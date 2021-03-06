
#define ELPP_THREAD_SAFE
#define ELPP_NO_DEFAULT_LOG_FILE

#include "fcdservice.h"
#include <httpServer/src/external/pbjson.hpp>
#include <iostream>
#include <string>
#include <common/utility/Utils.h>
#include <google/protobuf/text_format.h>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include <cmath>
#include <common/asn1/per_encoder.h>

using namespace std;

INITIALIZE_EASYLOGGINGPP


FcdService::FcdService(FcdServiceConfig &config, string globalConfig, string logConf, string statConf) {
    try {
        mGlobalConfig.loadConfigXML(globalConfig);
    }
    catch (std::exception &e) {
        cerr << "Error while loading config.xml: " << e.what() << endl;
    }

    mConfig = config;
    myId = mGlobalConfig.mStationID;
    mRelayNode = false;
    mReplied = false;
    mExpNum = mGlobalConfig.mExpNo;
    mRequests = mConfig.mNrOfRequests;

    // Logging
    mMsgUtils = new MessageUtils("FcdService", mGlobalConfig.mExpNo, logConf, statConf);
    mLogger = new LoggingUtility("FcdService", mGlobalConfig.mExpNo, logConf, statConf);
    
    // Sender and Receiver
    std::string moduleName = "FcdService";
    mReceiverFromDcc = new CommunicationReceiver(moduleName, "5555", "FCD", mGlobalConfig.mExpNo, logConf, statConf);
    mSenderToDcc     = new CommunicationSender(moduleName, "2323", mGlobalConfig.mExpNo, logConf, statConf);
    mReceiverGps = new CommunicationReceiver(moduleName, "3333", "GPS", mGlobalConfig.mExpNo, logConf, statConf);
	mReceiverObd2 = new CommunicationReceiver(moduleName, "2222", "OBD2", mGlobalConfig.mExpNo, logConf, statConf);
    mClientCam = new CommunicationClient(moduleName, "6789", mGlobalConfig.mExpNo, logConf, statConf);
    mClientCamInfo = new CommunicationClient(moduleName, "6789", mGlobalConfig.mExpNo, logConf, statConf);

    // Start the threads
    if (mConfig.mIsRSU){
        mThreadSender   = new boost::thread(&FcdService::sendLoop, this);
    }
    mThreadReceiver = new boost::thread(&FcdService::receive, this);
    mThreadGpsDataReceive = new boost::thread(&FcdService::receiveGpsData, this);
	mThreadObd2DataReceive = new boost::thread(&FcdService::receiveObd2Data, this);

    srand (time(NULL));

    if (mConfig.mIsBaseline){
        mLogger->logInfo("Running BASELINE algorithm... ");
    }
    else{
        mLogger->logInfo("Running DISCOVER algorithm...");
    }

    initializeResultFiles();
}


FcdService::~FcdService() {
    if (mConfig.mIsRSU){
        mThreadSender->join();
    }
    mThreadReceiver->join();
    mThreadGpsDataReceive->join();
	mThreadObd2DataReceive->join();
    //mIoServiceThread->join();

    delete mThreadSender;
    delete mThreadReceiver;
    delete mThreadGpsDataReceive;
	delete mThreadObd2DataReceive;
    //delete mIoServiceThread;

    delete mReceiverFromDcc;
    delete mSenderToDcc;
    delete mReceiverGps;
	delete mReceiverObd2;
    delete mClientCam;
    delete mClientCamInfo;

    delete mLogger;
    delete mMsgUtils;

    //mTimer->cancel();
	//delete mTimer;
    reqMap.clear();
    mLocalFcdSet.clear();
    mSentReplies.clear();
}


void FcdService::sendLoop() {
    int counter = 0;

    // Loop that sends every t seconds an FCD message
    while(counter <= mRequests) {
        string serializedData;
        dataPackage::DATA data;

        FCDREQ_t* fcdReq = generateFcd(counter);
        vector<uint8_t> encodedFcd = mMsgUtils->encodeMessage(&asn_DEF_FCDREQ, fcdReq);
        string strFcd(encodedFcd.begin(), encodedFcd.end());
	    mLogger->logDebug("Encoded FCDRequest size: " + to_string(strFcd.length()));
        
        data.set_id(messageID_request);
        data.set_type(dataPackage::DATA_Type_FCD);
        data.set_priority(dataPackage::DATA_Priority_VI);

        int64_t currTime = Utils::currentTime();
        data.set_createtime(currTime);
        data.set_validuntil(currTime + 2*1000*1000*1000);
        data.set_content(strFcd);

        data.SerializeToString(&serializedData);

        // Send message
        mSenderToDcc->send("FCD", serializedData);

        mCollectionStartTime = Utils::currentTime();

        //cout << "Sending FCD out with ReqID: " << to_string(fcdReq->fcdBasicHeader.requestID) << endl;
        cout << " " << endl;
        mLogger->logInfo("Sending Request " + to_string(fcdReq->fcdBasicHeader.requestID));

        updateCopy(fcdReq);

        saveRequestToFile(fcdReq);

        mLocalFcdSet.clear();

        // Wait for txInterval seconds
        boost::this_thread::sleep(boost::posix_time::seconds(mConfig.mTxInterval));
        
        counter++;
    }
}


void FcdService::receive() {
	string envelope;		//envelope
	string serializedAsnFcd;	//byte string (serialized)

    while (1) {
        pair<string, string> received = mReceiverFromDcc->receive();
        envelope = received.first;
        serializedAsnFcd = received.second;

        FCDREQ_t* fcd = 0;
		int res = mMsgUtils->decodeMessage(&asn_DEF_FCDREQ, (void **)&fcd, serializedAsnFcd);
		if (res != 0) {
			mLogger->logError("Failed to decode received FCDRequest. Error code: " + to_string(res));
			continue;
		}
        
        if (fcd->messageID == messageID_request){
            //cout << "Received Request " << to_string(fcdReq->fcdBasicHeader.requestID) << endl;
            cout << " " << endl;
            mLogger->logInfo("Received Request " + to_string(fcd->fcdBasicHeader.requestID) + " from sender " + to_string(fcd->fcdBasicHeader.stationID));
            handleRequest(fcd);
        }
        else if(fcd->messageID == messageID_reply){
            mLogger->logInfo("Received Reply " + to_string(fcd->fcdBasicHeader.requestID) + " from sender " + to_string(fcd->fcdBasicHeader.stationID) +
                " originated by " + to_string(fcd->fcdBasicHeader.originatorID));
            if (mRelayNode || mConfig.mIsRSU){
                handleReply(fcd);
            }
        }
        else{
            mLogger->logError("Received unknown FCD message.");
        }
    }
}


void FcdService::receiveGpsData() {
	string serializedGps;
	gpsPackage::GPS newGps;

	while (1) {
		serializedGps = mReceiverGps->receiveData();
		newGps.ParseFromString(serializedGps);
		mLogger->logDebug("Received GPS with latitude: " + to_string(newGps.latitude()) + ", longitude: " + to_string(newGps.longitude()));
		mMutexLatestGps.lock();
		mLatestGps = newGps;
		mMutexLatestGps.unlock();
	}
}


void FcdService::receiveObd2Data() {
	string serializedObd2;
	obd2Package::OBD2 newObd2;

	while (1) {
		serializedObd2 = mReceiverObd2->receiveData();
		newObd2.ParseFromString(serializedObd2);
		mLogger->logDebug("Received OBD2 with speed (m/s): " + to_string(newObd2.speed()));
		mMutexLatestObd2.lock();
		mLatestObd2 = newObd2;
		mMutexLatestObd2.unlock();
	}
}


FCDREQ_t* FcdService::generateFcd(int reqId) {
    mLogger->logDebug("Generating FCDRequest");
	FCDREQ_t* fcdReq = static_cast<FCDREQ_t*>(calloc(1, sizeof(FCDREQ_t)));
	if (!fcdReq) {
		throw runtime_error("could not allocate FCDREQ_t");
	}

                    /*double mLat = 0;
                    double mLong = 0;
                    if (myId == 11111){
                        mLat = 49.5034160;
                        mLong = 5.9450593;
                    }
                    else if (myId == 22222){
                        mLat = 49.5054160;
                        mLong = 5.9450593;
                    }
                    else if (myId == 33333){
                        mLat = 49.5024160;
                        mLong = 5.9450593;
                    }
                    else if (myId == 44444){
                        mLat = 49.5064160;
                        mLong = 5.9450593;
                    }
                    else if (myId == 55555){
                        mLat = 49.5074160;
                        mLong = 5.9450593;
                    }*/

    int64_t currTime = Utils::currentTime();
    // Seems like ASN1 supports 32 bit int (strange) and timestamp needs 42 bits.
	TimestampIts_t* timestamp = static_cast<TimestampIts_t*>(calloc(1, sizeof(TimestampIts_t)));
	timestamp->buf = static_cast<uint8_t*>(calloc(6, 1)); // timestamp needs 42 bits in standard
	timestamp->bits_unused = 6;
	timestamp->size = 6;
	memcpy(timestamp->buf, &currTime, 6);

    fcdReq->messageID = messageID_request;

    // FCD basic header
    fcdReq->fcdBasicHeader.protocolVersion = protocolVersion_currentVersion;
    fcdReq->fcdBasicHeader.requestID = reqId;
    fcdReq->fcdBasicHeader.reserved = 0; //TODO: check this value
    fcdReq->fcdBasicHeader.stationID = myId;

    // FCD request header
    fcdReq->fcdRequestHeader.dMax = mConfig.mMaxDistance;
    fcdReq->fcdRequestHeader.hCur = 0; //dynamic, will be increased at every hop
    fcdReq->fcdRequestHeader.hMax = mConfig.mMaxHops;
    mMutexLatestGps.lock();
	if(mLatestGps.has_time()) {	//only add gps if valid data is available
		fcdReq->fcdRequestHeader.latitude = mLatestGps.latitude() * 10000000; // in one-tenth of microdegrees
		fcdReq->fcdRequestHeader.longitude = mLatestGps.longitude() * 10000000; // in one-tenth of microdegrees
		fcdReq->fcdRequestHeader.altitude.altitudeValue = mLatestGps.altitude();
	} else {
        fcdReq->fcdRequestHeader.latitude = Latitude_unavailable;
        fcdReq->fcdRequestHeader.longitude = Longitude_unavailable;
        fcdReq->fcdRequestHeader.altitude.altitudeValue = AltitudeValue_unavailable;
        //fcdReq->fcdRequestHeader.latitude = mLat * 10000000;
        //fcdReq->fcdRequestHeader.longitude = mLong * 10000000;
	}
	mMutexLatestGps.unlock();
    fcdReq->fcdRequestHeader.tMaxRep = mConfig.mMaxReplyTimer; // in milliseconds
    fcdReq->fcdRequestHeader.tMaxReq = mConfig.mMaxRequestTimer; // in milliseconds
    fcdReq->fcdRequestHeader.generationTime = *timestamp;
    return fcdReq;
}


void FcdService::handleRequest(FCDREQ_t* fcd){
    //temp hack: these coordinates are hardcoded for testing purposes... to be removed
    /*double mLat = 0;
    double mLong = 0;
    if (myId == 11111){
        mLat = 49.5034160;
        mLong = 5.9450593;
    }
    else if (myId == 22222){
        mLat = 49.5054160;
        mLong = 5.9450593;
    }
    else if (myId == 33333){
        mLat = 49.5024160;
        mLong = 5.9450593;
    }
    else if (myId == 44444){
        mLat = 49.5064160;
        mLong = 5.9450593;
    }
    else if (myId == 55555){
        mLat = 49.5074160;
        mLong = 5.9450593;
    }*/

    double rcvdLat = fcd->fcdRequestHeader.latitude/(double)10000000;
    double rcvdLong = fcd->fcdRequestHeader.longitude/(double)10000000;

    //mLogger->logInfo("My Lat: " + to_string(mLatestGps.latitude()) + " | My Long: " + to_string(mLatestGps.longitude()));
    //mLogger->logInfo("Rec Lat: " + to_string(rcvdLat) + " | Rec Long: " + to_string(rcvdLong));
    double mDist = getDistance(mLatestGps.latitude(),mLatestGps.longitude(),rcvdLat,rcvdLong);
    //double mDist = getDistance(mLat,mLong,rcvdLat,rcvdLong);
    mLogger->logInfo("Distance from sender: " + to_string(mDist));

    if (mDist < fcd->fcdRequestHeader.dMax){
        mLogger->logInfo("Less then Dmax. OK!");

        updateCopy(fcd);

        if (getNumberOfCopies(fcd->fcdBasicHeader.requestID) == 1){
            mLogger->logInfo("This is the first copy.");
            mRelayNode = false;
            mReplied = false;
            mLocalFcdSet.clear();
            mSentReplies.clear();
            mCurHopCount = fcd->fcdRequestHeader.hCur + 1;

            if (mCurHopCount <= fcd->fcdRequestHeader.hMax){
                //schedule self-timer
                int64_t request_timer = fcd->fcdRequestHeader.tMaxReq * (0.8*(1 - (mDist / (double)fcd->fcdRequestHeader.dMax)) + 0.2*getRandomNumber());
                mLogger->logInfo("Request Timer = " + to_string(request_timer) + "ms");

                int tempId = fcd->fcdBasicHeader.requestID;
                auto call_request = boost::bind(FcdService::callback_request,this,tempId);

                Timer* tRequest = new Timer(call_request,boost::chrono::milliseconds(request_timer),true);
                tRequest->start(true);

                if (mConfig.mIsBaseline){
                    int64_t reply_timer = 0.1*getRandomNumber();
                    mLogger->logInfo("Reply Timer = " + to_string(reply_timer) + "ms");

                    auto call_reply = boost::bind(FcdService::callback_reply,this,tempId);
                    Timer* tReply = new Timer(call_reply,boost::chrono::milliseconds(reply_timer),true);
                    tReply->start(true);
                }
            }
            else{
                mLogger->logInfo("Max hop reached. Ignore this message.");
            }
        }
        else{
            mLogger->logInfo("Not the first copy.");
            saveRequestCopyToFile(fcd);
        }
    }
    else{
        mLogger->logInfo("Bigger then Dmax. Do nothing.");
    }
}


void FcdService::handleReply(FCDREQ_t* fcd){
    stringstream s;
    s << fcd->payload.buf;
    mLogger->logInfo(s.str());

    if (mConfig.mIsBaseline){
        saveInFcdSet(s.str());
        std::string mergedPayload = createPayload();
        cout << "Merged FCDs: " << mergedPayload << endl;
        saveRepliesToFile(fcd, mergedPayload);
        if (mRelayNode){
            if (mCurHopCount < fcd->fcdRequestHeader.hCur){
                set<int>::iterator it = mSentReplies.find(fcd->fcdBasicHeader.originatorID);
                if (it == mSentReplies.end()){
                    //first time sending this Reply
                    fcd->fcdBasicHeader.stationID = myId;

                    string serializedData;
                    dataPackage::DATA data;
                    vector<uint8_t> encodedFcd = mMsgUtils->encodeMessage(&asn_DEF_FCDREQ, fcd);
                    string strFcd(encodedFcd.begin(), encodedFcd.end());

                    int64_t currTime = Utils::currentTime();
                    TimestampIts_t* timestamp = static_cast<TimestampIts_t*>(calloc(1, sizeof(TimestampIts_t)));
                    timestamp->buf = static_cast<uint8_t*>(calloc(6, 1)); // timestamp needs 42 bits in standard
                    timestamp->bits_unused = 6;
                    timestamp->size = 6;
                    memcpy(timestamp->buf, &currTime, 6);                

                    data.set_id(messageID_request);
                    data.set_type(dataPackage::DATA_Type_FCD);
                    data.set_priority(dataPackage::DATA_Priority_VI);
                    data.set_createtime(currTime);
                    data.set_validuntil(currTime + 2*1000*1000*1000);
                    data.set_content(strFcd);

                    data.SerializeToString(&serializedData);

                    // Send message
                    mSenderToDcc->send("FCD", serializedData);

                    mLogger->logInfo("Forwarding Reply " + to_string(fcd->fcdBasicHeader.requestID) + " from sender " + to_string(fcd->fcdBasicHeader.stationID) +
                        " originated by " + to_string(fcd->fcdBasicHeader.originatorID));

                    mSentReplies.insert(fcd->fcdBasicHeader.originatorID);
                }
                else{
                    mLogger->logInfo("Reply generated by " + to_string(*it) + " already sent. Ignore.");
                }
            }
            else{
                mLogger->logInfo("Current hop count " + to_string(mCurHopCount) + " is greater or equal then the received hop count "
                 + to_string(fcd->fcdRequestHeader.hCur) + ". Ignore.");
            }
        }
    }
    else{
        if (!mReplied){
            saveInFcdSet(s.str());
            std::string mergedPayload = createPayload();
            cout << "Merged FCDs: " << mergedPayload << endl;
            saveRepliesToFile(fcd, mergedPayload);
        }
        else{
            mLogger->logInfo("Already replied: do nothing.");
        }
    }
}


double FcdService::getDistance(double lat1, double lon1, double lat2, double lon2) {
	double R = 6371; // km
	double dLat = (lat2-lat1) * M_PI/180.0;		//convert to rad
	double dLon = (lon2-lon1) * M_PI/180.0;
	lat1 = lat1 * M_PI/180.0;
	lat2 = lat2 * M_PI/180.0;

	double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	return R * c * 1000;						//convert to m
}


void FcdService::updateCopy(FCDREQ_t* fcd){
    //cout << ">>>>> Updating copies for request " << fcd->fcdBasicHeader.requestID << endl;
    FcdMsgInfo_table::iterator it = reqMap.find(fcd->fcdBasicHeader.requestID);
    if (it == reqMap.end()){   //first time receiving this message
        FCDRequestInfo info (fcd);
        reqMap.insert(make_pair(fcd->fcdBasicHeader.requestID, info));
    }
    else{
        it->second.updateCopy();
        if (fcd->fcdRequestHeader.hCur > getCurrentHopCount(fcd->fcdBasicHeader.requestID)){
            it->second.inhibit();
        }
        else{
            mLogger->logInfo("Spurious forwarder: do not inhibit.");
        }
    }
}


int FcdService::getNumberOfCopies(int msgId){
    int result = 0;
    FcdMsgInfo_table::iterator it = reqMap.find(msgId);
    if (it != reqMap.end()){   // it's the first time we receive this message
        result = it->second.getCopies();
    }
    else{
        throw runtime_error("Error: message id not found!");
    }
    return result;
}


int FcdService::getCurrentHopCount(int msgId){
    int result = 0;
    FcdMsgInfo_table::iterator it = reqMap.find(msgId);
    if (it != reqMap.end()){
        result = it->second.getReqMsg()->fcdRequestHeader.hCur;
    }
    else{
        throw runtime_error("Error: the Request message is not in my local table.");
    }
    return result;
}


bool FcdService::isInhibited(int msgId){
    int result = 0;
    FcdMsgInfo_table::iterator it = reqMap.find(msgId);
    if (it != reqMap.end()){
        result = it->second.isInhibited();
    }
    else{
        throw runtime_error("Error: message id not found!");
    }

    return result;
}


//requests all CAMs from LDM
std::string FcdService::requestCam(std::string condition) {
	mMutexCam.lock();
	std::string request, reply;
	std::string serializedData;
	dataPackage::LdmData ldmData;
	//get all CAMs from LDM
	reply = mClientCam->sendRequest("CAM", condition, mConfig.mTimeout);
	if (reply != "") {
		ldmData.ParseFromString(reply);

		//convert to JSON
		std::string json = "{\"type\":\"CAM\",\"number\":" + std::to_string(ldmData.data_size()) + ",\"msgs\":[";
		for (int i=0; i<ldmData.data_size(); i++) {
			std::string tempJson;
			std::string serializedCam = ldmData.data(i);
			camPackage::CAM cam;
			cam.ParseFromString(serializedCam);
			pbjson::pb2json(&cam, tempJson);
			if (i > 0) {
				json += "," + tempJson;
			}
			else {
				json += tempJson;
			}
		}
		json += "]}";
		mMutexCam.unlock();
		return json;
	}
	mMutexCam.unlock();
	return "";
}


//requests all CAMINFOs from LDM
std::string FcdService::requestCamInfo(std::string condition) {
	mMutexCamInfo.lock();
	std::string request, reply;
	std::string serializedData;
	dataPackage::LdmData ldmData;
	//get all camInfos from LDM
	reply = mClientCamInfo->sendRequest("camInfo", condition, mConfig.mTimeout);
	if (reply != "") {
		ldmData.ParseFromString(reply);

		//convert to JSON
		std::string json = "{\"type\":\"camInfo\",\"number\":" + std::to_string(ldmData.data_size()) + ",\"msgs\":[";

		for (int i=0; i<ldmData.data_size(); i++) {
			std::string tempJson;
			std::string serializedCamInfo = ldmData.data(i);
			infoPackage::CamInfo camInfo;
			camInfo.ParseFromString(serializedCamInfo);
			pbjson::pb2json(&camInfo, tempJson);
			if (i > 0) {
				json += "," + tempJson;
			}
			else {
				json += tempJson;
			}
		}
		json += "]}";
		mMutexCamInfo.unlock();
		return json;
	}
	mMutexCamInfo.unlock();
	return "";
}


std::string FcdService::createPayload(){
    //Create a new DOM to store the extracted information
    rapidjson::Document newDoc;
    newDoc.SetObject();
    rapidjson::Document::AllocatorType& allocator = newDoc.GetAllocator();
    rapidjson::Value msgs(rapidjson::kArrayType);

    newDoc.AddMember("type", "Payload", allocator);
    newDoc.AddMember("number", mLocalFcdSet.size(), allocator);
    FCDInfoSet::iterator it;
    for (it=mLocalFcdSet.begin(); it!=mLocalFcdSet.end(); it++){
        rapidjson::Value obj(rapidjson::kObjectType);
        obj.AddMember("stationID",  it->second.getVehicleId(), allocator);
        obj.AddMember("latitude",  it->second.getLatitude(), allocator);
        obj.AddMember("longitude",  it->second.getLongitude(), allocator);
        msgs.PushBack(obj, allocator);
    }
    newDoc.AddMember("msgs", msgs, allocator);

    //Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    newDoc.Accept(writer);

    return buffer.GetString();
}


std::string FcdService::createBaselinePayload(){
    rapidjson::Document newDoc;
    newDoc.SetObject();
    rapidjson::Document::AllocatorType& allocator = newDoc.GetAllocator();
    rapidjson::Value msgs(rapidjson::kArrayType);

    newDoc.AddMember("type", "Payload", allocator);
    newDoc.AddMember("number", 1, allocator);
    FCDInfoSet::iterator it;
    for (it=mLocalFcdSet.begin(); it!=mLocalFcdSet.end(); it++){
        if (it->first == myId){
            rapidjson::Value obj(rapidjson::kObjectType);
            obj.AddMember("stationID",  it->second.getVehicleId(), allocator);
            obj.AddMember("latitude",  it->second.getLatitude(), allocator);
            obj.AddMember("longitude",  it->second.getLongitude(), allocator);
            msgs.PushBack(obj, allocator);
            break;
        }
    }
    newDoc.AddMember("msgs", msgs, allocator);

    //Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    newDoc.Accept(writer);

    return buffer.GetString();    
}


void FcdService::saveInFcdSet(std::string payload){
    const char* myJson = payload.c_str();
    rapidjson::Document doc;
    doc.Parse(myJson);
    const rapidjson::Value& vec = doc["msgs"];
    string type = doc["type"].GetString();

    if (mLocalFcdSet.empty()){ //empty list: simply insert the elements
        if (type=="CAM"){ //payload coming from LDM
            for (rapidjson::Value::ConstValueIterator itr = vec.Begin(); itr != vec.End(); ++itr){
                FCDInfo newElem((*itr)["header"]["stationID"].GetInt(), (*itr)["coop"]["camParameters"]["basicContainer"]["latitude"].GetInt64(),
                    (*itr)["coop"]["camParameters"]["basicContainer"]["longitude"].GetInt64());
                mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>((*itr)["header"]["stationID"].GetInt(),newElem));
            }
        }
        else{ //payload coming from received Reply
            for (rapidjson::Value::ConstValueIterator itr = vec.Begin(); itr != vec.End(); ++itr){
                FCDInfo newElem((*itr)["stationID"].GetInt(), (*itr)["latitude"].GetInt64(), (*itr)["longitude"].GetInt64());
                mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>((*itr)["stationID"].GetInt(),newElem));
            }
        }
    }
    else{ //merge the new elements with the existing ones
        if (type=="CAM"){ //payload coming from LDM
            for (rapidjson::Value::ConstValueIterator itr = vec.Begin(); itr != vec.End(); ++itr){
                uint64_t tempId = (*itr)["header"]["stationID"].GetInt();
                FCDInfoSet::iterator iter = mLocalFcdSet.find(tempId);
                if (iter != mLocalFcdSet.end()){ //element already in list
                    mLocalFcdSet.erase(iter);
                    FCDInfo newElem(tempId, (*itr)["coop"]["camParameters"]["basicContainer"]["latitude"].GetInt64(),
                        (*itr)["coop"]["camParameters"]["basicContainer"]["longitude"].GetInt64());
                    mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>(tempId,newElem));
                }
                else{
                    FCDInfo newElem(tempId, (*itr)["coop"]["camParameters"]["basicContainer"]["latitude"].GetInt64(),
                        (*itr)["coop"]["camParameters"]["basicContainer"]["longitude"].GetInt64());
                    mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>(tempId,newElem));
                }
            }
        }
        else{ //payload coming from received Reply
            for (rapidjson::Value::ConstValueIterator itr = vec.Begin(); itr != vec.End(); ++itr){
                uint64_t tempId = (*itr)["stationID"].GetInt();
                FCDInfoSet::iterator iter = mLocalFcdSet.find(tempId);
                if (iter != mLocalFcdSet.end()){ //element already in list
                    mLocalFcdSet.erase(iter);
                    FCDInfo newElem(tempId, (*itr)["latitude"].GetInt64(), (*itr)["longitude"].GetInt64());
                    mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>(tempId,newElem));
                }
                else{
                    FCDInfo newElem(tempId, (*itr)["latitude"].GetInt64(), (*itr)["longitude"].GetInt64());
                    mLocalFcdSet.insert(std::pair<uint64_t,FCDInfo>(tempId,newElem));
                }
            }
        }
    }
}


void FcdService::initializeResultFiles(){
    saveConfigurationToFile();

    std::string reqFileName = "exp"+to_string(mExpNum)+"-"+to_string(myId)+"-requests.dat";
    if (fexists(reqFileName)){
        if (remove(reqFileName.c_str()) != 0)
            mLogger->logInfo( "Error deleting file " + reqFileName);
        else
            mLogger->logInfo( "File " + reqFileName +" successfully deleted" );
    }
    std::ofstream req_output;
    req_output.open (reqFileName, std::ofstream::out | std::ofstream::app);
    req_output << "ExpID   MyID   SenderID   RequestID   Longitude   Latitude   HopNumber   CurrentTime   GenerationTime   RelayNode\n";
    req_output.close();

    std::string repFileName = "exp"+to_string(mExpNum)+"-"+to_string(myId)+"-replies.dat";
    if (fexists(repFileName)){
        if (remove(repFileName.c_str()) != 0)
            mLogger->logInfo( "Error deleting file " + repFileName);
        else
            mLogger->logInfo( "File " + repFileName +" successfully deleted" );
    }
    std::ofstream rep_output;
    rep_output.open (repFileName, std::ofstream::out | std::ofstream::app);
    rep_output << "ExpID   MyID   SenderID   RequestID   CollectionDelay   RcvdFCD   MergedFCDs\n";
    rep_output.close();

    std::string reqCopyFileName = "exp"+to_string(mExpNum)+"-"+to_string(myId)+"-reqcopies.dat";
    if (fexists(reqCopyFileName)){
        if (remove(reqCopyFileName.c_str()) != 0)
            mLogger->logInfo( "Error deleting file " + reqCopyFileName);
        else
            mLogger->logInfo( "File " + reqCopyFileName +" successfully deleted" );
    }
    std::ofstream reqcopy_output;
    reqcopy_output.open (reqCopyFileName, std::ofstream::out | std::ofstream::app);
    reqcopy_output << "ExpID   MyID   SenderID   RequestID   Longitude   Latitude   HopNumber   CurrentTime   GenerationTime   RelayNode\n";
    reqcopy_output.close();
}


void FcdService::saveRequestToFile(FCDREQ_t* request){
    mLogger->logInfo("Saving the received REQUEST to file.");
    std::ofstream output;
    output.open ("exp"+to_string(mExpNum)+"-"+to_string(myId)+"-requests.dat", std::ofstream::out | std::ofstream::app);
    int64_t curr_time = Utils::currentTime();
    int64_t gen_time;
    memcpy(&gen_time, request->fcdRequestHeader.generationTime.buf, 6);
    output << to_string(mExpNum) + "   " + to_string(myId) + "   " + to_string(request->fcdBasicHeader.stationID) + 
        "   " + to_string(request->fcdBasicHeader.requestID) + "   " + to_string(request->fcdRequestHeader.longitude) + 
        "   " + to_string(request->fcdRequestHeader.latitude) + "   " + to_string(request->fcdRequestHeader.hCur) + "   " + to_string(curr_time) +
        "   " + to_string(gen_time) + "   " + to_string(!isInhibited(request->fcdBasicHeader.requestID)) + "\n";
    output.close();
}


void FcdService::saveRequestCopyToFile(FCDREQ_t* request){
    mLogger->logInfo("Saving the received REQUEST Copy to file.");
    std::ofstream output;
    output.open ("exp"+to_string(mExpNum)+"-"+to_string(myId)+"-reqcopies.dat", std::ofstream::out | std::ofstream::app);
    int64_t curr_time = Utils::currentTime();
    int64_t gen_time;
    memcpy(&gen_time, request->fcdRequestHeader.generationTime.buf, 6);
    output << to_string(mExpNum) + "   " + to_string(myId) + "   " + to_string(request->fcdBasicHeader.stationID) + 
        "   " + to_string(request->fcdBasicHeader.requestID) + "   " + to_string(request->fcdRequestHeader.longitude) + 
        "   " + to_string(request->fcdRequestHeader.latitude) + "   " + to_string(request->fcdRequestHeader.hCur) + "   " + to_string(curr_time) +
        "   " + to_string(gen_time) + "   " + to_string(!isInhibited(request->fcdBasicHeader.requestID)) + "\n";
    output.close();
}


/*void FcdService::saveReplyToFile(FCDREQ_t* reply){
    mLogger->logInfo("Saving the received REPLY to file.");
    std::stringstream s;
    s << reply->payload.buf;
    std::ofstream output;
    output.open ("exp"+to_string(mExpNum)+"-"+to_string(myId)+"-replies.dat", std::ofstream::out | std::ofstream::app);
    int64_t collection_delay = Utils::currentTime() - mCollectionStartTime; //nanoseconds
    output << to_string(mExpNum) + "   " + to_string(myId) + "   " + to_string(reply->fcdBasicHeader.stationID) +
        "   " + to_string(reply->fcdBasicHeader.requestID) + "   " + to_string(collection_delay) + "   " + s.str() + "\n";
    output.close();
}*/


void FcdService::saveRepliesToFile(FCDREQ_t* reply, std::string mergedPayload){
    mLogger->logInfo("Saving the received REPLY to file.");
    std::stringstream s;
    s << reply->payload.buf;
    std::ofstream output;
    output.open ("exp"+to_string(mExpNum)+"-"+to_string(myId)+"-replies.dat", std::ofstream::out | std::ofstream::app);
    int64_t collection_delay = Utils::currentTime() - mCollectionStartTime; //nanoseconds
    output << to_string(mExpNum) + "   " + to_string(myId) + "   " + to_string(reply->fcdBasicHeader.stationID) +
        "   " + to_string(reply->fcdBasicHeader.requestID) + "   " + to_string(collection_delay) + "   " + s.str() + "   " + mergedPayload + "\n";
    output.close();
}


void FcdService::saveConfigurationToFile(){
    mLogger->logInfo("Saving the CONFIGURATION to file.");
    std::string fileName = "exp"+to_string(mExpNum)+"-"+to_string(myId)+"-config.dat";
    if (fexists(fileName)){
        if (remove(fileName.c_str()) != 0)
            mLogger->logInfo( "Error deleting file " + fileName);
        else
            mLogger->logInfo( "File " + fileName +" successfully deleted" );
    }
    std::ofstream output;
    output.open (fileName, std::ofstream::out | std::ofstream::app);
    output << "ExpID   MyID   TxInterval   MaxDistance   MaxHops   MaxReqTimer   MaxRepTimer   IsRSU\n";
    output << to_string(mExpNum) + "   " + to_string(mGlobalConfig.mStationID) + "   " + to_string(mConfig.mTxInterval) +
        "   " + to_string(mConfig.mMaxDistance) + "   " + to_string(mConfig.mMaxHops) + "   " + to_string(mConfig.mMaxRequestTimer) + 
        "   " + to_string(mConfig.mMaxReplyTimer) + "   " + to_string(mConfig.mIsRSU) + "\n";
}


double FcdService::getRandomNumber(){
    //return rand() / double(RAND_MAX);
    double result = rand() / double(RAND_MAX);
    mLogger->logInfo( "Generated random number " + to_string(result));
    return result;
}


void FcdService::callback_request(FcdService* self, int tempId){
    /*double mLat = 0;
    double mLong = 0;
    if (self->myId == 11111){
        mLat = 49.5034160;
        mLong = 5.9450593;
    }
    else if (self->myId == 22222){
        mLat = 49.5054160;
        mLong = 5.9450593;
    }
    else if (self->myId == 33333){
        mLat = 49.5024160;
        mLong = 5.9450593;
    }
    else if (self->myId == 44444){
        mLat = 49.5064160;
        mLong = 5.9450593;
    }
    else if (self->myId == 55555){
        mLat = 49.5074160;
        mLong = 5.9450593;
    }*/

    FcdMsgInfo_table::iterator it = self->reqMap.find(tempId);
    if (it != self->reqMap.end()){
        //if (it->second.getCopies() == 1){
        self->saveRequestToFile(it->second.getReqMsg());
        if (!self->isInhibited(tempId)){
            self->mLogger->logInfo("REQUEST timer expired.");
            self->mRelayNode = true;

            int64_t currTime = Utils::currentTime();
            TimestampIts_t* timestamp = static_cast<TimestampIts_t*>(calloc(1, sizeof(TimestampIts_t)));
            timestamp->buf = static_cast<uint8_t*>(calloc(6, 1)); // timestamp needs 42 bits in standard
            timestamp->bits_unused = 6;
            timestamp->size = 6;
            memcpy(timestamp->buf, &currTime, 6);
                            
            FCDREQ_t* toForward = it->second.getReqMsg();
            toForward->fcdRequestHeader.generationTime = *timestamp;
            toForward->fcdBasicHeader.stationID = self->myId;
            self->mMutexLatestGps.lock();
            if(self->mLatestGps.has_time()) {	//only add gps if valid data is available
                toForward->fcdRequestHeader.latitude = self->mLatestGps.latitude() * 10000000; // in one-tenth of microdegrees
                toForward->fcdRequestHeader.longitude = self->mLatestGps.longitude() * 10000000; // in one-tenth of microdegrees
                toForward->fcdRequestHeader.altitude.altitudeValue = self->mLatestGps.altitude();
            } else {
                toForward->fcdRequestHeader.latitude = Latitude_unavailable;
                toForward->fcdRequestHeader.longitude = Longitude_unavailable;
                toForward->fcdRequestHeader.altitude.altitudeValue = AltitudeValue_unavailable;
                //toForward->fcdRequestHeader.latitude = mLat * 10000000;
                //toForward->fcdRequestHeader.longitude = mLong * 10000000;
            }
            self->mMutexLatestGps.unlock();
            toForward->fcdRequestHeader.hCur = self->mCurHopCount;

            //std::cout << ">>> Update current hop to " << to_string(toForward->fcdRequestHeader.hCur) << std::endl;
            //std::cout << ">>> Update Lat to " << to_string(toForward->fcdRequestHeader.latitude) << std::endl;
            //std::cout << ">>> Update Long to " << to_string(toForward->fcdRequestHeader.longitude) << std::endl;

            string serializedData;
            dataPackage::DATA data;
            vector<uint8_t> encodedFcd = self->mMsgUtils->encodeMessage(&asn_DEF_FCDREQ, toForward);
            string strFcd(encodedFcd.begin(), encodedFcd.end());
                            
            data.set_id(messageID_request);
            data.set_type(dataPackage::DATA_Type_FCD);
            data.set_priority(dataPackage::DATA_Priority_VI);
            data.set_createtime(currTime);
            data.set_validuntil(currTime + 2*1000*1000*1000);
            data.set_content(strFcd);

            data.SerializeToString(&serializedData);

            // Send message
            self->mSenderToDcc->send("FCD", serializedData);

            self->mLogger->logInfo("Forwarding Request " + to_string(toForward->fcdBasicHeader.requestID));

            if (!self->mConfig.mIsBaseline){
                auto call_reply = boost::bind(FcdService::callback_reply,self,tempId);
                //TODO: add a random factor to avoid synchronized transmissions
                int64_t reply_timer = toForward->fcdRequestHeader.tMaxRep * (1 - (self->mCurHopCount / (double)toForward->fcdRequestHeader.hMax)) +
                                            toForward->fcdRequestHeader.tMaxReq * (toForward->fcdRequestHeader.hMax - self->mCurHopCount);
                self->mLogger->logInfo("Reply Timer = " + to_string(reply_timer) + "ms");
                Timer* tReply = new Timer(call_reply,boost::chrono::milliseconds(reply_timer),true);
                tReply->start(true);
            }
        }
        else{
            self->mLogger->logInfo("Inhibited. Do nothing.");
        }
    }
    else{
        throw runtime_error("Error: timeout with no associated message");
    }
}


void FcdService::callback_reply(FcdService* self, int tempId){
    self->mLogger->logInfo("REPLY timer expired.");
    
    //get CAMs from LDM
    string condition = "latest";
    string existing_cams = self->requestCam(condition);

    //save CAMs into the local FCD set
    self->saveInFcdSet(existing_cams);

    //HACK: filter the extracted information to fit the MTU
    //TODO: split the data in multiple frames
    string myPayload = "";
    if (self->mConfig.mIsBaseline){
        myPayload = self->createBaselinePayload();
    }
    else{
        myPayload = self->createPayload();
    }
    int payload_len = myPayload.size()+1;
    char fcd_from_ldm[payload_len];
    strcpy(fcd_from_ldm, myPayload.c_str());

    //create the payload
    Payload_t* payload = static_cast<Payload_t*>(calloc(1, sizeof(Payload_t)));
    payload->buf = static_cast<uint8_t*>(calloc(payload_len, 1));
    payload->size = payload_len;
    memcpy(payload->buf, fcd_from_ldm, payload_len);

    //create the FCDReply message
    FCDREQ_t* fcdRep = self->generateFcd(tempId);
    fcdRep->messageID = messageID_reply;
    fcdRep->fcdBasicHeader.originatorID = self->myId;
    fcdRep->fcdRequestHeader.hCur = self->mCurHopCount;
    fcdRep->payload = *payload;

    string serializedData;
    dataPackage::DATA data;
    vector<uint8_t> encodedFcd = self->mMsgUtils->encodeMessage(&asn_DEF_FCDREQ, fcdRep);
    string strFcd(encodedFcd.begin(), encodedFcd.end());

    int64_t currTime = Utils::currentTime();                        
    data.set_id(messageID_reply);
    data.set_type(dataPackage::DATA_Type_FCD);
    data.set_priority(dataPackage::DATA_Priority_VI);
    data.set_createtime(currTime);
    data.set_validuntil(currTime + 2*1000*1000*1000);
    data.set_content(strFcd);

    data.SerializeToString(&serializedData);

    // Send message
    self->mSenderToDcc->send("FCD", serializedData);

    self->mLogger->logInfo("Sending Reply " + to_string(fcdRep->fcdBasicHeader.requestID));
    self->mLogger->logInfo(myPayload);

    self->mReplied = true;
}


bool FcdService::fexists(const std::string& filename) {
  std::ifstream ifile(filename.c_str());
  return (bool)ifile;
}


int main(int argc, const char* argv[]) {

    if(argc != 5) {
        fprintf(stderr, "missing arguments: %s <globalConfig.xml> <fcdConfig.xml> <logging.conf> <statistics.conf> \n", argv[0]);
        exit(1);
    }

    FcdServiceConfig config;
	try {
		config.loadConfigXML(argv[2]);
	}
	catch (std::exception &e) {
		cerr << "Error while loading config.xml: " << e.what() << endl << flush;
		return EXIT_FAILURE;
	}

    FcdService fcd(config, argv[1], argv[3], argv[4]);
    
    return EXIT_SUCCESS;
}
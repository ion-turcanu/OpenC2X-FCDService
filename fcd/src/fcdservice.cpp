
#define ELPP_THREAD_SAFE
#define ELPP_NO_DEFAULT_LOG_FILE

#include "fcdservice.h"
#include <iostream>
#include <string>
#include <common/utility/Utils.h>
#include <google/protobuf/text_format.h>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include <cmath>
#include <common/asn1/per_encoder.h>

INITIALIZE_EASYLOGGINGPP

using namespace std;

FcdService::FcdService(FcdServiceConfig &config, string globalConfig, string logConf, string statConf) {
    try {
        mGlobalConfig.loadConfigXML(globalConfig);
    }
    catch (std::exception &e) {
        cerr << "Error while loading config.xml: " << e.what() << endl;
    }

    mConfig = config;

    // Logging
    mLogger = new LoggingUtility("FcdService", mGlobalConfig.mExpNo, logConf, statConf);
    
    // Sender and Receiver
    mReceiverFromDcc = new CommunicationReceiver("FcdService", "5555", "FCD", mGlobalConfig.mExpNo, logConf, statConf);
    mSenderToDcc     = new CommunicationSender("FcdService", "2323", mGlobalConfig.mExpNo, logConf, statConf);

    // Start the threads
    if (mConfig.mIsRSU){
        mThreadSender   = new boost::thread(&FcdService::sendLoop, this);
    }
    mThreadReceiver = new boost::thread(&FcdService::receive, this);
}

FcdService::~FcdService() {
    if (mConfig.mIsRSU){
        mThreadSender->join();
    }
    mThreadReceiver->join();

    delete mThreadSender;
    delete mThreadReceiver;

    delete mReceiverFromDcc;
    delete mSenderToDcc;

    delete mLogger;
}

void FcdService::sendLoop() {
    int counter = 0;

    // Endless loop that sends every second an FCD message
    while(1) {
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

        // Wait for txInterval seconds
        boost::this_thread::sleep(boost::posix_time::seconds(mConfig.mTxInterval));
        mLogger->logInfo("Sending FCD out: " + strFcd);
        
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

        FCDREQ_t* fcdReq = 0;
		int res = mMsgUtils->decodeMessage(&asn_DEF_FCDREQ, (void **)&fcdReq, serializedAsnFcd);
		if (res != 0) {
			mLogger->logError("Failed to decode received FCDRequest. Error code: " + to_string(res));
			continue;
		}
        
        mLogger->logInfo("Incoming FCD: " + serializedAsnFcd);
    }
}

FCDREQ_t* FcdService::generateFcd(int reqId) {
    mLogger->logDebug("Generating FCDRequest");
	FCDREQ_t* fcdReq = static_cast<FCDREQ_t*>(calloc(1, sizeof(FCDREQ_t)));
	if (!fcdReq) {
		throw runtime_error("could not allocate CAM_t");
	}

    int64_t currTime = Utils::currentTime();
    // Seems like ASN1 supports 32 bit int (strange) and timestamp needs 42 bits.
	TimestampIts_t* timestamp = static_cast<TimestampIts_t*>(calloc(1, sizeof(TimestampIts_t)));
	timestamp->buf = static_cast<uint8_t*>(calloc(6, 1)); // timestamp needs 42 bits in standard
	timestamp->bits_unused = 6;
	timestamp->size = 6;
	memcpy(timestamp->buf, &currTime, 6);

    // FCD basic header
    fcdReq->fcdBasicHeader.messageID = messageID_request;
    fcdReq->fcdBasicHeader.protocolVersion = protocolVersion_currentVersion;
    fcdReq->fcdBasicHeader.requestID = reqId;
    fcdReq->fcdBasicHeader.reserved = 0; //TODO: check this value
    fcdReq->fcdBasicHeader.stationID = mGlobalConfig.mStationID;

    // FCD request header
    fcdReq->fcdRequestHeader.dMax = 200;
    fcdReq->fcdRequestHeader.hCur = 0;
    fcdReq->fcdRequestHeader.hMax = 4;
    fcdReq->fcdRequestHeader.latitude = 180;
    fcdReq->fcdRequestHeader.longitude = 90;
    fcdReq->fcdRequestHeader.tMaxRep = 1000; // in milliseconds
    fcdReq->fcdRequestHeader.tMaxReq = 100; // in milliseconds
    fcdReq->fcdRequestHeader.generationTime = *timestamp;
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

#ifndef FCDSERVICE_H
#define FCDSERVICE_H

#include <boost/thread.hpp>
#include <common/config/config.h>
#include <common/utility/CommunicationReceiver.h>
#include <common/utility/CommunicationSender.h>
#include <common/utility/CommunicationClient.h>
#include <common/buffers/build/cam.pb.h>
#include <common/buffers/build/denm.pb.h>
#include <common/buffers/build/gps.pb.h>
#include <common/buffers/build/obd2.pb.h>
#include <common/buffers/build/dccInfo.pb.h>
#include <common/buffers/build/camInfo.pb.h>
#include <common/buffers/build/ldmData.pb.h>
#include <common/buffers/build/request.pb.h>
#include <common/buffers/build/data.pb.h>
#include <google/protobuf/text_format.h>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <mutex>
#include <common/asn1/FCDREQ.h>
#include <common/messages/MessageUtils.h>
#include "Timer.h"
#include "external/rapidjson/document.h"
#include "external/rapidjson/writer.h"
#include "external/rapidjson/stringbuffer.h"
#include <iostream>
#include <stdio.h>


/** Struct that hold the configuration for FcdService.
 * The configuration is defined in <a href="../../fcd/config/config.xml">fcd/config/config.xml</a>
 */
struct FcdServiceConfig {
    int mTxInterval;
	int mNrOfRequests;
	int mMaxDistance;
	int mMaxHops;
	double mMaxRequestTimer;
	double mMaxReplyTimer;
	bool mIsRSU;
	int mTimeout;

	void loadConfigXML(const std::string &filename) {
		boost::property_tree::ptree pt;
		read_xml(filename, pt);

		mTxInterval = pt.get("fcd.txInterval", 10);
		mNrOfRequests = pt.get("fcd.nrOfRequests", 10);
        mMaxDistance = pt.get("fcd.maxDistance", 100);
		mMaxHops = pt.get("fcd.maxHops", 2);
		mMaxRequestTimer = pt.get("fcd.maxRequestTimer", 0.1);
		mMaxReplyTimer = pt.get("fcd.maxReplyTimer", 1);
		mIsRSU = pt.get("fcd.isRSU", false);

		mTimeout = pt.get("fcd.timeout", 100);
	}
};


/**
 * Class that handles the receiving, creating and sending of FCD Messages.
 *
 */
class FcdService {

public:
    FcdService(FcdServiceConfig &config, std::string globalConfig, std::string loggingConf, std::string statisticConf);
    ~FcdService();

    void sendLoop();

private:
	/** Receives incoming FCDs from DCC.
	 */
    void receive();

	/** Receives new GPS data from the GPS module.
	 *
	 */
	void receiveGpsData();

	/** Receives new OBD2 data from the OBD2 module.
	 *
	 */
	void receiveObd2Data();

	void handleRequest(FCDREQ_t* fcd);

	void handleReply(FCDREQ_t* fcd);

	FCDREQ_t* generateFcd(int reqId);

	/** Calculates the distance between the two specified coordinates
	 *
	 * @param lat1 Latitude of coordinate 1.
	 * @param lon1 Longitude of coordinate 1.
	 * @param lat2 Latitude of coordinate 2.
	 * @param lon2 Longitude of coordinate 2.
	 * @return The distance in meters.
	 */
	double getDistance(double lat1, double lon1, double lat2, double lon2);

	/** Updates the number of received FCD Requestes
	 *
	 */
	void updateCopy(FCDREQ_t* fcd);

	/** Returns the number of copies
	 *
	 */
	int getNumberOfCopies(int id);

	int getCurrentHopCount(int msgId);

	double getRandomNumber();

	bool isInhibited(int msgId);

	std::string createPayload();

	std::string requestCam(std::string condition);

	std::string requestCamInfo(std::string condition);

	void saveInFcdSet(std::string receivedPayload);

	void initializeResultFiles();

	void saveConfigurationToFile();

	void saveRequestToFile(FCDREQ_t* request);
	
	void saveRequestCopyToFile(FCDREQ_t* request);

	//void saveReplyToFile(FCDREQ_t* reply);

	void saveRepliesToFile(FCDREQ_t* reply, std::string mergedPayload);

	bool fexists(const std::string& filename);
	
	static void callback_request(FcdService* self, int tempId);

	static void callback_reply(FcdService* self, int tempId);

    CommunicationSender*   mSenderToDcc;
    CommunicationReceiver* mReceiverFromDcc;
	CommunicationReceiver* mReceiverGps;
	CommunicationReceiver* mReceiverObd2;
	
	CommunicationClient* mClientCam;
	CommunicationClient* mClientCamInfo;
	std::mutex mMutexCam;
	std::mutex mMutexCamInfo;

	gpsPackage::GPS mLatestGps;
	std::mutex mMutexLatestGps;

	obd2Package::OBD2 mLatestObd2;
	std::mutex mMutexLatestObd2;

    GlobalConfig    mGlobalConfig;
	MessageUtils*	mMsgUtils;

    boost::thread* mThreadSender;
    boost::thread* mThreadReceiver;
	boost::thread* mThreadGpsDataReceive;
	boost::thread* mThreadObd2DataReceive;
	//boost::thread* mIoServiceThread;

    FcdServiceConfig mConfig;
    LoggingUtility* mLogger;

	//boost::asio::io_service mIoService;
	//boost::asio::deadline_timer* mTimer;

	bool mRelayNode;
	bool mReplied;
	int mCurHopCount;
	int mExpNum;
	int mRequests;
	int64_t mCollectionStartTime;
	uint64_t myId;
	//string mMergedFcdSets;


	class FCDRequestInfo{

    public:

        FCDRequestInfo(FCDREQ_t* newMsg){ //constructor
            reqMsg = newMsg;
            copies = 1;
			inhibited = false;
        }

        ~FCDRequestInfo(){}; //destructor

        void updateCopy(){
            copies++;
        }

		void inhibit(){
            inhibited = true;
        }

        int getCopies(){
            return copies;
        }

		bool isInhibited(){
            return inhibited;
        }

        FCDREQ_t* getReqMsg(){
            return reqMsg;
        }

        private:
            FCDREQ_t* reqMsg;
            int copies;
			bool inhibited;
    };
	typedef std::map<int, FCDRequestInfo> FcdMsgInfo_table;
    FcdMsgInfo_table reqMap;


	class FCDInfo {

	public:
	    FCDInfo(uint64_t vehID, uint64_t lat, uint64_t lon){ //constructor
            vehicleID = vehID;
            latitude = lat;
			longitude = lon;
        }

		~FCDInfo(){}; //destructor

		uint64_t getVehicleId(){
			return vehicleID;
		}

		uint64_t getLatitude(){
			return latitude;
		}

		uint64_t getLongitude(){
			return longitude;
		}

		void setVehicleId(uint64_t vehID){
			vehicleID = vehID;
		}

		void setLatitude(uint64_t lat){
			latitude = lat;
		}

		void setLongitude(uint64_t lon){
			longitude = lon;
		}

    private:
        uint64_t vehicleID;
        uint64_t latitude;
		uint64_t longitude;
        //obd2Package::OBD2;
  	};

  	typedef std::map<uint64_t, FCDInfo> FCDInfoSet;    //id, FCDInfo
	FCDInfoSet mLocalFcdSet;
};

#endif

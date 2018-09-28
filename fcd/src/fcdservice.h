#ifndef FCDSERVICE_H
#define FCDSERVICE_H

#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <common/config/config.h>
#include <common/utility/CommunicationReceiver.h>
#include <common/utility/CommunicationSender.h>
#include <common/buffers/build/data.pb.h>
#include <common/buffers/build/cam.pb.h>
#include <common/buffers/build/gps.pb.h>
#include <common/buffers/build/obd2.pb.h>
#include <common/buffers/build/camInfo.pb.h>
#include <common/buffers/build/CoopAwareness.pb.h>
#include <common/buffers/build/ItsPduHeader.pb.h>
#include <mutex>
#include <common/asn1/CAM.h> //TODO: a dedicated FCD message has to be defined and the FCD.h header should be included here
#include <common/messages/MessageUtils.h>


/** Struct that hold the configuration for FcdService.
 * The configuration is defined in <a href="../../fcd/config/config.xml">fcd/config/config.xml</a>
 */
struct FcdServiceConfig {
    int mTxInterval;
	int mMaxDistance;
	int mMaxHops;
	double mMaxRequestTimer;
	double mMaxReplyTimer;
	bool mIsRSU;

	void loadConfigXML(const std::string &filename) {
		boost::property_tree::ptree pt;
		read_xml(filename, pt);

		mTxInterval = pt.get("fcd.txInterval", 10);
        mMaxDistance = pt.get("fcd.maxDistance", 100);
		mMaxHops = pt.get("fcd.maxHops", 2);
		mMaxRequestTimer = pt.get("fcd.maxRequestTimer", 0.1);
		mMaxReplyTimer = pt.get("fcd.maxReplyTimer", 1);
		mIsRSU = pt.get("fcd.isRSU", false);
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
    void receive();

    CommunicationSender*   mSenderToDcc;
    CommunicationReceiver* mReceiverFromDcc;
    GlobalConfig           mGlobalConfig;

    boost::thread* mThreadSender;
    boost::thread* mThreadReceiver;

    FcdServiceConfig mConfig;
    LoggingUtility* mLogger;
};

#endif

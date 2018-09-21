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
#include <common/asn1/CAM.h>
#include <common/messages/MessageUtils.h>

/**
 * Class that handles the receiving, creating and sending of FCD Messages.
 *
 */

class FcdService {

public:
    FcdService(std::string globalConfig, std::string loggingConf, std::string statisticConf);
    ~FcdService();

    void sendLoop();

private:
    void receive();

    CommunicationSender*   mSenderToDcc;
    CommunicationReceiver* mReceiverFromDcc;
    GlobalConfig           mGlobalConfig;

    boost::thread* mThreadSender;
    boost::thread* mThreadReceiver;

    LoggingUtility* mLogger;
};

#endif

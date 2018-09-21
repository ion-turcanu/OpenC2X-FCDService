
#define ELPP_THREAD_SAFE
#define ELPP_NO_DEFAULT_LOG_FILE

#include "fcdservice.h"
#include <iostream>
#include <string>
#include <common/utility/Utils.h>

INITIALIZE_EASYLOGGINGPP

using namespace std;

FcdService::FcdService(string globalConfig, string logConf, string statConf) {
    try {
        mGlobalConfig.loadConfigXML(globalConfig);
    }
    catch (std::exception &e) {
        cerr << "Error while loading config.xml: " << e.what() << endl;
    }

    // Logging
    mLogger = new LoggingUtility("FcdService", mGlobalConfig.mExpNo, logConf, statConf);
    
    // Sender and Receiver
    mReceiverFromDcc = new CommunicationReceiver("FcdService", "5555", "FCD", mGlobalConfig.mExpNo, logConf, statConf);
    mSenderToDcc     = new CommunicationSender("FcdService", "2323", mGlobalConfig.mExpNo, logConf, statConf);

    // Start the threads
    mThreadSender   = new boost::thread(&FcdService::sendLoop, this);
    mThreadReceiver = new boost::thread(&FcdService::receive, this);
}

FcdService::~FcdService() {
    mThreadSender->join();
    mThreadReceiver->join();

    delete mThreadSender;
    delete mThreadReceiver;

    delete mReceiverFromDcc;
    delete mSenderToDcc;

    delete mLogger;

    cout << "~FcdService" << endl;
}

void FcdService::sendLoop() {
    int counter = 0;

    // Endless loop that sends every second an FCD message
    while(1) {
        string serializedData;
        dataPackage::DATA data;

        data.set_id(messageID_fcd);
        data.set_type(dataPackage::DATA_Type_FCD);
        data.set_priority(dataPackage::DATA_Priority_VI);

        int64_t currTime = Utils::currentTime();
        data.set_createtime(currTime);
        data.set_validuntil(currTime + 2*1000*1000*1000);
        data.set_content("FCD" + to_string(counter));

        data.SerializeToString(&serializedData);

        // Send message
        mSenderToDcc->send("FCD", serializedData);
        counter++;

        // Wait for one second
        boost::this_thread::sleep(boost::posix_time::seconds(1));
        std::cout << "[FCD] Sending FCD out: " << std::endl;
    }
}

void FcdService::receive() {
    string env;
    string str;

    while (1) {
        pair<string, string> received = mReceiverFromDcc->receive();
        env = received.first;
        str = received.second;

        //mLogger->logInfo("Incoming FCD: " + str);
        std::cout << "[FCD] Incoming FCD: " << str << std::endl;
    }
}

int main(int argc, const char* argv[]) {

    if(argc != 4) {
        fprintf(stderr, "missing arguments: %s <globalConfig.xml> <logging.conf> <statistics.conf> \n", argv[0]);
        exit(1);
    }

    FcdService fcd(argv[1], argv[2], argv[3]);
    
    return EXIT_SUCCESS;
}

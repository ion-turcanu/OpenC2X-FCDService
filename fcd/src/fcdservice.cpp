#include "fcdservice.h"
#include <iostream>
#include <string>

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
    mReceiverFromLdm = new CommunicationReceiver("FcdService", "5555", "FCD", mGlobalConfig.mExpNo, logConf, statConf);
    mSenderToLdm     = new CommunicationSender("FcdService", "8888", mGlobalConfig.mExpNo, logConf, statConf);

    // Start the threads
    mThreadSender   = new boost::thread(&FcdService::sendLoop, this);
    mThreadReceiver = new boost::thread(&FcdService::receive, this);
}

FcdService::~FcdService() {
    mThreadSender->join();
    mThreadReceiver->join();

    cout << "~FcdService" << endl;
}

void FcdService::sendLoop() {
    int counter = 0;

    // Endless loop that sends every second an FCD message
    while(1) {
        // Send message
        mSenderToLdm->send("FCD", "FCD" + to_string(counter));
        counter++;

        // Wait for one second
        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }
}

void FcdService::receive() {
    string env;
    string str;

    while (1) {
        pair<string, string> received = mReceiverFromLdm->receive();
        env = received.first;
        str = received.second;

        mLogger->logInfo("Incoming FCD: " + str);
    }
}

int main(int argc, const char* argv[]) {

    if(argc != 5) {
        fprintf(stderr, "missing arguments: %s <globalConfig.xml> <camConfig.xml> <logging.conf> <statistics.conf> \n", argv[0]);
        exit(1);
    }

    FcdService fcd(argv[1], argv[3], argv[4]);

    return EXIT_SUCCESS;
}

#include "fcdservice.h"
#include <iostream>

INITIALIZE_EASYLOGGINGPP

using namespace std;

FcdService::FcdService(string globalConfig, string loggingConf, string statisticConf) {
    cout << "FcdService" << endl;

    try {
        mGlobalConfig.loadConfigXML(globalConfig);
    }
    catch (std::exception &e) {
        cerr << "Error while loading config.xml: " << e.what() << endl;
    }


    mSenderToLdm = new CommunicationSender("FcdService", "8888", mGlobalConfig.mExpNo, loggingConf, statisticConf);
}

FcdService::~FcdService() {
    cout << "~FcdService" << endl;
}

int main(int argc, const char* argv[]) {
    if(argc != 5) {
        fprintf(stderr, "missing arguments: %s <globalConfig.xml> <camConfig.xml> <logging.conf> <statistics.conf> \n", argv[0]);
        exit(1);
    }

    FcdService fcd(argv[1], argv[3], argv[4]);

    return EXIT_SUCCESS;
}

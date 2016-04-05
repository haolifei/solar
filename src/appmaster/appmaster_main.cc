#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <sofa/pbrpc/pbrpc.h>
#include <gflags/gflags.h>
#include "appmaster_impl.h"

static volatile bool s_quit = false;
static void SignalIntHandler(int /*sig*/){
    s_quit = true;
}

int main(int argc, char* argv[]) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    baidu::galaxy::AppMasterImpl * appmaster = new baidu::galaxy::AppMasterImpl();
    appmaster->Init();
    sofa::pbrpc::RpcServerOptions options;
    sofa::pbrpc::RpcServer rpc_server(options);
    if (!rpc_server.RegisterService(static_cast<baidu::galaxy::AppMaster*>(appmaster))) {
        LOG(FATAL, "failed to register appmaster service");
        exit(-1);
    }

    std::string endpoint = "0.0.0.0:" + FLAGS_appmaster_port;
    if (!rpc_server.Start(endpoint)) {
        LOG(FATAL, "failed to start server on %s", endpoint.c_str());
        exit(-2);
    }
    signal(SIGINT, SignalIntHandler);
    signal(SIGTERM, SignalIntHandler);

    LOG(INFO, "appmaster started.");
    while (!s_quit) {
        sleep(1);
    }
    return 0;
}


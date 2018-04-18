#include <iostream>
#include <stdio.h>
#include <enet/enet.h>
#include "udpserver.h"
#include "netrequestmgr.h"
#include "timer_manager.h"
#include "character_mgr.h"
#include <glog/logging.h>
#include "message.pb.h"
#include "system_util.h"
#include "message_process.h"
#include "process_event.h"

DEFINE_bool(daemon,false,"run in daemon");

int main(int argc, char** argv){
    google::ParseCommandLineFlags(&argc,&argv,true); 
    google::InitGoogleLogging(argv[0]);
    if(FLAGS_daemon == false){
        LOG(INFO)<<"run in front..."; 
        FLAGS_logtostderr =true;
    }else{
        LOG(INFO)<<"run in background"; 
        daemon_init_func(1,1);
    }

    if (enet_initialize () != 0)
    {
        LOG(ERROR)<<"error of enet!";
        return -1;
    }

    timer_manager::CreateInstance();
    timer_manager::Instance()->init(14);
    net_request_mgr::CreateInstance();

    CCharacterMgr::CreateInstance();
    //new thread process receive udp message!
    udp_server::CreateInstance();
    udp_server* pServer = udp_server::Instance();//udp_server::Instance();
    pServer->init("0.0.0.0",1234,2000);
    pServer->create();

    bool bRun = true;
    int t = time(NULL);
    while(bRun){
        timer_manager::Instance()->run_until_now();
        process_all_event(200);
        usleep(50); 
        net_request_mgr::Instance()->dump_statis();
    }
    timer_manager::DestoryInstance();
    udp_server::DestoryInstance();
    net_request_mgr::DestoryInstance();

    atexit(enet_deinitialize);
    return 0;
}

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
#include "signal.h"

DEFINE_bool(daemon,false,"run in daemon");

bool g_run = false;

void signal_function(int signo){
    LOG(INFO)<<"Recv signo"<<signo;
}

void init_signal_func()
{
    signal(SIGINT,signal_function) ;               
    signal(SIGTERM,signal_function) ;              
    signal(SIGQUIT,signal_function) ;              
    signal(SIGUSR2,signal_function) ;              
    signal(SIGUSR1,signal_function) ;            
    signal(SIGPIPE, SIG_IGN);         
    signal(SIGALRM,SIG_IGN);         
    signal(SIGHUP,SIG_IGN);           
}

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
    init_signal_func();

    timer_manager::CreateInstance();
    timer_manager::Instance()->init(14);
    net_request_mgr::CreateInstance();

    CCharacterMgr::CreateInstance();
    //new thread process receive udp message!
    udp_server::CreateInstance();
    udp_server* pServer = udp_server::Instance();//udp_server::Instance();
    pServer->init("0.0.0.0",1234,2000);
    pServer->create();

    g_run = true;
    while(g_run){
        timer_manager::Instance()->run_until_now();
        process_all_event(200);
        usleep(50); 
        //net_request_mgr::Instance()->dump_statis();
    }
    timer_manager::DestoryInstance();
    udp_server::DestoryInstance();
    net_request_mgr::DestoryInstance();
    CCharacterMgr::DestoryInstance();

    atexit(enet_deinitialize);
    return 0;
}

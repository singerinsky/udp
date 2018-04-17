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


void process_udp_event(e_uint32 uMaxProcessNum)
{
    e_uint32 count = 0;
    while(uMaxProcessNum >= count++){
        stInEvent* pevent =  net_request_mgr::Instance()->pop_in_event();
        if(pevent == NULL){
            return; 
        }
        switch(pevent->nType)
        {
            case eConnect:
                {
                    ENetPeer* peer = udp_server::Instance()->get_peer(pevent->stUn.connEvt.dwConnID);
                    printf("accept new connection from %d :%d!\n",peer->address.host,peer->address.port);
                    //set time out
                    enet_peer_timeout(peer,500,1000,1000);
                    //net_request_mgr::Instance()->push_disconnect_outevent(pevent->stUn.connEvt.dwConnID);
                    SoccerPlayerInfoRequest request;
                    std::string name = request.GetTypeName();
                    LOG(INFO)<<name;
                }
                break;
            case eConnectFail:
                break;
            case eRecv:
                {
                    int ret = message_process::Instance()->parse_recv_message(pevent,
                            pevent->stUn.recvEvt.pData,
                            pevent->stUn.recvEvt.dwLen);
                    if(pevent->stUn.recvEvt.pData != NULL){
                        delete[] pevent->stUn.recvEvt.pData; 
                    }
                    break;
                }
            case eDisConnect:
                break;
            case eNone:
                break;
        }
        delete pevent;
    }
    return;
}

void process_tcp_event(int process_num)
{
    LOG(INFO)<<"Process tcp event!!";
}

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

    //new thread process receive udp message!
    udp_server::CreateInstance();
    udp_server* pServer = udp_server::Instance();//udp_server::Instance();
    pServer->init("0.0.0.0",1234,2000);
    pServer->create();

    bool bRun = true;
    int t = time(NULL);
    while(bRun){
        timer_manager::Instance()->run_until_now();
        process_udp_event(200);
        process_tcp_event(200);
        usleep(50); 
    }
    timer_manager::DestoryInstance();
    udp_server::DestoryInstance();
    net_request_mgr::DestoryInstance();

    atexit(enet_deinitialize);
    return 0;
}

#include "process_event.h"
#include "serverpch.h"
#include "event_define.h"
#include "netrequestmgr.h"
#include "udpserver.h"
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
                    ENetPeer* peer = udp_reactor::Instance()->get_peer(pevent->stUn.connEvt.dwConnID);
                    LOG(INFO)<<"New Connection ip:"<<peer->address.host<<" port:"<<peer->address.port;
                    enet_peer_timeout(peer,500,1000,1000);
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
                LOG(INFO)<<"Disconnect !";
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

void process_all_event(e_uint32 uMaxProcessNum){
    process_udp_event(uMaxProcessNum);
    //process_tcp_event(uMaxProcessNum);
}




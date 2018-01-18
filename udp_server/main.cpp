#include <iostream>
#include <stdio.h>
#include <enet/enet.h>
#include "udpserver.h"
#include "netrequestmgr.h"
#include "timer_manager.h"
#include "character_mgr.h"

void process_event()
{
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
                net_request_mgr::Instance()->push_disconnect_outevent(pevent->stUn.connEvt.dwConnID);
            }
            break;
        case eConnectFail:
            break;
        case eRecv:
            printf("data len %d =>%s\n",
                    pevent->stUn.recvEvt.dwLen,
                    pevent->stUn.recvEvt.pData);
            //decode message
            if(pevent->stUn.recvEvt.pData != NULL){
                delete pevent->stUn.recvEvt.pData; 
            }
            break;
        case eDisConnect:
            break;
        case eNone:
            break;
   }
   delete pevent;
}

int main(){
    if (enet_initialize () != 0)
    {
        printf ("An error occurred while initializing ENet.\n");
        return -1;
    }

    timer_manager::CreateInstance();
    timer_manager::Instance()->init(14);
    net_request_mgr::CreateInstance();
    udp_server::CreateInstance();
    udp_server* pServer = udp_server::Instance();//udp_server::Instance();
    pServer->init("0.0.0.0",1234,1000);
    pServer->create();
    CCharacterMgr mgr;
    while(true){
        //netrequestmgr::Instance()->pop_event();
        timer_manager::Instance()->run_until_now();
        process_event();
        usleep(10); 
    }
    atexit(enet_deinitialize);
    return 0;
}

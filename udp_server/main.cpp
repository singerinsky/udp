#include <iostream>
#include <stdio.h>
#include <enet/enet.h>
#include "udpserver.h"
#include "netrequestmgr.h"
#include "timer_manager.h"

void process_event()
{
   stEvent* pevent =  net_request_mgr::Instance()->pop_event();
   if(pevent == NULL){
        return; 
   }
   switch(pevent->nType)
   {
        case eConnect:
            printf("accept new connection!\n");
            break;
        case eConnectFail:
            break;
        case eRecv:
            printf("data len %d =>%s\n",
                    pevent->stUn.recvEvt.dwLen,
                    pevent->stUn.recvEvt.pData);
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
    

    timer_manager timermgr;
    timermgr.init(14);
    net_request_mgr::CreateInstance();
    udp_server* pServer = new udp_server();//udp_server::Instance();
    pServer->init("0.0.0.0",1234,1000);
    pServer->create();
    while(true){
        //netrequestmgr::Instance()->pop_event();
        timermgr.run_until_now();
        process_event();
        usleep(10); 
    }
    atexit(enet_deinitialize);
    return 0;
}

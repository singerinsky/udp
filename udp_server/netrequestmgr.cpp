#include "netrequestmgr.h"
#include "udpserver.h"

INSTANCE_SINGLETON(net_request_mgr);

void net_request_mgr::push_recv_event(e_uint32 uConnID,const char* pData,e_uint32 nlen)
{
    stInEvent* pevent = new stInEvent();
    pevent->nType= eRecv;
    pevent->stUn.recvEvt.dwConnID = uConnID;
    char* buff = new char[nlen];
    memcpy(buff,pData,nlen);
    pevent->stUn.recvEvt.pData = buff;
    pevent->stUn.recvEvt.dwLen = nlen;
    _net_request_queue.enqueue(pevent);
    _statis.uRecvCount++;
}

void net_request_mgr::push_conn_event(e_uint32 uConnID,e_uint32 uRemoteIP,e_uint32 uRemotePort)
{
    stInEvent* pevent = new stInEvent();
    pevent->nType = eConnect;
    pevent->stUn.connEvt.dwConnID = uConnID; 
    pevent->stUn.connEvt.dwRemoteIP = uRemoteIP; 
    pevent->stUn.connEvt.dwRemotePort = uRemotePort; 
    _net_request_queue.enqueue(pevent); 
    _statis.uRecvCount++;
}

void net_request_mgr::push_disconn_event(e_uint32 uConnID,e_uint32 uRemoteIP,e_uint32 uRemotePort)
{
    stInEvent* pevent = new stInEvent();
    pevent->nType = eDisConnect;
    pevent->stUn.connEvt.dwConnID = uConnID; 
    pevent->stUn.connEvt.dwRemoteIP = uRemoteIP; 
    pevent->stUn.connEvt.dwRemotePort = uRemotePort; 
    _net_request_queue.enqueue(pevent); 
    _statis.uRecvCount++;
}

stInEvent* net_request_mgr::pop_in_event(){
    stInEvent* pevent = _net_request_queue.dequeue();
    if(pevent != NULL){
        _statis.uProcessCount++;
    }
    return pevent;
}

void    net_request_mgr::push_disconnect_outevent(e_uint32 uConnID)
{
    stOutEvent* pevent = new stOutEvent();
    pevent->nType = eOutDisconnect;
    pevent->stUn.disOutEvt.dwConnID = uConnID;
    _net_out_queue.enqueue(pevent);
}

void    net_request_mgr::push_send_outevent(e_uint32 uConnID,char* pData,e_uint32 nLen)
{
    stOutEvent* pevent = new stOutEvent();
    pevent->nType = eOutSend;
    pevent->stUn.sendOutEvt.dwConnID = uConnID;
    pevent->stUn.sendOutEvt.pData = pData;
    pevent->stUn.sendOutEvt.sendLen = nLen;
    _net_out_queue.enqueue(pevent);
}

void net_request_mgr::process_out_event(e_uint32 process_num)
{
    int uCount = 0;
    while(true){
        uCount++;
        if(uCount >= process_num)
            return;
        stOutEvent* pevent = _net_out_queue.dequeue();
        if(pevent == NULL){
            return;
        }
        switch(pevent->nType)
        {
            case eOutDisconnect:
                {
                    ENetPeer* peer = udp_server::Instance()->get_peer(pevent->stUn.disOutEvt.dwConnID);
                    if(peer != NULL){
                        enet_peer_disconnect_now(peer,0); 
                        LOG(INFO)<<"disconnect peer!\n";
                    }else{
                        LOG(ERROR)<<"error of disconnect !failed find peer!\n"; 
                    }
                }
                break;
            case eOutSend:
                {
                    ENetPacket* packet = enet_packet_create(NULL,
                            pevent->stUn.sendOutEvt.sendLen,
                            ENET_PACKET_FLAG_RELIABLE);
                    memcpy((char*)packet->data,pevent->stUn.sendOutEvt.pData,pevent->stUn.sendOutEvt.sendLen);
                    ENetPeer* peer = udp_server::Instance()->get_peer(pevent->stUn.sendOutEvt.dwConnID);
                    if(peer != NULL){
                        LOG(INFO)<<"send data back to client!\n";
                        enet_peer_send(peer,0,packet);
                    }else
                    {
                        LOG(ERROR)<<"error of send data,failed find peer!\n"; 
                    }
                    delete[] pevent->stUn.sendOutEvt.pData;
                }
                break;
            default:
                assert(false);
        }
        delete pevent;
    }

}



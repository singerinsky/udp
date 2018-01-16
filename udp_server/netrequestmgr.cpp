#include "netrequestmgr.h"

INSTANCE_SINGLETON(net_request_mgr);

void net_request_mgr::push_recv_event(e_uint32 uConnID,const char* pData,e_uint32 nlen)
{
    stEvent* pevent = new stEvent();
    pevent->nType= eRecv;
    pevent->stUn.recvEvt.dwConnID = uConnID;
    char* buff = new char[nlen];
    memcpy(buff,pData,nlen);
    pevent->stUn.recvEvt.pData = buff;
    pevent->stUn.recvEvt.dwLen = nlen;
    _net_request_queue.enqueue(pevent);
}

void net_request_mgr::push_conn_event(e_uint32 uConnID,e_uint32 uRemoteIP,e_uint32 uRemotePort)
{
    stEvent* pevent = new stEvent();
    pevent->nType = eConnect;
    pevent->stUn.connEvt.dwConnID = uConnID; 
    pevent->stUn.connEvt.dwRemoteIP = uRemoteIP; 
    pevent->stUn.connEvt.dwRemotePort = uRemotePort; 
    _net_request_queue.enqueue(pevent); 
}

void net_request_mgr::push_disconn_event(e_uint32 uConnID,const char* strRemoteIP,e_uint32 uRemotePort)
{

}

stEvent* net_request_mgr::pop_event(){

    stEvent* pevent = _net_request_queue.dequeue();
    return pevent;
}


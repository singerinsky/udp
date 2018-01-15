#include "netrequestmgr.h"

INSTANCE_SINGLETON(net_request_mgr);

void net_request_mgr::push_recv_event(e_uint32 uConnID,const char* pdata,e_uint32 nlen)
{
    stEvent* pevent = new stEvent();
    pevent->uEventType = eRecv;
    pevent->stUn.uConnID = uConnID;

}

void net_request_mgr::push_conn_event(e_uint32 uConnID,const char* strRemoteIP,e_uint32 uRemotePort)
{
}

void net_request_mgr::push_disconn_event(e_uint32 uConnID,const char* strRemoteIP,e_uint32 uRemotePort)
{

}

stEvent* net_request_mgr::pop_event(){


}


#ifndef _NET_REQUEST_MGR_H_
#define _NET_REQUEST_MGR_H_

#include "singleton.h"
#include "queue.h"
#include "event_define.h"

class net_request_mgr{
    DECLARE_SINGLETON(net_request_mgr);
    public:
        void        push_recv_event(e_uint32 uConnID,const char* pdata,e_uint32 nlen);
        void        push_conn_event(e_uint32 uConnID,e_uint32 uRemoteIP,e_uint32 uRemotePort);
        void        push_disconn_event(e_uint32 uConnID,const char* strRemoteIP,e_uint32 uRemotePort);
        stEvent*    pop_event(); 
    
    private:
        ConcurrenceQueue<stEvent>   _net_request_queue; 
}; 

#endif

#ifndef _NET_REQUEST_MGR_H_
#define _NET_REQUEST_MGR_H_

#include "singleton.h"
#include "queue.h"
#include "event_define.h"

struct net_statis
{
    e_uint32 uRecvCount;
    e_uint32 uProcessCount;
    net_statis(){
        memset(this,0,sizeof(net_statis)); 
    }
};

class net_request_mgr{
    DECLARE_SINGLETON(net_request_mgr);
    public:
        void        push_recv_event(e_uint32 uConnID,const char* pdata,e_uint32 nlen);
        void        push_conn_event(e_uint32 uConnID,e_uint32 uRemoteIP,e_uint32 uRemotePort);
        void        push_disconn_event(e_uint32 uConnID,e_uint32 strRemoteIP,e_uint32 uRemotePort);
        stInEvent*  pop_in_event(); 
        void        process_out_event(e_uint32 process_num);
        void        push_disconnect_outevent(e_uint32 uConnID);
        void        push_send_outevent(e_uint32,char*,e_uint32);
        void        dump_statis(){
            printf("%d:%d\n",_statis.uRecvCount,_statis.uProcessCount); 
        }

    private:
        ConcurrenceQueue<stInEvent>     _net_request_queue; 
        ConcurrenceQueue<stOutEvent>    _net_out_queue; 
        net_statis  _statis;
}; 

#endif

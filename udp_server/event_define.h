#ifndef _EVENT_DEFINE_H_
#define _EVENT_DEFINE_H_

enum EventType{
    eNone = 0,
    eConnect,
    eConnectFail,
    eRecv,
    eDisConnect
};

struct stConnectEvt{
    e_uint32 dwSockID;
    e_uint32 dwConnID;
    e_uint32 dwLocalIP;
    e_uint32 dwRemoteIP;
    e_uint32 dwLocalPort;
    e_uint32 dwRemotePort;
};

struct stConnFailEvt{
    e_uint32 dwError;
    e_uint32 dwHandle;
};

struct stRecvEvt
{
    e_uint32 dwConnID;
    e_uint32 dwLen;
    char*    pData;
};

struct stDisconnEvt
{
    e_uint32 dwConnID;
    e_uint32 dwError;
};

struct stEvent{
    EventType nType;
    union
    {
        stConnFailEvt;
        stConnectEvt;
        stRecvEvt;
        stDisconnEvt;
    }stUn;
};


#endif

#ifndef _EVENT_DEFINE_H_
#define _EVENT_DEFINE_H_

struct stMsgHead{
    int uMsgType;
    int uMsgLen;
};

enum eInEventType{
    eNone = 0,
    eConnect,
    eConnectFail,
    eRecv,
    eDisConnect
};

enum eOutEventType
{
    eOutNone = 0,
    eOutDisconnect,
    eOutSend,
    eOutStopRecv,
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

struct stInEvent{
    eInEventType nType;
    union
    {
        stConnFailEvt failEvt;
        stConnectEvt connEvt;
        stRecvEvt recvEvt;
        stDisconnEvt disEvt;
    }stUn;
};

struct stDisconnOutEvt
{
    e_uint32 dwConnID;
};

struct stSendOutEvt
{
    e_uint32 dwConnID;
    e_uint32 sendLen;
    char*    pData;
};

/*
struct stStopRecv
{
};
*/

struct stOutEvent
{
    eOutEventType nType;
    union
    {
        stDisconnOutEvt disOutEvt;
        stSendOutEvt    sendOutEvt;
    }stUn;
};

#endif

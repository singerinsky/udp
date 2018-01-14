#ifndef _EVENT_DEFINE_H_
#define _EVENT_DEFINE_H_

enum EventType{
    eNone = 0,
    eConnect,
    eRecv,
    eDisConnect
};

struct stEvent{
    e_int32     uEventType;
    e_uint32    uConnID;
    void*       pEventData;
};


#endif

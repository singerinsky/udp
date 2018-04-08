#ifndef _MESSAGE_PROCESS_H_
#define _MESSAGE_PROCESS_H_

#include "serverpch.h"
#include <streambuf>
#include <istream>
#include "message.pb.h"
#include "bit_order.h"
#include "event_define.h"
#include "request_function.h"

struct membuf:std::streambuf
{
    membuf(char* buff,e_uint32 nLen){
        this->setg(buff,buff,buff+nLen);    
    }
};

#define MESSAGE_DISPATCH(MessageType,MessageClass)\
    case MessageType:\
        {\
            MessageClass object;\
            object.ParseFromIstream(&istr);\
            do_##MessageClass(object,pEvent->stUn.recvEvt.dwConnID);\
            break;\
        }\


class message_process
{
    DECLARE_SINGLETON(message_process);
    public:
        int parse_message(stInEvent* pEvent, char* pData, e_uint32 nLen) 
        {
            assert(nLen > 2*sizeof(e_uint32));
            e_uint32 uMessageType = 0,uMessageLen;
            memcpy(&uMessageType,pData,sizeof(e_uint32));
            memcpy(&uMessageLen,pData+4,sizeof(e_uint32));
            uMessageType = ntoh_int32(uMessageType);
            membuf buf(pData+8,nLen);
            istream istr(&buf);
            switch(uMessageType){
                MESSAGE_DISPATCH(MSG_HEART_BEAT,ClientHeartBeatRequest ) 
            
                default:
                {
                    LOG(ERROR)<<"undefined message!";
                    return -1;
                }
            }
            return 1;
            //google::protobuf::Message message;//  = new google::protobuf::Message();
            //message.ParseFromIstream(&istr);
        };
};

#endif

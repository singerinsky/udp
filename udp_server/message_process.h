#ifndef _MESSAGE_PROCESS_H_
#define _MESSAGE_PROCESS_H_

#include "serverpch.h"
#include <streambuf>
#include <istream>
#include "message.pb.h"

struct membuf:std::streambuf
{
    membuf(char* buff,e_uint32 nLen){
        this->setg(buff,buff,buff+nLen);    
    }
};

class message_process
{
    DECLARE_SINGLETON(message_process);
    public:
        void    parse_message(char* pData,e_uint32 nLen) {
            membuf buf(pData,nLen);
            istream istr(&buf);
            google::protobuf::Message message;//  = new google::protobuf::Message();
            message.ParseFromIstream(&istr);
        };
};

#endif

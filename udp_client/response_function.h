#ifndef _RESPONSE_FUNCTION_H_
#define _RESPONSE_FUNCTION_H_

#include <streambuf>
#include <istream>
#include "message.pb.h"
#include <enet/enet.h>


void do_ClientLoginAck(ClientLoginAck& response,int dwConnID)
{
    LOG(INFO)<<"Client Login Ack! Current time :"<<response.ret();
}


#endif

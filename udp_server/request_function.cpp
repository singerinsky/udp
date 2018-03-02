#include "request_function.h"
#include "serverpch.h"
#include <streambuf>
#include <istream>
#include "message.pb.h"


void do_ClientHeartBeatRequest(ClientHeartBeatRequest& request,e_uint32 dwConnID)
{
    LOG(INFO)<<"Client HeartBeat!";
}


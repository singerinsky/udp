#ifndef _REQUEST_FUNCTION_H_
#define _REQUEST_FUNCTION_H_

#include "serverpch.h"
#include <streambuf>
#include <istream>
#include "message.pb.h"
#include "event_define.h"


void do_ClientHeartBeatRequest(ClientHeartBeatRequest& request,e_uint32 dwConnID);

#endif

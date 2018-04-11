#include "request_function.h"
#include "serverpch.h"
#include <streambuf>
#include <istream>
#include "message.pb.h"
#include "message_process.h"


void do_ClientHeartBeatRequest(ClientHeartBeatRequest& request,e_uint32 dwConnID)
{
    LOG(INFO)<<"Client HeartBeat! Current time :"<<request.client_time();
    ClientHeartBeatRequest response;
    response.set_client_time(request.client_time());
    message_process::Instance()->compress_send_message(dwConnID,&response,MSG_HEART_BEAT);
}

void do_ClientLoginRequest(ClientLoginRequest& request,e_uint32 dwConnID)
{
    LOG(INFO)<<"Client HeartBeat! Current time :"<<request.md5_code().length();
    ClientHeartBeatRequest response;
    response.set_client_time(1);
    message_process::Instance()->compress_send_message(dwConnID,&response,MSG_HEART_BEAT);

}


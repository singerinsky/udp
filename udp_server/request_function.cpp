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
    SEND_MSG(dwConnID,response,MSG_HEART_BEAT);
}

void do_ClientLoginRequest(ClientLoginRequest& request,e_uint32 dwConnID)
{
    LOG(INFO)<<"Client HeartBeat! Current time :"<<request.player_id();
    ClientLoginAck ack;
    ack.set_player_id(9999);
    ack.set_ret(1);
    SEND_MSG(dwConnID,ack,MSG_CLIENT_LOGIN_ACK);
}


#ifndef _MESSAGE_BUILD_H_
#define _MESSAGE_BUILD_H_

#include <enet/enet.h>
#include "message.pb.h"
#include "bit_order.h"
#include <sstream>
#include <stdio.h>
#include <glog/logging.h>
#include <streambuf>
#include <istream>
#include "response_function.h"

using namespace std;
using namespace google;

struct membuf:std::streambuf
{
    membuf(char* buff,int nLen){
        this->setg(buff,buff,buff+nLen);    
    }
};

#define MESSAGE_DISPATCH(MessageType,MessageClass,ConnID)\
    case MessageType:\
        {\
            MessageClass object;\
            object.ParseFromIstream(&istr);\
            do_##MessageClass(object,ConnID);\
            break;\
        }\



int g_send_size = 0;

void send_message_reliable(ENetPeer* peer,protobuf::Message* pMessage,int uMessageType)
{
    int uTotoalSize = pMessage->ByteSize() + 8;
    ENetPacket *packet = enet_packet_create(NULL,uTotoalSize,ENET_PACKET_FLAG_RELIABLE); //创建包

    int uMessageLen = hton_int32(pMessage->ByteSize());
    uMessageType = hton_int32(uMessageType);
    memcpy((char*)packet->data,&uMessageType,sizeof(uMessageType));
    memcpy((char*)packet->data+4,&uMessageLen,sizeof(uMessageLen));

    //streambuf buff;
    //ostream output(&buff);
    bool serRst = pMessage->SerializeToArray(packet->data+8,uTotoalSize - 8 );
    if(serRst == false){
         fprintf (stderr, 
                "error parse!");
    }
    int sendLen = enet_peer_send(peer,0,packet);
    g_send_size += sendLen;
    //    LOG(INFO)<<"send "<<sendLen <<" totoal "<< ntoh_int32(uMessageLen);
}

struct stMsgHead
{
    int uMsgType;
    int uMsgLen;
};

int parse_recv_message(char* pData,int dwLen, int dwConnID){
    int uMessageType = 0;
    stMsgHead head;
    memcpy(&head,pData,sizeof(stMsgHead));

    uMessageType = ntoh_int32(head.uMsgType);
    membuf buf(pData+sizeof(stMsgHead),dwLen);
    istream istr(&buf);
    switch(uMessageType){
            MESSAGE_DISPATCH(MSG_CLIENT_LOGIN_ACK,ClientLoginAck,dwConnID) 

        default:
            {
                LOG(ERROR)<<"undefined message!";
                return -1;
            }
    }
    return 1;
}



#endif

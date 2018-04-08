#ifndef _MESSAGE_BUILD_H_
#define _MESSAGE_BUILD_H_

#include <enet/enet.h>
#include "message.pb.h"
#include "bit_order.h"
#include <sstream>
#include <stdio.h>

using namespace std;
using namespace google;

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
    enet_peer_send(peer,0,packet);
}

#endif

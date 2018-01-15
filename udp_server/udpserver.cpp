/*
 * udpserver.cpp
 *
 *  Created on: 2018Äê1ÔÂ11ÈÕ
 *      Author: user
 */

#include "udpserver.h"

INSTANCE_SINGLETON(udp_server);

udp_server::udp_server() {
	// TODO Auto-generated constructor stub
	m_bRun = false;
}

udp_server::~udp_server() {
	// TODO Auto-generated destructor stub
	enet_host_destroy(m_pServer);
}

bool udp_server::init(std::string str_ip,e_uint32 u_port,e_uint32 u_max_online)
{
	if (enet_initialize () != 0)
	{
		return false;
	}
	enet_address_set_host (&_address, str_ip.c_str());
	/* Bind the server to port 1234. */
	_address.port = u_port;
	m_pServer = enet_host_create (& _address /* the address to bind the server host to */,
			u_max_online      /* allow up to 32 clients and/or outgoing connections */,
			2      /* allow up to 2 channels to be used, 0 and 1 */,
			0      /* assume any amount of incoming bandwidth */,
			0      /* assume any amount of outgoing bandwidth */);
	if (m_pServer == NULL)
	{
		return false;
	}
	return true;
}

bool udp_server::loop(){
	  ENetEvent *event = new ENetEvent();
	    /* Wait up to 1000 milliseconds for an event. */
	    while(m_bRun){
	        //printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
	        while (enet_host_service (m_pServer, event, 1) >= 0)
	        {

	            printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
	            switch (event->type)
	            {
	            	//build gameserver event,send to logic thread
	                case ENET_EVENT_TYPE_CONNECT:
	                    printf ("A new client connected from %x:%u.\n",
	                            event->peer -> address.host,
	                            event->peer -> address.port);
	                    /* Store any relevant client information here. */
	                    break;
	                case ENET_EVENT_TYPE_RECEIVE:
	                    printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
	                            event->packet -> dataLength,
	                            event->packet -> data,
	                            event->peer -> data,
	                            event->channelID);
	                    /* Clean up the packet now that we're done using it. */
	                    enet_packet_destroy (event->packet);

	                    break;

	                case ENET_EVENT_TYPE_DISCONNECT:
	                    printf ("%s disconnected.\n", event->peer -> data);
	                    /* Reset the peer's client information. */
	                    event->peer -> data = NULL;
	                    break;
	            }
                //check event,valid event should push list
                //TODO 
	        }
	    }
}

void udp_server::run(){
    bool rst = loop();
}

/*
 * udpserver.cpp
 *
 *  Created on: 2018Äê1ÔÂ11ÈÕ
 *      Author: user
 */

#include "udpserver.h"
#include "netrequestmgr.h"

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
        printf("start udpserver failed!\n");
		return false;
	}
    printf("start udpserver successed!\n");
	return true;
}

bool udp_server::loop(){
	  ENetEvent *event = new ENetEvent();
	    /* Wait up to 1000 milliseconds for an event. */
	    while(m_bRun){
	        //printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
	        while (enet_host_service (m_pServer, event, 10) > 0)
	        {
	            //printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
	            switch (event->type)
	            {
	            	//build gameserver event,send to logic thread
	                case ENET_EVENT_TYPE_CONNECT:
                        char ip_str[24];
                        enet_address_get_host_ip(&(event->peer->address),ip_str,24);
                        net_request_mgr::Instance()->push_conn_event(event->peer->connectID,
                                event->peer->address.host,
                                event->peer->address.port);
	                    printf ("A new client connected from %s:%u.\n",
                                ip_str,
	                            event->peer -> address.port);
	                    break;
	                case ENET_EVENT_TYPE_RECEIVE:
                        net_request_mgr::Instance()->push_recv_event(event->peer->connectID,
                                (char*)event->packet->data,
                                event->packet->dataLength
                                );
	                    enet_packet_destroy (event->packet);
	                    break;

	                case ENET_EVENT_TYPE_DISCONNECT:
                        //net_request_mgr::Instance()->push_disconn_event();
	                    printf ("%s disconnected.\n", event->peer -> data);
	                    /* Reset the peer's client information. */
	                    event->peer -> data = NULL;
	                    break;
	            }
                //check event,valid event should push list
                //TODO 
	        }
	    }
        return true;
}

void udp_server::run(){
    m_bRun = true;
    loop();
}

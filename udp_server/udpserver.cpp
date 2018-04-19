/*
 * udpserver.cpp
 *
 *  Created on: 2018Äê1ÔÂ11ÈÕ
 *      Author: user
 */

#include "udpserver.h"
#include "netrequestmgr.h"
#include "serverpch.h"

INSTANCE_SINGLETON(udp_reactor);

udp_reactor::udp_reactor() {
	m_bRun = false;
}

udp_reactor::~udp_reactor() {
	enet_host_destroy(m_pServer);
}

bool udp_reactor::init(std::string str_ip,e_uint32 u_port,e_uint32 u_max_online)
{
    enet_address_set_host (&_address, str_ip.c_str());

	_address.port = u_port;
	m_pServer = enet_host_create (& _address /* the address to bind the server host to */,
			u_max_online      /* allow up to 32 clients and/or outgoing connections */,
			2      /* allow up to 2 channels to be used, 0 and 1 */,
			0      /* assume any amount of incoming bandwidth */,
			0      /* assume any amount of outgoing bandwidth */);
	if (m_pServer == NULL)
	{
        LOG(INFO)<<"start udpserver failed!\n";
		return false;
	}
    LOG(INFO)<<"start udpserver successed!\n";
	return true;
}

bool udp_reactor::loop(){
        ENetEvent *event = new ENetEvent();
	    while(m_bRun){
            net_request_mgr::Instance()->process_out_event(300);
            e_uint32 count = 0;
	        while ((enet_host_service (m_pServer, event, 5) > 0))
	        {
                if(count++ > 200)
                    break;
	            switch (event->type)
	            {
	                case ENET_EVENT_TYPE_CONNECT:
                        char ip_str[24] ;
                        memset(ip_str,0,sizeof(ip_str));
                        enet_address_get_host_ip(&(event->peer->address),ip_str,24);
                        net_request_mgr::Instance()->push_conn_event(event->peer->connectID,
                                event->peer->address.host,
                                event->peer->address.port);
	                    LOG(INFO)<<"New Connection  reach!"; 
	                    break;
	                case ENET_EVENT_TYPE_RECEIVE:
                        net_request_mgr::Instance()->push_recv_event(event->peer->connectID,
                                (char*)event->packet->data, event->packet->dataLength
                                );
	                    enet_packet_destroy (event->packet);
	                    break;

	                case ENET_EVENT_TYPE_DISCONNECT:
                        net_request_mgr::Instance()->push_disconn_event(event->peer->connectID,
                                event->peer->address.host,
                                event->peer->address.port);
	                    event->peer -> data = NULL;
	                    break;
                    defalut:
                        break;
	            }
                //check event,valid event should push list
                //TODO 
	        }
	    }
        delete event;
        return true;
}

void udp_reactor::run(){
    m_bRun = true;
    loop();
}

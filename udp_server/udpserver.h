/*
 * udpserver.h
 *
 *  Created on: 2018Äê1ÔÂ11ÈÕ
 *      Author: user
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "serverpch.h"

class udp_server {
public:
	udp_server();
	virtual ~udp_server();
	bool init(std::string ,uint32_t );
	bool loop();

protected:
    ENetAddress _address;
    ENetHost * m_pServer;
    bool		m_bRun;
};

#endif /* UDPSERVER_H_ */

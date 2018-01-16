/*
 * udpserver.h
 *
 *  Created on: 2018Äê1ÔÂ11ÈÕ
 *      Author: user
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "serverpch.h"
#include "thread.h"
#include "singleton.h"
#include "queue.h"

class udp_server:public thread {
//    DECLARE_SINGLETON(udp_server);
public:
	udp_server();
	virtual ~udp_server();
	bool init(std::string ,e_uint32,e_uint32);
	bool loop();
    void run();

protected:
    ENetAddress _address;
    ENetHost * m_pServer;
    bool		m_bRun;
};

#endif /* UDPSERVER_H_ */

/*
 * udpserver.h
 *
 *  Created on: 2018��1��11��
 *      Author: user
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "serverpch.h"
#include "thread.h"
#include "singleton.h"
#include "queue.h"
#include <enet/enet.h>

class udp_reactor:public thread {
    DECLARE_SINGLETON(udp_reactor);
public:
	udp_reactor();
	virtual ~udp_reactor();
	bool init(std::string ,e_uint32,e_uint32);
	bool loop();
    void run();
    ENetPeer* get_peer(e_uint32 uConnID){
        ENetPeer* peer = enet_host_get_peer(m_pServer,uConnID);
        return peer;
    };
    void stop(){
        m_bRun = false;
    }

protected:
    ENetAddress _address;
    ENetHost * m_pServer;
    bool		m_bRun;
};

#endif /* UDPSERVER_H_ */

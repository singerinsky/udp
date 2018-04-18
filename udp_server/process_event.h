#ifndef _PROCESS_EVENT_H_
#define _PROCESS_EVENT_H_

#include "serverpch.h"

//处理udp产生的event
void process_udp_event(e_uint32 uMaxProcessNum);
//处理tcp产生的event
void process_tcp_event(int process_num);

void process_all_event(e_uint32 uMaxProcessNum);


#endif

#include <iostream>
#include <stdio.h>
#include <enet/enet.h>
#include "udpserver.h"

bool create_server(){

    ENetAddress address;
    ENetHost * server;
    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */
    //address.host = ENET_HOST_ANY;
    enet_address_set_host (&address, "127.0.0.1"); 
    /* Bind the server to port 1234. */
    address.port = 1234;
    server = enet_host_create (& address /* the address to bind the server host to */, 
            2000      /* allow up to 32 clients and/or outgoing connections */,
            2      /* allow up to 2 channels to be used, 0 and 1 */,
            0      /* assume any amount of incoming bandwidth */,
            0      /* assume any amount of outgoing bandwidth */);
    if (server == NULL)
    {
        fprintf (stderr, 
                "An error occurred while trying to create an ENet server host.\n");
        return false;
    }
    ENetEvent event;
    /* Wait up to 1000 milliseconds for an event. */
    while(true){
        //printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
        while (enet_host_service (server, & event, 1) >= 0)
        {
            //printf("loop enet :%u=%u\n",(uint32_t)time(NULL),enet_time_get());
            switch (event.type)
            {
                case ENET_EVENT_TYPE_CONNECT:
                    printf ("A new client connected from %x:%u.\n", 
                            event.peer -> address.host,
                            event.peer -> address.port);
                    /* Store any relevant client information here. */
                     //snprintf(name,10,"%d",111);
                     //event.peer -> data = (void*)name;//(void*)"Client information";
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                            event.packet -> dataLength,
                            event.packet -> data,
                            event.peer -> data,
                            event.channelID);
                    /* Clean up the packet now that we're done using it. */
                    enet_packet_destroy (event.packet);

                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    printf ("%s disconnected.\n", event.peer -> data);
                    /* Reset the peer's client information. */
                    event.peer -> data = NULL;
                    break;
            }
        }
    }
    enet_host_destroy(server);
    return true;
}

int main(){
    if(udp_server::CreateInstance() == false){
        printf("error of create Instance!\n");
    }
    udp_server* pServer = udp_server::Instance();
    pServer->init("0.0.0.0",9090,1000);
    pServer->create();
    while(true){
        usleep(1000); 
    }
    /*
    if (enet_initialize () != 0)
    {
        printf ("An error occurred while initializing ENet.\n");
        return -1;
    }
    create_server();
    */
    atexit(enet_deinitialize);
    return 0;
}

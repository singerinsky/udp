#include <iostream>
#include <stdio.h>
#include <enet/enet.h>
#include <string.h>

bool create_client(){

    ENetHost * client;
    client = enet_host_create (NULL /* the address to bind the server host to */, 
            1/* allow up to 32 clients and/or outgoing connections */,
            2      /* allow up to 2 channels to be used, 0 and 1 */,
            0      /* assume any amount of incoming bandwidth */,
            0      /* assume any amount of outgoing bandwidth */);
    if (client == NULL)
    {
        fprintf (stderr, 
                "An error occurred while trying to create an ENet server host.\n");
        return false;
    }

    ENetAddress address;
    ENetEvent event;
    ENetPeer *peer;
    /* Connect to some.server.net:1234. */
    enet_address_set_host (&address, "localhost");
    address.port = 1234;
    /* Initiate the connection, allocating the two channels 0 and 1. */
    peer = enet_host_connect (client, & address, 2, 0);    
    if (peer == NULL)
    {
        fprintf (stderr, 
                "No available peers for initiating an ENet connection.\n");
        exit (EXIT_FAILURE);
    }
    /* Wait up to 5 seconds for the connection attempt to succeed. */
    if (enet_host_service (client, & event, 5000) > 0 &&
            event.type == ENET_EVENT_TYPE_CONNECT)
    {

        enet_host_flush (client); //必须使用这个函数或是enet_host_service来使数据发出去
        while(true){
            ENetPacket *packet1=enet_packet_create(NULL,13,ENET_PACKET_FLAG_RELIABLE); //创建包
            memcpy((char*)packet1->data,"Hello,World!",13);
            enet_peer_send(peer,0,packet1);
            enet_host_flush (client); //必须使用这个函数或是enet_host_service来使数据发出去
            sleep(1);

        }
        
    }
    else
    {
        /* Either the 5 seconds are up or a disconnect event was */
        /* received. Reset the peer in the event the 5 seconds   */
        /* had run out without any significant event.            */
        enet_peer_reset (peer);
        puts ("Connection to some.server.net:1234 failed.");
    }
    enet_host_destroy(client);
    return true;
}

int main(){
    if (enet_initialize () != 0)
    {
        printf ("An error occurred while initializing ENet.\n");
        return -1;
    }
    create_client();
    atexit(enet_deinitialize);
    return 0;
}

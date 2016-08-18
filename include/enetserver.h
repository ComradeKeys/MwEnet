#pragma once
/**
 * @file   enetserver.h
 * @Author Brigham Keys (bkeys@gnu.org)
 * @todo   Stop connection which violates the protocol. in InternalPacket recieve
 * 
 * Derived class that has the networking components and is usable. It
 * Also serves as an example of what an implementation of all the 
 * pure virtual functions look like
 */

#include "enetnetwork.h"
#include "server.h"

#include <thread>
#include <mutex>
#include <condition_variable>

namespace mw {

class EnetServer : public EnetNetwork, public Server {
public:
    EnetServer(int port, ServerInterface &serverInterface); //not < Creates an inactive server and binds it to a port
    ~EnetServer();

    EnetServer(const EnetServer &) = delete; //not < copy constructor
    EnetServer &operator=(const EnetServer &) = delete;

    void serverPushToSendBuffer(const Packet &packet, PacketType type, int toId) override; //not < Adds a packet to the send buffer, which then gets send off in the next frame, you can additionally give it the ID of the client sending the packet

    void serverPushToSendBuffer(const Packet &packet, PacketType type) override;  //not < Adds a packet to the send buffer, which then gets send off in the next frame, you can additionally give it the ID of the client sending the packet

    void start() override; //not < Creates a host, sets the state to active, removes any old remaining packets.

    void stop() override; //not < Changes status to disconnecting, disconnects all peers from network.

protected:
    void update(); //not < Handles the event loop for ENet which involves receiving and sending packets, accepting new connections.

    InternalPacket receive(ENetEvent eNetEvent) override; //not < Recieves an ENet packet and converts it into an InternalPacket

private:
    typedef std::pair<ENetPeer *, int> Pair; //not < first: Peer second: id.

    // Sends connectInfo to new connected client. Client is assigned
    // the number id.
    // char type = |CONNECT_INFO
    // char id   = |id
    // char id1  = |?
     //		...
    // char idN  = |?
    void sendConnectInfoToPeers(const std::vector<Pair> &peers) const;

    int currentId_; //not < The id to be assigned to the next connected client.
    std::vector<Pair> peers_; //not < container for information about all connected peers
    ENetAddress address_; //not < Address of the server on the network
    ENetHost *server_; //not < ENet server host

    std::thread thread_; //not < Thread for networking events
    ServerInterface &serverInterface_; //not < Server interface that handles server events inside of the update function
};

} // Namespace mw.

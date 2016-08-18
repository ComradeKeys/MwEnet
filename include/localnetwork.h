#pragma once
/**
 * @file   localnetwork.h
 * @Author Brigham Keys (bkeys@gnu.org)
 * 
 * Class that handles local connections
 */

#include "network.h"
#include "server.h"

#include <queue>

namespace mw {

class LocalNetwork : public Network, public Server {
public:

  /*not 
   * \brief Activates the network interfaces and creates a non active status
   */
    LocalNetwork(ServerInterface &serverFilter);

    /*not 
     * \brief Sends a packet to the send buffer
     * Adds a packet to the send buffer, which then gets send off in the next
     * frame, you can additionally give it the ID of the client sending the packet
     */
    void pushToSendBuffer(const Packet &packet, PacketType type, int toId) override;

    /*not 
     * \brief Adds a packet to the send buffer, which then gets send off
     * in the next frame, you can additionally give it the ID of the
     * client sending the packet. Send data to receiveBuffer. Send data
     * through serverfilter (if there is one).
     */
    void pushToSendBuffer(const Packet &packet, PacketType type) override;

    
    int pullFromReceiveBuffer(Packet &packet) override; //not < Receives data from server.

    /*not 
     * \brief Informs the server to broadcast a packet to a specified peer
     * 
     * Adds a packet to the send buffer, which then gets send off
     * in the next frame, you can additionally give it the ID of the client
     * sending the packet, this function tells the server to broadcast the
     * packet to everyone on the network
     */
    void serverPushToSendBuffer(const Packet &packet, Network::PacketType type, int toId) override;

    /*not 
     * \brief Informs the server to broadcast a packet
     * 
     * Adds a packet to the send buffer, which then gets send off
     * in the next frame, you can additionally give it the ID of the client
     * sending the packet, this function tells the server to broadcast the
     * packet to everyone on the network
     */
    void serverPushToSendBuffer(const Packet &packet, Network::PacketType type) override;

    void start() override; //not < sets the localnetwork status to active

    void stop() override; //not < sets the localnetwork status to inactive

    
    int getId() const override; //not < Return the same id as server id.

    Status getStatus() const override; //not < Returns status of peer

private:
    void pushToSendBuffer(const Packet &packet, Network::PacketType type, int toId, bool server); //not < Sends a packet to the send buffer

    /*
     * \todo Probably should be the same copy as the internal packet, if so 
     * then we need to make a private header for it
     */
    struct Data {
        Data() {
        }

        Data(const Packet &packet, bool server) : packet_(packet), server_(server) {
        }

        Packet packet_; 
        bool server_;
    };

    Status status_; //not < Status of peer on the network

    std::queue<Data> buffer_; //not < Order of events
    ServerInterface &serverFilter_; //not < Server interface
};

} // Namespace mw.

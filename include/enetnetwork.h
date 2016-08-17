#pragma once
/**
 * @file   enetnetwork.h
 * @Author Brigham Keys (bkeys@gnu.org)
 * @todo   Fix that packages cant be sent before a id is assigned to the client.
 * 
 * Uses enet for implementing usefull parts of the Network interface.
 */

#include "network.h"
#include "packet.h"

#include <enet/enet.h>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace mw {

class EnetNetwork : public Network {
public:
    EnetNetwork(); //!< Increments the number of instances and calls enet_initialize
    virtual ~EnetNetwork();

    void pushToSendBuffer(const Packet &packet, PacketType type, int toId) override final; //!<  Copy buffer to send buffer. Assign the correct sender id.

    void pushToSendBuffer(const Packet &packet, PacketType type) override final; //!< Push packet to buffer to be sent, without ID it will send to all clients so basically a broadcast

    int pullFromReceiveBuffer(Packet &data) override final; //!< Pull packet from recieving buffer

    int getId() const override final; //!< gets ID of the peer

    Status getStatus() const override final; //!< status of the peer on the network

protected:
    enum EnetConnectionType {
        CONNECT_INFO = 0,
        PACKET = 1
    };

    class InternalPacket {
    public:
        InternalPacket(Packet packet, int id, PacketType type) {
            data_ = packet;
            fromId_ = id;
            type_ = type;
            toId_ = 0;
        }

        InternalPacket(Packet packet, int id, PacketType type, int toId) {
            data_ = packet;
            fromId_ = id;
            type_ = type;
            toId_ = toId;
        }

        Packet data_; //!< Information stored in the internal packet
        int fromId_; //!< ID of peer the packet came from
        PacketType type_; //!< Whether the packet is reliable or unreliable
        int toId_; //!< ID of client the packet is being sent to
    };

    virtual InternalPacket receive(ENetEvent eNetEvent) = 0;

    // Sends data packet from client width the corresponding id.
    // 0 char type    |	EnetNetwork type.
    // 1 char id      |
    // 2 char data[N] |
    static ENetPacket *createEnetPacket(const Packet &dataPacket, char fromId, PacketType type); // Unpacks the Packet's data and returns the constructed ENet packet

    std::queue<InternalPacket> sendPackets_;
    std::queue<InternalPacket> receivePackets_;

    int id_; //!< Sets the fromId_ of packets being sent
    Status status_;
    mutable std::mutex mutex_; //!< private mutex to handle order of operations regarding threading
    std::condition_variable condition_; //!< Helps handle threading

    static int nbrOfInstances; //!< How many ENet networks are currently spawned
};

} // Namespace mw.

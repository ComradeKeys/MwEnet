#pragma once
/**
 * @file   localnetwork.h
 * @Author Brigham Keys (bkeys@gnu.org)
 * 
 * Class that handles local connections
 */

#include "packet.h"
#include "network.h"

#include <vector>

namespace mw {

class ServerInterface {
public:

  virtual void receiveToServer(const Packet &packet, int clientId) = 0; //!< Specifies how to process incoming packets
  virtual bool connectToServer(int clientId) = 0; //!< Specifies how to connect to the server
    virtual void disconnectToServer(int clientId) = 0; //!< Specifies how to disconnect to the server
};

/*!
 * This class works as a server.
 * The server is responsible to give all client a unique value and
 * serves as a relay station which relays all data to and from clients.
 */
class Server {
public:

    virtual void serverPushToSendBuffer(const Packet &packet, Network::PacketType type, int toId) = 0; //!< Specifies how to send a packet to a peer with the ID

    virtual void serverPushToSendBuffer(const Packet &packet, Network::PacketType type) = 0; //!< Specifies how to broadcast a packet
};

} // Namespace mw.

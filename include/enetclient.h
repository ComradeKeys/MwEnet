#pragma once

#include "enetnetwork.h"

#include <string>
#include <vector>
#include <thread>
#include <mutex>

namespace mw {

/**
 * \brief A client network entity.
 * \details A network entity that sends packets to a server.
 */
class EnetClient : public EnetNetwork {
public:
    /**
     * \brief Initializes the client.
     * \details starts up the client with a given IP and port number.
     * @param[in] port The server's port to which the client should connect to.
     * @param[in] ip An IP address to which the clien tshould connect.
     */
    EnetClient(int port, std::string ip, int id);
    ~EnetClient();

    /**
     * \brief Connects to the server.
     */
    void start() override;

    /**
     * \brief Disconnects from the server.
     */
    void stop() override;

protected:
    /**
     * \brief Threaded function receiving information from the server.
     */
    void update();

    /**
     * \brief Waits to receive a packet from peer.
     * @param[in] eNetEvent Event to receive.
     * \returns Returns a packet recieved from peer.
     */
    InternalPacket receive(ENetEvent eNetEvent) override;

private:
    std::vector<int> ids_;

    ENetPeer *peer_;
    ENetAddress address_;
    ENetHost *client_;
    std::thread thread_;
};

} // Namespace mw.

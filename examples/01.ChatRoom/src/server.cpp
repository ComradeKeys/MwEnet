#include <iostream>
#include <string>
#include <enetserver.h>
#include <server.h>
#include <packet.h>
#include <network.h>
#include <vector>

std::vector<mw::Packet> msgs;

class ChatInterface : public mw::ServerInterface {
    void receiveToServer(const mw::Packet &packet, int clientId) {
        msgs.push_back(packet);
    }

    bool connectToServer(int clientId) {
        std::cout << "The server got a new connection at " << clientId << std::endl;
	return true;
    }

    void disconnectToServer(int clientId) {
        puts("Client disconnected");
    }
};

int main(int argc, char *argv[]) {

    ChatInterface interface;
    mw::EnetServer server(12345, interface);
    server.start();
    std::string welcomeMessage = "Welcome to the chat room example!\n";
    mw::Packet packet(welcomeMessage.c_str(), welcomeMessage.size());
    while(true) {
        if(not msgs.empty()) {
            server.serverPushToSendBuffer(msgs.front(), mw::Network::RELIABLE);
            msgs.erase(msgs.begin());
        }
    }

    server.stop();

    return 0;
}

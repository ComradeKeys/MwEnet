#include <iostream>
#include <string>
#include <enetserver.h>
#include <server.h>
#include <packet.h>

class ChatInterface : public mw::ServerInterface {
  void receiveToServer(const mw::Packet& packet, int clientId) {

  }

  bool connectToServer(int clientId) {

  }

  void disconnectToServer(int clientId) {

  }
};

int main(int argc, char *argv[]) {

  std::string myName = "Brigham";
  mw::Packet packet(myName.c_str(), myName.size());
  ChatInterface interface;
  mw::EnetServer server(1234, interface);
  server.start();
  while(true) {
    server.serverPushToSendBuffer(packet, mw::Network::RELIABLE);
  }

  server.stop();

  return 0;
}

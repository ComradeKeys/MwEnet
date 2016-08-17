#include <iostream>
#include <enetclient.h>
#include <server.h>

class ChatInterface : public mw::ServerInterface {
  void receiveToServer(const mw::Packet& packet, int clientId) {

  }

  bool connectToServer(int clientId) {

  }

  void disconnectToServer(int clientId) {

  }
};

int main(int argc, char *argv[]) {

  ChatInterface interface;
  mw::EnetClient client(1234, "localhost");
  client.start();

  for(int i = 0; i < 100000; ++i) {
    interface.receiveToServer();
  }

  client.stop();
  return 0;
}

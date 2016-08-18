#include <iostream>
#include <enetclient.h>
#include <network.h>
#include <packet.h>
#include <thread>
#include <time.h>
#include <stdlib.h>
#include <math.h>

bool run;

int main(int argc, char *argv[]) {
  srand(time(NULL));
    std::string ip = "localhost";
    int port = 12345;
    int id   = abs(rand() % 50);
    std::cout << "ID should be " << id << std::endl;
    mw::EnetClient client(port, ip, id);

    run = true;
    client.start();

    do {
        // Send
        std::string msg;
        std::cin >> msg;
        if(msg == "quit" or msg == "exit") {
            run = false;
            break;
        }
        mw::Packet pkt(msg.c_str(), sizeof(char) * msg.length());
        client.pushToSendBuffer(pkt, mw::Network::RELIABLE);

        // Receive
        while(client.pullFromReceiveBuffer(pkt) not_eq 0) {
            std::cout << "Msg: " << pkt.getData() << std::endl;
        }
    } while(run);

    client.stop();

    return 0;
}

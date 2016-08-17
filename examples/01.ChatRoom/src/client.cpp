#include <iostream>
#include <enetclient.h>
#include <network.h>
#include <packet.h>
#include <thread>

bool run;

int main(int argc, char *argv[]) {
    std::string ip;
    int port;
    std::cout << "IP: ";
    std::cin >> ip;
    std::cout << "Port: ";
    std::cin >> port;

    mw::EnetClient client(port, ip);

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

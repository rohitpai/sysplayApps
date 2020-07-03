#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5555");
    usleep(1000000);

    for(int n = 0; n < 3; n++) {
        zmq::message_t env1(1);
        memcpy(env1.data(), "A", 1);
        std::string msg1_str = "Hello A";
        zmq::message_t msg1(msg1_str.size());
        memcpy(msg1.data(), msg1_str.c_str(), msg1_str.size());
        std::cout << "Sending '" << msg1_str << "' on topic A" << std::endl;
        publisher.send(env1, ZMQ_SNDMORE);
        publisher.send(msg1);

        zmq::message_t env2(1);
        memcpy(env2.data(), "B", 1);
        std::string msg2_str = "Hello B";
        zmq::message_t msg2(msg2_str.size());
        memcpy(msg2.data(), msg2_str.c_str(), msg2_str.size());
        std::cout << "Sending '" << msg2_str << "' on topic B" << std::endl;
        publisher.send(env2, ZMQ_SNDMORE);
        publisher.send(msg2);

        usleep(1000000);
    }
    return 0;
}
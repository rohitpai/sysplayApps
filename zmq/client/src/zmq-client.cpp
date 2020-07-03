#include <zmq.hpp>
#include <string>
#include <iostream>

int main()
{
    zmq::context_t context(1);
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5555");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "B", 1);

    while(true)
    {
        zmq::message_t env;
        subscriber.recv(&env);
        std::string env_str = std::string(static_cast<char*>(env.data()), env.size());
        std::cout << "Received envelope '" << env_str << "'" << std::endl;

        zmq::message_t msg;
        subscriber.recv(&msg);
        std::string msg_str = std::string(static_cast<char*>(msg.data()), msg.size());
        std::cout << "Received '" << msg_str << "'" << std::endl;
    }
    return 0;
}
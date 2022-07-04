#include "socket.hpp"

#ifndef CLIENT_H
#define CLIENT_H

class client
{
    public:
        client() : running(false) { }
        void inputLoop();
        bool running;
    private:
        socket _socket;
};

#endif
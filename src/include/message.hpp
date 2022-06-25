#ifndef MESS_H
#define MESS_H

#include "user.hpp"
#include <string>

class message
{
    public:
        message();
        std::string Text;
        user Author;
};

#endif
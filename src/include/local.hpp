#ifndef LOCAL_H
#define LOCAL_H

#include "user.hpp"
#include "guild.hpp"
#include <string>

class local
{
    public:
        local(std::string username);
        static std::string Username;
};
bool InitialLogin();

#endif
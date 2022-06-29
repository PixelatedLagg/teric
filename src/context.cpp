#include <string>
#include "include/context.hpp"

context::context(std::string username, std::string channel, std::string guild)
{
    Username = new std::string(username);
    Channel = new std::string(channel);
    Guild = new std::string(guild);
}

bool InitialLogin()
{
    return true;
}
#ifndef LOCAL_H
#define LOCAL_H

#include "user.hpp"
#include "guild.hpp"
#include <string>

struct context
{
    public:
        context(std::string username, std::string channel, std::string guild);
        std::string* Username;
        std::string* Channel;
        std::string* Guild;
        unsigned long* UserID;
        unsigned long* ChannelID;
        unsigned long* GuildID;
};
bool InitialLogin();

#endif
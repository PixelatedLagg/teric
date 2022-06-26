#ifndef USER_H
#define USER_H

#include <string>

class user
{
    public:
        user(std::string username, int tag, std::string password);
        std::string Username;
        std::string Password;
        int Tag;
        unsigned long ID;
        int Color;
};

#endif
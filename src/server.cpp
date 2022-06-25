#include "include/server.hpp"
#include "include/user.hpp"
#include <sstream>
#include <string>

unsigned long GenerateID(user* user)
{
    std::stringstream stream;
    for (auto i : user->Username)
    {
        stream << (int)i - 48;
    }
    stream << user->Tag;
    user->ID = std::stoi(stream.str());
}
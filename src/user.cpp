#include "include/user.hpp"
#include <string>
#include <sstream>
#include <random>

user::user(std::string username, int tag, std::string password)
{
    /*Username = username;
    Tag = tag;
    Password = password;
    std::stringstream stream;
    for (auto i : user->Username)
    {
        stream << (int)i - 48;
    }
    stream << Tag;
    ID = std::stoi(stream.str());
    time_t nTime;
    srand((unsigned) time(&nTime));*/


    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 8);
    distr(gen);
}
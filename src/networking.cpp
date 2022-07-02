#include "include/networking.hpp"
#include <string>
#include <iostream>

//GET
bool UsernameIsTaken(std::string username)
{
    return false;
}
int TryLogin(std::string username, std::string password)
{
    /*char p_request[100] = {0};
    char p_resourcepath[]="login?=";
    char p_hostaddress[]="www.cplusplus.com";
    sprintf(p_request, "GET /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: text/plain\r\n\r\n", p_resourcepath, p_hostaddress);
    std::cout << "Created Get Request is as follows:"<<"\n";
    std::cout << p_request;*/
    return 0;
}
void PrintUsersInChannel(unsigned long guildid, unsigned long channelid)
{

}

//POST
void CreateUser(std::string username, std::string password)
{

}
void Logoff()
{

}
void LoginChannel()
{

}
void LogoffChannel()
{

}
void JoinGuild()
{

}
void LeaveGuild()
{

}
void SendMessageToChannel(unsigned long guildid, unsigned long channelid, std::string message, std::string username)
{

}
void DeleteUser()
{

}
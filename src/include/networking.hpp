#ifndef NETW_H
#define NETW_H

#include "message.hpp"
#include "guild.hpp"
#include <vector>
#include <string>


//GET
bool UsernameIsTaken(std::string username);
int TryLogin(std::string username, std::string password);
void PrintUsersInChanel(unsigned long guildid, unsigned long channelid);

//POST
void CreateUser(std::string username, std::string password);
void Logoff();
void LoginChannel();
void LogoffChannel();
void JoinGuild();
void LeaveGuild();
void SendMessage(unsigned long guildid, unsigned long channelid, std::string message, std::string username);
void DeleteUser();

#endif
#ifndef NETW_H
#define NETW_H

#include "message.hpp"
#include "guild.hpp"
#include <vector>
#include <string>

bool UsernameIsTaken(std::string username);
bool TryLogin(std::string username, std::string password);
void CreateUser(std::string username, std::string password);
void Login(std::string username, std::string password);
void Logoff();
void LoginChannel();
void LogoffChannel();
void JoinGuild();
void LeaveGuild();
void SendMessageToChannel(unsigned long guildid, unsigned long channelid, std::string message, std::string username);
void SendMessageToUser();
void SendFriendRequest();
void DeleteUser();

//std::string[] UsersInChannel();

#endif
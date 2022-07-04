#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define WINDOWS
#endif
#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include "include/client.hpp"
#include "include/colorconsole.hpp"

time_t* timeseed = new time_t();
int* timestamp = new int();
struct tm* temp = new tm();

bool IsValidInt(const std::string& s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    {
        return false;
    }
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

void PrintTime()
{
    if (temp->tm_min < 10)
    {
        std::cout << dye::grey(std::to_string(temp->tm_hour) + ":0" + std::to_string(temp->tm_min) + ' ');
    }
    else
    {
        std::cout << dye::grey(std::to_string(temp->tm_hour) + ':' + std::to_string(temp->tm_min) + ' ');
    }
}
void TimeStamp()
{
    time(timeseed);
    if (time(0) / 60 > *timestamp)
    {
        *timestamp = time(0) / 60;
        temp = localtime(timeseed);
        PrintTime();
    }
}
void InputReplace(std::string input, std::string username)
{
    std::cout << "\x1b[1A\x1b[2K";
    TimeStamp();
    std::cout << dye::blue(username) << ": " << input << "\n";
}
int main(int argc, char* argv[])
{
    #ifdef WINDOWS
    system(" ");
    #endif
    SetConsoleTitleA("teric v0.1");
    time(timeseed);
    *timestamp = time(0) / 60;
    temp = localtime(timeseed);
    PrintTime();
    std::cout << "Running teric v0.1\n";

    //client _client;
    //std::thread inputLoop(&client::inputLoop, &_client);
}
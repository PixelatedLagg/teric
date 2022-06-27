#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include "windows.h"
#include "include/user.hpp"
#include "include/local.hpp"
#include "include/networking.hpp"
#include "include/colorconsole.hpp"

time_t* globalTime = new time_t();
struct tm* timeStamp = new tm();

void PrintColored(int color, std::string text)
{
    switch (color)
    {
        case 1: //red
            std::cout << dye::red(text);
            break;
        case 2: //yellow
            std::cout << dye::yellow(text);
            break;
        case 3: //green
            std::cout << dye::green(text);
            break;
        case 4: //aqua
            std::cout << dye::aqua(text);
            break;
        case 5: //blue
            std::cout << dye::blue(text);
            break;
        case 6: //purple
            std::cout << dye::purple(text);
            break;
        case 7: //black on gray
            std::cout << dye::black_on_grey(text);
            break;
    }
}
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
bool TimeIsGreater(tm* tm1, tm* tm2)
{
    if (tm1->tm_min > tm2->tm_min)
    {
        return true;
    }
    else if (tm1->tm_hour > tm2->tm_hour)
    {
        return true;
    }
    else if (tm1->tm_yday > tm2->tm_yday)
    {
        return true;
    }
    return false;
}
void PrintTime()
{
    if (timeStamp->tm_min < 10)
    {
        std::cout << dye::grey(std::to_string(timeStamp->tm_hour) + ":0" + std::to_string(timeStamp->tm_min) + ' ');
    }
    else
    {
        std::cout << dye::grey(std::to_string(timeStamp->tm_hour) + ':' + std::to_string(timeStamp->tm_min) + ' ');
    }
}
void TimeStamp()
{
    time(globalTime);
    if (TimeIsGreater(localtime(globalTime), timeStamp))
    {
        timeStamp = localtime(globalTime);
        PrintTime();
    }
}
int main()
{
    time(globalTime);
    timeStamp = localtime(globalTime);
    local l("user");
    PrintTime();
    if (InitialLogin())
    {
        std::cout << "Greetings and welcome to teric!\n";
        TimeStamp();
        std::cout << "Do you already have an account? [y/n]\n";
        TimeStamp();
        std::cout << dye::blue(l.Username) << ": ";
        std::string input;
        std::cin >> input;
        while (true)
        {
            if (input != "y" && input != "n")
            {
                TimeStamp();
                std::cout << dye::red("Invalid input.\n") << dye::blue(l.Username) << ": ";
                std::cin >> input;
            }
            else
            {
                break;
            }
        }
        if (input == "y")
        {
            std::string username;
            std::string password;
            TimeStamp();
            std::cout << "Enter your full username. Example: CoolGuy#1849\n" << dye::blue(l.Username) << ": ";
            std::cin >> username;
            TimeStamp();
            std::cout << "Enter your password.\n" << dye::blue(l.Username) << ": ";
            std::cin >> password;
            while (true)
            {
                if (!TryLogin(username, password))
                {
                    TimeStamp();
                    std::cout << dye::red("Incorrect username and/or password.") << "\nEnter your full username. Example: CoolGuy#1849\n" << dye::blue(l.Username) << ": ";
                    std::cin >> username;
                    TimeStamp();
                    std::cout << "Enter your password.\n" << dye::blue(l.Username) << ": ";
                    std::cin >> password;
                }
                else
                {
                    break;
                }
            }
            Login(username, password);
            std::cout.flush();
        }
        else
        {
            std::string username;
            std::string tag;
            std::string password;
            TimeStamp();
            std::cout << "Create your username.\n" << dye::blue(l.Username) << ": ";
            std::cin >> username;
            TimeStamp();
            std::cout << "Create your tag. " << dye::grey("Example: 8039\n") << dye::blue(l.Username) << ": ";
            std::cin >> tag;
            while (true)
            {
                if (tag.size() != 4 || !IsValidInt(tag))
                {
                    TimeStamp();
                    std::cout << dye::red("Invalid tag.") << "\nCreate your tag. " << dye::grey("Example: 8039\n") << dye::blue(l.Username) << ": ";
                    std::cin >> tag;
                    continue;
                }
                if (UsernameIsTaken(username + "#" + tag))
                {
                    TimeStamp();
                    std::cout << dye::red("Sorry, that username and tag combination is taken.") << "\nCreate your username.\n" << dye::blue(l.Username) << ": ";
                    std::cin >> username;
                    TimeStamp();
                    std::cout << "Create your tag. " << dye::grey("Example: 8039\n") << dye::blue(l.Username) << ": ";
                    std::cin >> tag;
                }
                else
                {
                    break;
                }
            }
            TimeStamp();
            std::cout << "Create a nice and strong password.\n" << dye::blue(l.Username) << ": ";
            std::cin >> password;
            CreateUser(username, password);
            l.Username = username;
            std::cout.flush();
        }
    }
    else
    {
        TimeStamp();
        std::cout << dye::grey("Running Teric v0.1");
        std::string input;
        while (true)
        {
            std::cout << dye::blue(l.Username) << ": ";
            std::cin >> input;
            if (input[0] == '.')
            {
                if (input == ".online")
                {
                    TimeStamp();
                    std::cout << dye::grey("Online in this channel:");
                }
            }
            else
            {

            }
        }
    }
}
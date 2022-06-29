#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include "windows.h"
#include "include/user.hpp"
#include "include/context.hpp"
#include "include/networking.hpp"
#include "include/colorconsole.hpp"

time_t* timeseed = new time_t();
int* timestamp = new int();
struct tm* temp = new tm();

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
int main()
{
    time(timeseed);
    *timestamp = time(0) / 60;
    temp = localtime(timeseed);
    context c("user", "none", "none");
    PrintTime();
    if (InitialLogin())
    {
        std::cout << "Greetings and welcome to teric!\n";
        TimeStamp();
        std::cout << "Do you already have an account? [y/n]\n";
        TimeStamp();
        std::cout << dye::blue(*c.Username) << ": ";
        std::string input;
        std::cin >> input;
        while (true)
        {
            if (input != "y" && input != "n")
            {
                TimeStamp();
                std::cout << dye::red("Invalid input.\n") << dye::blue(*c.Username) << ": ";
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
            std::cout << "Enter your full username. Example: CoolGuy#1849\n" << dye::blue(*c.Username) << ": ";
            std::cin >> username;
            TimeStamp();
            std::cout << "Enter your password.\n" << dye::blue(*c.Username) << ": ";
            std::cin >> password;
            while (true)
            {
                if (!TryLogin(username, password))
                {
                    TimeStamp();
                    std::cout << dye::red("Incorrect username and/or password.") << "\nEnter your full username. Example: CoolGuy#1849\n" << dye::blue(*c.Username) << ": ";
                    std::cin >> username;
                    TimeStamp();
                    std::cout << "Enter your password.\n" << dye::blue(*c.Username) << ": ";
                    std::cin >> password;
                }
                else
                {
                    break;
                }
            }
            Login(username, password);
            std::cout << "\x1B[2J\x1B[H";
        }
        else
        {
            std::string username;
            std::string tag;
            std::string password;
            TimeStamp();
            std::cout << "Create your username.\n" << dye::blue(*c.Username) << ": ";
            std::cin >> username;
            TimeStamp();
            std::cout << "Create your tag. " << dye::grey("Example: 8039\n") << dye::blue(*c.Username) << ": ";
            std::cin >> tag;
            while (true)
            {
                if (tag.size() != 4 || !IsValidInt(tag))
                {
                    TimeStamp();
                    std::cout << dye::red("Invalid tag.") << "\nCreate your tag. " << dye::grey("Example: 8039\n") << dye::blue(*c.Username) << ": ";
                    std::cin >> tag;
                    continue;
                }
                if (UsernameIsTaken(username + "#" + tag))
                {
                    TimeStamp();
                    std::cout << dye::red("Sorry, that username and tag combination is taken.") << "\nCreate your username.\n" << dye::blue(*c.Username) << ": ";
                    std::cin >> username;
                    TimeStamp();
                    std::cout << "Create your tag. " << dye::grey("Example: 8039\n") << dye::blue(*c.Username) << ": ";
                    std::cin >> tag;
                }
                else
                {
                    break;
                }
            }
            TimeStamp();
            std::cout << "Create a nice and strong password.\n" << dye::blue(*c.Username) << ": ";
            std::cin >> password;
            CreateUser(username, password);
            *c.Username = username;
            std::cout << "\x1B[2J\x1B[H";
        }
    }
    PrintTime();
    std::cout << dye::grey("Running Teric v0.1\n");
    std::string input;
    while (true)
    {
        std::cout << dye::blue(*c.Username) << ": ";
        std::cout << "aids!";
        std::getline(std::cin, input);
        if (input != "")
        {
            InputReplace(input, *c.Username);
            if (input[0] == '.')
            {
                if (input == ".online")
                {
                    TimeStamp();
                    std::cout << dye::grey("Online in this channel:\n");
                }
                else if (input == ".current")
                {
                    TimeStamp();
                    std::cout << dye::grey("Channel: " + *c.Channel + "\nGuild: " + *c.Guild + "\n");
                }
                else if (input == ".clear")
                {
                    std::cout << "\x1B[2J\x1B[H";
                    PrintTime();
                    std::cout << dye::grey("Cleared the chat.\n");
                }
                else if (input == ".exit")
                {
                    return 0;
                }
            }
            else
            {
                std::cout << "\n";
            }
        }
    }
}
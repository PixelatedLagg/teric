#include <iostream>
#include <string>
#include "include/user.hpp"
#include "include/server.hpp"
#include "include/local.hpp"
#include "include/networking.hpp"
#include "include/color.hpp"

auto fun = NULL;

int main()
{
    if (InitialLogin())
    {
        std::cout << "Greetings and welcome to teric!\nDo you already have an account? [y/n]\n";
        std::string input;
        std::cin >> input;
        while (true)
        {
            if (input != "y" && input != "n")
            {
                std::cout << "Invalid input.\n";
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
            std::cout << "Enter your full username. Example: CoolGuy#1849\n";
            std::cin >> username;
            std::cout << "Enter your password.\n";
            std::cin >> password;
            while (true)
            {
                if (!TryLogin(username, password))
                {
                    PrintColored(Red, "Incorrect username and/or password.\n");
                    std::cout << "Enter your full username. Example: CoolGuy#1849\n";
                    std::cin >> username;
                    std::cout << "Enter your password.\n";
                    std::cin >> password;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            std::string username;
            int tag;
            std::string password;
            std::cout << "Create your username\n";
            std::cin >> username;
            std::cout << "Create your tag. Example: 8039\n"
            while (true)
            {
                if (UsernameIsTaken(username, tag))
                {
                    std::cout << "Sorry, that username is taken.\nCreate your username. Example: NewCoolGuy#9481\n";
                    std::cin >> username;
                }
                else
                {
                    break;
                }
            }
            std::cout << "Create a nice and strong password.\n";
            std::cin >> password;
            CreateUser(username, password);

        }
    }
}
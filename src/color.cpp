#include "include/color.hpp"
#include "include/colorconsole.hpp"
#include "include/user.hpp"
#include <string>
#include <iostream>

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
        case 8: //black on gray
            std::cout << dye::black_on_grey(text);
            break;
    }
}
void PrintMessage(user user, std::string text)
{
    
}
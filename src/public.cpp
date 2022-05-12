#include "public.h"
#include "draw.h"
#include "CreatSudoku.h"
#include "gotoxy.h"
#include <iostream>

void print_color(int color, std::string str)
{
    switch (color)
    {
    case 1:
        /*red*/
        std::cout << "\033[1;31m" << str << "\033[0m";
        break;
    case 2:
        /*green*/
        std::cout << "\033[1;32m" << str << "\033[0m";
        break;
    case 3:
        /*yellow*/
        std::cout << "\033[1;33m" << str << "\033[0m";
        break;
    case 4:
        /*blue*/
        std::cout << "\033[1;34m" << str << "\033[0m";
        break;
    default:
        std::cout << str;
        break;
    }
}
void print_color(int color, int num)
{
    switch (color)
    {
    case 1:
        /*red*/
        std::cout << "\033[1;31m" << num << "\033[0m";
        break;
    case 2:
        /*green*/
        std::cout << "\033[1;32m" << num << "\033[0m";
        break;
    case 3:
        /*yellow*/
        std::cout << "\033[1;33m" << num << "\033[0m";
        break;
    case 4:
        /*blue*/
        std::cout << "\033[1;34m" << num << "\033[0m";
        break;
    default:
        std::cout << num;
        break;
    }
}

void cls()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
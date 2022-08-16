#include "Utils.h"

void print_color(int color, std::string str)
{
    printf("\033[1;3%dm%s\033[0m",color,str.c_str());
}
void print_color(int color, int num)
{
    printf("\033[1;3%dm%d\033[0m",color,num);
}

void cls()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#if _WIN32
    #include <Windows.h>
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
#else
    #include <cstdio>
    void gotoxy(int x, int y)
    {
        printf ( "%c[%d;%df" ,0x1B,y,x);
    }
#endif
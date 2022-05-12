#include "gotoxy.h"
#if _WIN32
    #include <Windows.h>
    #include <cstdio>
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


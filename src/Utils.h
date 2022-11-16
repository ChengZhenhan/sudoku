#ifndef _SUDOKU_UTILS_H_
#define _SUDOKU_UTILS_H_

#include <cstdio>
#include <string>

void print_color(int color, std::string str);
void print_color(int color, int num);
void cls();
void gotoxy(int x, int y);
#ifdef _WIN32
#include <conio.h>
#else
    #ifdef __linux__
    #include <termio.h>
    #include <cstdio>
    #elif __APPLE__
    #include <termios.h>
    #endif
    char getch();
#endif
#endif
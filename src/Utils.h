#ifndef _SUDOKU_UTILS_H_
#define _SUDOKU_UTILS_H_

#include <cstdio>
#include <string>

void print_color(int color, std::string str);
void print_color(int color, int num);
void cls();
void gotoxy(int x, int y);
#if _WIN32
#include <conio.h>
#else
#if 0
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
namespace linuxRead{
    static struct termios initial_settings, new_settings;
    static int peek_character = -1;
    class linuxRead{
    public:
        linuxRead() {}
        ~linuxRead() {}
        void init_keyboard();
        void close_keyboard();
        int kbhit();
        int readch();
    };
    void linuxRead::init_keyboard() {
        tcgetattr(0,&initial_settings);
        new_settings = initial_settings;
        new_settings.c_lflag |= ICANON;
        new_settings.c_lflag |= ECHO;
        new_settings.c_lflag |= ISIG;
        new_settings.c_cc[VMIN] = 1;
        new_settings.c_cc[VTIME] = 0;
        tcsetattr(0, TCSANOW, &new_settings);
    }
    void linuxRead::close_keyboard() {
        tcsetattr(0, TCSANOW, &initial_settings);
    }
    int linuxRead::kbhit() {
        unsigned char ch;
        int nread;
    
        if (peek_character != -1) return 1;
        new_settings.c_cc[VMIN]=0;
        tcsetattr(0, TCSANOW, &new_settings);
        nread = (int)read(0,&ch,1);
        new_settings.c_cc[VMIN]=1;
        tcsetattr(0, TCSANOW, &new_settings);
        if(nread == 1) 
        {
            peek_character = ch;
            return 1;
        }
        return 0;
    }
    int linuxRead::readch() {
        char ch;
    
        if(peek_character != -1) 
        {
            ch = peek_character;
            peek_character = -1;
            return ch;
        }
        read(0,&ch,1);
        return ch;
    }
}
#endif
// class linuxRead{
// private:
//     static struct termios initial_settings, new_settings;
//     int peek_character = -1;
// public:
//     linuxRead() {}
//     ~linuxRead() {}
//     void init_keyboard();
//     void close_keyboard();
//     int kbhit();
//     int readch();
// };
char getch();
#endif
#endif
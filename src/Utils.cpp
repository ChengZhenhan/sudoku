#include "Utils.h"

void print_color(int color, std::string str) {
    printf("\033[1;3%dm%s\033[0m",color,str.c_str());
}
void print_color(int color, int num) {
    printf("\033[1;3%dm%d\033[0m",color,num);
}

void cls() {
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
    void gotoxy(int x, int y) {
        printf ( "%c[%d;%df" ,0x1B,y,x);
    }
#endif

#if _WIN32
#include <conio.h>
#else
// char getch() {
//     char c;
//     system("stty -echo");  //不回显
//     system("stty -icanon");//设置一次性读完操作，如使用getchar()读操作，不需要按enter
//     c=getchar();
//     system("stty icanon");//取消上面的设置
//     system("stty echo");//回显
//     return c;
// }
char getch() {
    struct termios tmtemp, tm;
    char c;
    int fd = 0;
    if (tcgetattr(fd, &tm) != 0) {
        return -1;
    }
    tmtemp = tm;
    cfmakeraw(&tmtemp);
    if (tcsetattr(fd, TCSANOW, &tmtemp) != 0) {
        return -1;
    }
    c = getchar();
    if (tcsetattr(fd, TCSANOW, &tm) != 0) {
        return 0;
    }
    return c;
}
#endif
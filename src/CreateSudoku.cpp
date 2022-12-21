#include "CreateSudoku.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <time.h>
#include <map>

#if _WIN32
#define GetX(x) (2+4*x)
#define GetY(y) (1+2*y)
#else
#define GetX(x) (3+4*x)
#define GetY(y) (2+2*y)
#endif
void CreateSudoku::load(const std::string& filename) {
    std::ifstream in(filename);
    if(!in.is_open()) {
        print_color(1,"ERROR:File opening failed!");
        return;
    }
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            in >> board[i][j];
            if (board[i][j] == 0) {
                zero++;
            }
        }
    }
    in.close();
}

void CreateSudoku::save(const std::string& filename) {
    std::ofstream out(filename);
    if(!out.is_open()) {
        print_color(1,"ERROR:File opening failed!");
        return;
    }
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            out << board[i][j] << " ";
        }
        out << std::endl;
    }
    out.close();
}

//It can also be exchanged by addition and subtraction
void CreateSudoku::turnrow(int row1, int row2) {
    int temp = 0;
    for(int i = 0;i < 9;i++) {
        temp = board[row1][i];
        board[row1][i] = board[row2][i];
        board[row2][i] = temp;
    }
}

void CreateSudoku::turncol(int col1, int col2) {
    int temp = 0;
    for(int i = 0;i < 9;i++) {
        temp = board[i][col1];
        board[i][col1] = board[i][col2];
        board[i][col2] = temp;
    }
}
bool CreateSudoku::judge() {
    bool t[10] = {false};
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            t[board[i][j]] = true;
        }
        for(int j = 0;j < 9;j++) {
            if(!t[j]) {
                return false;
            }
            t[j] = false;
        }
    }
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            t[board[j][i]] = true;
        }
        for(int j = 0;j < 9;j++) {
            if(!t[j]) {
                return false;
            }
            t[j] = false;
        }
    }
    int x[3] = {0,3,6};
    int y[3] = {0,3,6};
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            for(int k = 0;k < 9;k++) {
                t[board[x[i] + k/3][y[j] + k%3]] = true;
            }
            for(int k = 0;k < 9;k++) {
                if(!t[k]) {
                    return false;
                }
                t[k] = false;
            }
        }
    }
    return true;
}

bool CreateSudoku::checkput(int x,int y) {
    //check if the number is valid
    std::stack<Node> temp;
    temp = s;
    if(temp.empty()) {
        return board[y][x] == 0;
    }
    while(!temp.empty()) {
        if(temp.top().x == x && temp.top().y == y) {
            return true;
        }
        temp.pop();
    }
    return false;
}

void CreateSudoku::get_input() {
    gotoxy(GetX(now.x),1+GetY(now.y));
    print_color(2,"^");
    int x = 0;
    int y = 0;
    std::map<std::pair<int, int>, bool> red;
    // #if !(_WIN32)
    //     linuxRead::linuxRead lread;
    //     lread.init_keyboard();
    // #endif
    while(true) {
        char ch = '\0';
        // #if _WIN32
        //     // if (_kbhit()) {
        //     //     ch = _getch();
        //     // }
        //     ch = getch();
        // #else
        //     // if (lread.kbhit()) {
        //     //     ch = lread.readch();
        //     // }
        //     ch = getch();
        // #endif
        ch = getch();
        bool out = false;
        switch (ch) {
        case 'Q': case 'q': exit(0);
        case 'w': case 'W': if(y>0) { y--; } break;
        case 's': case 'S': if(y<8) { y++; } break;
        case 'a': case 'A': if(x>0) { x--; } break;
        case 'd': case 'D': if(x<8) { x++; } break;
        case 'b': case 'B': 
        if(!s.empty()) {
            gotoxy(GetX(s.top().x),GetY(s.top().y));
            print_color(4,"0");
            board[s.top().y][s.top().x] = 0;
            s.pop();
        }
        break;
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        if(board[y][x] == 0 || checkput(x,y)) {
            board[y][x] = ch - '0';
            Node node;
            node.x = x;
            node.y = y;
            s.push(node);
        }
        break;
        case '\r':
            if(judge()) {
                cls();
                std::cout << "Success" << std::endl;
                return;
            } else {
                red = getError();
            }
            break;
        case 27: cls(); return;
        default:
            out = true;
            break;
        }
        if(out) {out = false; continue;}
        // Render the chess pieces
        // std::stack<Node> temp;
        // temp = s;
        // while(!temp.empty())
        // {
        //     gotoxy(2+4*temp.top().x,1+2*temp.top().y);
        //     print_color(4,board[temp.top().y][temp.top().x]);
        //     temp.pop();
        // }
        if(!s.empty()) {
            gotoxy(GetX(s.top().x),GetY(s.top().y));
            print_color(2,board[s.top().y][s.top().x]);
        }
        // Render pointer
        gotoxy(GetX(now.x), 1+GetY(now.y));
        if((now.y + 1) % 3 == 0) {
            print_color(1,"━");
        }
        else {
            print_color(0,"━");
        }
        std::stack<Node> temp;
        temp = s;
        bool flag = false;
        while(!temp.empty()) {
            if(temp.top().x == now.x && temp.top().y == now.y) {
                gotoxy(GetX(now.x),GetY(now.y));
                print_color(2,board[now.y][now.x]);
                flag = true;
                break;
            }
            temp.pop();
        }
        if(!flag) {
            gotoxy(GetX(now.x),GetY(now.y));
            print_color(0,board[now.y][now.x]);
        }
        // Highlight the wrong answers
        if (!red.empty()) {
            std::map<std::pair<int, int>, bool> ::iterator it;
            std::map<std::pair<int, int>, bool> ::iterator itEnd;
            it = red.begin();
            itEnd = red.end();
            while (it != itEnd) {
                gotoxy(GetX(it->first.first),GetY(it->first.second));
                print_color(1,board[it->first.first][it->first.second]);
                it++;
            }
            red.clear();
        }
        // Describe current position
        gotoxy(GetX(x),GetY(y));
        print_color(4,board[y][x]);
        gotoxy(GetX(x),1+GetY(y));
        print_color(2,"^");
        now.x = x;
        now.y = y;//update "now"
    }
}

std::map<std::pair<int, int>, bool> CreateSudoku::getError() {
    std::map<std::pair<int,int>, bool> red;
    int t[10] = {0};
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            t[board[i][j]]++;
        }
        for(int j = 0;j < 9;j++) {
            if (t[board[i][j]] > 1) {
                red.insert(std::pair<std::pair<int, int>, bool>(std::pair<int, int>(i, j), true));
            }
        }
        memset(t, 0, sizeof (t));
    }
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++) {
            t[board[j][i]]++;
        }
        for(int j = 0;j < 9;j++) {
            if (t[board[j][i]] > 1) {
                red.insert(std::pair<std::pair<int, int>, bool>(std::pair<int, int>(j, i), true));
            }
        }
        memset(t, 0, sizeof (t));
    }
    int x[3] = {0,3,6};
    int y[3] = {0,3,6};
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            for(int k = 0;k < 9;k++) {
                t[board[x[i] + k/3][y[j] + k%3]]++;
            }
            for(int k = 0;k < 9;k++) {
                if (t[board[x[i] + k/3][y[i] + k%3]] > 1) {
                    red.insert(std::pair<std::pair<int, int>, bool>(std::pair<int, int>(x[i] + k/3, y[i] + k%3), true));
                }
            }
            memset(t, 0, sizeof (t));
        }
    }
    return red;
}

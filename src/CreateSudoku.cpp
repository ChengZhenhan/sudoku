#include "CreateSudoku.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <time.h>
#include <utility>
#include <vector>

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

// It can also be exchanged by addition and subtraction
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
        for(int j = 1;j <= 9;j++) {
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
        for(int j = 1;j <= 9;j++) {
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
    std::vector<std::pair<int, int>> errors;
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
        case 'Q': case 'q': return;
        case 'w': case 'W': if(y>0) { y--; } break;
        case 's': case 'S': if(y<8) { y++; } break;
        case 'a': case 'A': if(x>0) { x--; } break;
        case 'd': case 'D': if(x<8) { x++; } break;
        case 'b': case 'B': case 'u': case 'U': 
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
                errors = getError();
            }
            break;
        // case 27: cls(); return;
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
        if (!errors.empty()) {
            std::vector<std::pair<int, int>> ::iterator it;
            std::vector<std::pair<int, int>> ::iterator itEnd;
            it = errors.begin();
            itEnd = errors.end();
            while (it != itEnd) {
                // Mark only the numbers that players fill in themselves
                if (puzzle[it->first][it->second] != 0) {
                    continue;
                }
                gotoxy(GetX(it->second),GetY(it->first));
                // print_color(1,board[it->first.first][it->first.second]);
                print_color(1,board[it->first][it->second]);
                it++;
            }
            errors.clear();
        }
        // Describe current position
        gotoxy(GetX(x),GetY(y));
        print_color(4,board[y][x]);
        gotoxy(GetX(x),1+GetY(y));
        print_color(2,"^");
        now.x = x;
        now.y = y;//update the position
    }
}

std::vector<std::pair<int, int> > CreateSudoku::getError() {
    std::vector<std::pair<int, int> > errors;
    int rows[9] = {0};      // 每行出现的数字情况
    int cols[9] = {0};      // 每列出现的数字情况
    int boxes[3][3] = {0};  // 每个 3x3 子框架出现的数字情况
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                continue;
            }
            int x = board[i][j];
            if ((rows[i] >> (x-1)) & 1) {
                // 数字 x 在当前行已经出现过
                for (int k = 0; k < j; ++k) {
                    if (board[i][k] == x) {
                        errors.emplace_back(i, k);
                        errors.emplace_back(i, j);
                        break;
                    }
                }
            } else {
                rows[i] |= (1 << (x-1));  // 将数字 x 标记为已出现
            }
            if ((cols[j] >> (x-1)) & 1) {
                // 数字 x 在当前列已经出现过
                for (int k = 0; k < i; ++k) {
                    if (board[k][j] == x) {
                        errors.emplace_back(k, j);
                        errors.emplace_back(i, j);
                        break;
                    }
                }
            } else {
                cols[j] |= (1 << (x-1));
            }
            if ((boxes[i/3][j/3] >> (x-1)) & 1) {
                // 数字 x 在当前 3x3 子框架已经出现过
                int r0 = i/3 * 3, c0 = j/3 * 3;
                for (int r = r0; r < i; ++r) {
                    for (int c = c0; c < j; ++c) {
                        if (board[r][c] == x) {
                            errors.emplace_back(r, c);
                            errors.emplace_back(i, j);
                            break;
                        }
                    }
                }
            } else {
                boxes[i/3][j/3] |= (1 << (x-1));
            }
        }
    }
    return errors;
}

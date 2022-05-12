#include "CreatSudoku.h"
#include "public.h"
#include "gotoxy.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stack>
#include <time.h>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <conio.h>
#else
char getch() {
    char c;
    system("stty -echo");
    c = getchar();
    system("stty echo");
    return c;
}
#endif

void CreatSudoku::load(const std::string& filename)
{
    std::ifstream in(filename);
    if(!in.is_open())
    {
        print_color(1,"ERROR:File opening failed!");
        return;
    }
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            in >> board[i][j];
        }
    }
    in >> n;
    in.close();
}

void CreatSudoku::save(const std::string& filename)
{
    std::ofstream out(filename);
    if(!out.is_open())
    {
        print_color(1,"ERROR:File opening failed!");
        return;
    }
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            out << board[i][j] << " ";
        }
        out << std::endl;
    }
    out.close();
}

//It can also be exchanged by addition and subtraction
void CreatSudoku::turnrow(int row1, int row2)
{
    int temp = 0;
    for(int i = 0;i < 9;i++)
    {
        temp = board[row1][i];
        board[row1][i] = board[row2][i];
        board[row2][i] = temp;
    }
}

void CreatSudoku::turncol(int col1, int col2)
{
    int temp = 0;
    for(int i = 0;i < 9;i++)
    {
        temp = board[i][col1];
        board[i][col1] = board[i][col2];
        board[i][col2] = temp;
    }
}
bool CreatSudoku::judge()
{
    bool t[9] = {false};
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            t[board[i][j] - 1] = true;
        }
        for(int j = 0;j < 9;j++)
        {
            if(!t[j])
            {
                return false;
            }
            t[j] = false;
        }
    }
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            t[board[j][i] - 1] = true;
        }
        for(int j = 0;j < 9;j++)
        {
            if(!t[j])
            {
                return false;
            }
            t[j] = false;
        }
    }
    int x[3] = {0,3,6};
    int y[3] = {0,3,6};
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            for(int k = 0;k < 9;k++)
            {
                t[board[x[i] + k/3][y[j] + k%3] - 1] = true;
            }   
            for(int k = 0;k < 9;k++)
            {
                if(!t[k])
                {
                    return false;
                }
                t[k] = false;
            }
        }
    }
    return true;
}

bool CreatSudoku::checkput(int x,int y){
    //check if the number is valid
    std::stack<Node> temp;
    temp = s;
    if(temp.empty())
    {
        return true;
    }
    while(!temp.empty())
    {
        if(temp.top().x == x && temp.top().y == y)
        {
            return true;
        }
        temp.pop();
    }
    return false;
}

void CreatSudoku::get_input()
{
    gotoxy(2+4*now.x,2+2*now.y);
    print_color(2,"^");
    int x = 0;
    int y = 0;
    while(true)
    {
        if (kbhit())
        {
            char ch = getch();
            if(ch == 'q' || ch == 'Q')
            {
                exit(0);
            }
            else if(ch == 'w' || ch == 'w')
            {
                if(y>0)
                {
                    y--;
                }
            }
            else if(ch == 's' || ch == 'S')
            {
                if(y<8)
                {
                    y++;
                }
            }
            else if(ch == 'a' || ch == 'A')
            {
                if(x>0)
                {
                    x--;
                }
            }
            else if(ch == 'd' || ch == 'D')
            {
                if(x<8)
                {
                    x++;
                }
            }
            else if(ch == 'b' || ch == 'B')
            {
                if(!s.empty())
                {
                    gotoxy(2+4*s.top().x,1+2*s.top().y);
                    // if(s.top().x==now.x && s.top().y==now.y)
                    // {
                    //     print_color(4,"0");
                    // }
                    print_color(4,"0");
                    board[s.top().y][s.top().x] = 0;
                    s.pop();
                }
            }
            else if(ch == '1')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 1;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '2')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 2;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '3')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 3;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '4')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 4;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '5')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 5;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '6')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 6;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '7')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 7;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '8')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 8;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            else if(ch == '9')
            {
                if(board[y][x] == 0 || checkput(x,y))
                {
                    board[y][x] = 9;
                    Node node;
                    node.x = x;
                    node.y = y;
                    s.push(node);
                }
            }
            //enter
            else if(ch == '\r')
            {
                if(judge())
                {
                    cls();
                    std::cout << "Success" << std::endl;
                    // while(true){}
                    break;
                }
            }
            else
            {
                continue;
            }
            //将下过的棋子重新渲染
            // std::stack<Node> temp;
            // temp = s;
            // while(!temp.empty())
            // {
            //     gotoxy(2+4*temp.top().x,1+2*temp.top().y);
            //     print_color(4,board[temp.top().y][temp.top().x]);
            //     temp.pop();
            // }
            if(!s.empty())
            {
                gotoxy(2+4*s.top().x,1+2*s.top().y);
                print_color(2,board[s.top().y][s.top().x]);
            }
            //渲染指针
            gotoxy(2+4*now.x,2+2*now.y);
            if((now.y + 1) % 3 == 0)
            {
                print_color(1,"━");
            }
            else
            {
                print_color(0,"━");
            }
            std::stack<Node> temp;
            temp = s;
            bool flag = false;
            while(!temp.empty())
            {
                if(temp.top().x == now.x && temp.top().y == now.y)
                {
                    gotoxy(2+4*now.x,1+2*now.y);
                    print_color(2,board[now.y][now.x]);
                    flag = true;
                    break;
                }
                temp.pop();
            }
            if(!flag)
            {
                gotoxy(2+4*now.x,1+2*now.y);
                print_color(0,board[now.y][now.x]);
            }
            gotoxy(2+4*x,1+2*y);
            print_color(4,board[y][x]);
            gotoxy(2+4*x,2+2*y);
            print_color(2,"^");
            now.x = x;
            now.y = y;//update now
        }
    }
}
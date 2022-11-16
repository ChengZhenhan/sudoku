#ifndef _SUDO_CREATE_SUDOKU_H_
#define _SUDO_CREATE_SUDOKU_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <cstring>
#include <stack>
#include "Utils.h"

class CreateSudoku
{
private:
    int board[9][9] = {{9,7,2,8,5,3,6,1,4},
                        {1,4,6,2,7,9,5,3,8},
                        {5,8,3,1,4,6,7,2,9},
                        {6,2,4,7,1,8,9,5,3},
                        {8,1,7,3,9,5,4,6,2},
                        {3,5,9,4,6,2,8,7,1},
                        {7,9,8,6,2,1,3,4,5},
                        {2,6,5,9,3,4,1,8,7},
                        {4,3,1,5,8,7,2,9,6}};
    
    typedef struct Node{
        int x = 0;
        int y = 0;
    }Node;
    Node now;
    std::stack<Node> s;
    int n = 0;  //Number of steps
public:
    bool flag = false;  //If the board is filled in correctly
    CreateSudoku(int difficulty) {
        srand(time(NULL));
        int i = rand()%99 + 15;
        int j = rand()%99 + 15;
        int rand1;
        int rand2;
        for(int k = 0;k < i;k++) {
            for(int l = 0;l < j;l++) {
                rand1 = (rand()%3 + 1)*(rand()%3 + 1) - 1;
                rand2 = rand1/3*3 + rand() % 3;
                turnrow(rand1,rand2);
                turncol(rand1,rand2);
                rand1 = (rand()%3 + 1)*(rand()%3 + 1) - 1;
                rand2 = rand1/3*3 + rand() % 3;
                turncol(rand1,rand2);
                turnrow(rand1,rand2);
            }
        }
        for(int k = 0;k < difficulty;k++) {
            int a = rand()%9;
            int b = rand()%9;
            if(board[a][b] != 0) {
                board[a][b] = 0;
            }
            else {
                k--;
            }
        }
    }

    CreateSudoku(const std::string& filename) {
        load(filename);
    }

    ~CreateSudoku() {
        cls();
        std::string filename;
        std::cout << "Please input the filename: ";
        std::cin >> filename;
        save(filename);
    }

    void load(const std::string& filename);
    void save(const std::string& filename);
    void turnrow(int row1, int row2);
    void turncol(int col1, int col2);
    bool judge();
    void get_input();
    bool checkput(int x, int y);
    //get_board
    int** get_board()
    {
        int **p = new int*[9];
        for(int i = 0;i < 9;i++)
        {
            p[i] = new int[9];
        }
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                p[i][j] = board[i][j];
            }
        }
        return p;
    }
};

#endif
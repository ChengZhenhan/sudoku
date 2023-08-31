#ifndef _SUDO_CREATE_SUDOKU_H_
#define _SUDO_CREATE_SUDOKU_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <stack>
#include <random>
#include <vector>
#include "Utils.h"

class CreateSudoku {
private:
    std::vector<std::vector<int>> board { { 9, 7, 2, 8, 5, 3, 6, 1, 4 },
                        { 1, 4, 6, 2, 7, 9, 5, 3, 8 },
                        { 5, 8, 3, 1, 4, 6, 7, 2, 9 },
                        { 6, 2, 4, 7, 1, 8, 9, 5, 3 },
                        { 8, 1, 7, 3, 9, 5, 4, 6, 2 },
                        { 3, 5, 9, 4, 6, 2, 8, 7, 1 },
                        { 7, 9, 8, 6, 2, 1, 3, 4, 5 },
                        { 2, 6, 5, 9, 3, 4, 1, 8, 7 },
                        { 4, 3, 1, 5, 8, 7, 2, 9, 6 } };

    // int board[9][9] =
    typedef struct Node {
        int x = 0;
        int y = 0;
    } Node;
    Node now;
    std::stack<Node> s; // 存储填充的数的顺序
    int zero = 0; // Number of steps
    struct History {
        int x,y;
        int num;
        int type;   // 1: 更改数字
                    // 2: 回溯
//        int change;
    };
public:
    bool test = false;
    std::string filename;
    std::vector<std::vector<int>> puzzle;   // 存储最开始的棋盘,可能会用到
    std::vector<History> actionHistory;

    CreateSudoku() {}
    CreateSudoku(int difficulty)
    {
        zero = difficulty;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist1(15,99);
        std::uniform_int_distribution<> dist2(0,8);
        int i = dist1(gen);
        int j = dist1(gen);
        int rand1;
        int rand2;
        for (int k = 0; k < i; k++) {
            for (int l = 0; l < j; l++) {
                rand1 = dist2(gen);
                rand2 = dist2(gen);
                turnrow(rand1, rand2);
                turncol(rand1, rand2);
                rand1 = dist2(gen);
                rand2 = dist2(gen);
                turncol(rand1, rand2);
                turnrow(rand1, rand2);
            }
        }
        for (int k = 0; k < difficulty; k++) {
            int a = dist2(gen);
            int b = dist2(gen);
            if (board[a][b] != 0) {
                board[a][b] = 0;
            } else {
                k--;
            }
        }
        puzzle = board;
    }

    CreateSudoku(const std::string &filename)
    {
        this->filename = filename;
        board = std::vector<std::vector<int>> (9, std::vector<int> (9));
        load(filename);
        puzzle = board;
    }

    ~CreateSudoku()
    {
        if (!test) {
            cls();
            while (true) {
                std::cout << "Do you want to save the board? (yes(y)/no(n))?" << std::endl;
                std::string choice;
                std::cin >> choice;
                if (choice == "yes" || choice == "y") {
                    if (!filename.empty()) {
                        save(filename);
                        exit(0);
                    }
                    std::cout << "Please input the filename: ";
                    std::cin >> filename;
                    save(filename);
                    exit(0);
                } else if (choice == "no" || choice == "n") {
                    exit(0);
                } else {
                    continue;
                }
            }
        }
    }

    void load(const std::string &filename);
    void save(const std::string &filename);
    void turnrow(int row1, int row2);
    void turncol(int col1, int col2);
    bool judge();
    void get_input();
    bool checkput(int x, int y);
    std::vector<std::pair<int, int>> getError();
    // get_board
    std::vector<std::vector<int>> get_board() {
        return board;
    }

    void set_board(std::vector<std::vector<int>> b) {
        board = b;
    }
};

#endif

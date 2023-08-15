//
// Created by ChengZhenhan on 2022/12/19.
//
#include "../src/CreateSudoku.h"
#include <iostream>
#include <ostream>
#include <vector>

int testCreateSudoku(int t) {
    CreateSudoku sudokuObj;
    sudokuObj.test = true;

    // 测试用例1
    int board1[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // 测试用例2
    int board2[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    // 测试用例3
    int board3[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 9, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    if (t == 1) {
        std::vector<std::pair<int, int>> expectedOutput1 = {};
        sudokuObj.set_board(board1);
        std::vector<std::pair<int, int>> output1 = sudokuObj.getError();
        std::cout << "Test Case 1: ";
        if (output1 == expectedOutput1) {
            std::cout << "Passed\n";
            return 0;
        } else {
            std::cout << "Failed\n";
            return -1;
        }
    } else if (t == 2) {
        std::vector<std::pair<int, int>> expectedOutput2 = {};
        sudokuObj.set_board(board2);
        std::vector<std::pair<int, int>> output2 = sudokuObj.getError();
        std::cout << "Test Case 2: ";
        if (output2 == expectedOutput2) {
            std::cout << "Passed\n";
            return 1;
        } else {
            std::cout << "Failed\n";
            return -1;
        }
    } else if (t == 3) {
        std::vector<std::pair<int, int>> expectedOutput3 = {
            {2, 2}, {2, 3}, {2, 4}, {2, 5}
        };
        sudokuObj.set_board(board3);
        std::vector<std::pair<int, int>> output3 = sudokuObj.getError();
        std::cout << "Test Case 3: ";
        if (output3 == expectedOutput3) {
            std::cout << "Passed\n";
            return 1;
        } else {
            std::cout << "Failed\n";
            std::cout << "    - Expected Output: ";
            for (auto coord : expectedOutput3) {
                std::cout << "(" << coord.first << ", " << coord.second << "), ";
            }
            std::cout << "\n    - Actual Output: ";
            for (auto coord : output3) {
                std::cout << "(" << coord.first << ", " << coord.second << "), ";
            }
            std::cout << "\n";
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::string a = argv[1];
    int t = a[0] - '0';
    // std::cout << a << " " << t << std::endl;
    return testCreateSudoku(t);
}



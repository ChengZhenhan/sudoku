//
// Created by ChengZhenhan on 2022/12/19.
//
#include "../src/CreateSudoku.h"

int main(int argc, char const *argv[]) {
    CreateSudoku sudoku("./test.txt");
    sudoku.test = true;
    if (!sudoku.judge()) {
    //  std::cout << "pass" << std::endl;
        return 0;
    } else {
        return -1;
    }
}

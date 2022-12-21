//
// Created by ChengZhenhan on 2022/12/19.
//
#include "../src/CreateSudoku.h"

int main(int argc, char const *argv[]) {
    CreateSudoku sudoku("./test.txt");
    sudoku.test = true;
    std::map<std::pair<int, int>, bool> map = sudoku.getError();
    return 0;
}

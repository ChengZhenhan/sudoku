//
// Created by ChengZhenhan on 2022/12/19.
//
#include "../src/CreateSudoku.h"

int main(int argc, char const *argv[]) {
    CreateSudoku sudoku(argv[0]);
    sudoku.test = true;
    std::vector<std::pair<int, int>> map = sudoku.getError();
    if (map.size() != 0) {
        return -1;
    }
    return 0;
}

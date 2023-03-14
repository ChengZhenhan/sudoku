//
// Created by ChengZhenhan on 2022/12/19.
//
#include "../src/CreateSudoku.h"

int main(int argc, char const *argv[]) {
    CreateSudoku sudoku(argv[0]);
    sudoku.test = true;
    bool ans;
    if (strcmp(argv[1],"1") == 0) {
        ans = true;
    } else {
        ans = false;
    }
    
    if (sudoku.judge() == ans) {
    //  std::cout << "pass" << std::endl;
        return 0;
    } else {
        return -1;
    }
}

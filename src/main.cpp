#include "CreateSudoku.h"
#include "Utils.h"
#include "draw.h"
#include <cmath>
#include <cstring>
#include <iostream>

void help() {
    std::cout << "Usage: ./Sudoku [filename]" << std::endl;
    std::cout << "If no filename is given, the game will start automatically." << std::endl;
}

void play()
{
    cls();

// clock_t startTime,endTime;
// startTime = clock();
s:
    std::cout << "Welcome to Sudoku!" << std::endl;
    std::cout << "Please input the difficulty level you want[1.easy 2.medium 3.difficult]:" << std::endl;
    int level = 0;
    std::cin >> level;
    cls();
    if (level >= 1 && level <= 3) {
        CreateSudoku sudoku(20 * level);
        draw d(sudoku.get_board());
        d.draw_board(0, 0);
        sudoku.get_input();
    } else {
        std::cout << "ERROR:Invalid input!" << std::endl;
        goto s;
    }
}
void play(const std::string &filename)
{
    cls();
    CreateSudoku sudoku(filename);
    draw d(sudoku.get_board());
    d.draw_board(0, 0);
    sudoku.get_input();
}
int main(int argc, char *argv[])
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    if (argc == 1) {
        play();
    } else if (argc == 2 && !strcmp(argv[1], "-h")) {
        help();
        return 0;
    } else if (argc == 2) {
        play(argv[2]);
    } else {
        help();
    }
    // while (true) { }
    return 0;
}

#include <iostream>
#include <cstring>
#include <cmath>
#include "draw.h"
#include "CreateSudoku.h"

void play() {
	cls();

	// clock_t startTime,endTime;
	// startTime = clock();
	s:
	std::cout << "Welcome to Sudoku!" << std::endl;
	std::cout << "Please input the difficulty level you want[1.easy 2.medium 3.difficult]:" << std::endl;
	int level = 0;
	std::cin >> level;
	cls();
	if(level >= 1 && level <= 3)
	{
		CreateSudoku sudoku(20 * level);
		draw d(sudoku.get_board());
		d.draw_board(0,0);
		sudoku.get_input();
	}
	else
	{
		std::cout << "ERROR:Invalid input!" << std::endl;
		goto s;
	}
}
void play(const std::string& filename) {
	cls();
	CreateSudoku sudoku(filename);
	draw d(sudoku.get_board());
	d.draw_board(0,0);
	sudoku.get_input();
}
int main(int argc, char *argv[]) {
#ifdef _WIN32
	system("chcp 65001");
#endif
	m:
	if(argc == 1) {
		play();
	}
	else if(argc == 2 && !strcmp(argv[1], "-h")) {
		std::cout << "Usage: ./Sudoku [filename]" << std::endl;
		std::cout << "If no filename is given, the game will start automatically." << std::endl;
		goto m;
	}
	else if(argc == 2) {
		play(argv[2]);
	}
	else {
		std::cout << "Usage: ./Sudoku [filename]" << std::endl;
		std::cout << "If no filename is given, the game will start automatically." << std::endl;
		goto m;
	}
	while(true){}
    return 0;
}

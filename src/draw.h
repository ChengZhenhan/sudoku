#ifndef _SUDO_DRAW_H_
#define _SUDO_DRAW_H_

#include <iostream>
#include <cstring>

class draw
{
private:
	int board[9][9] = {0};
public:
	void draw_board(int nx,int ny);
	draw(int **board)
	{
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0;j < 9;j++)
			{
				this->board[i][j] = board[i][j];
			}
		}
		// memcpy(this->board, board, sizeof(board));
	}
	~draw()
	{
	}
};

#endif
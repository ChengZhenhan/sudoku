#ifndef _SUDO_DRAW_H_
#define _SUDO_DRAW_H_

#include <iostream>
#include <cstring>
#include <vector>

class draw
{
private:
    std::vector<std::vector<int>> board;
public:
    void draw_board(int nx,int ny);
    explicit draw(std::vector<std::vector<int>> board) {
        this->board = board;
    }
    ~draw()
    = default;
};

#endif

#include <cstring>
#include <cmath>
#include "draw.h"
#include "Utils.h"

void draw::draw_board(int nx,int ny) {
    gotoxy(0, 0);
    print_color(1,"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓");
    std::cout << std::endl;
    int color;
    for(int i = 0;i < 9;i++) {
        print_color(1,"┃");
        for(int j = 0;j < 9;j++) {
            color = (j+1)%3==0?1:0;
            std::cout << " ";
            if(i == ny && j == nx)
                print_color(4,board[i][j]);
            else
                print_color(0,board[i][j]);
            print_color(color," ┃");
        }
        std::cout << std::endl;
        color = (i+1)%3==0?1:0;
        if (i == 8) {
            print_color(color,"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛");
        } else {
            print_color(color,"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫");
        }
        std::cout << std::endl;
    }
}
# sudoku
A simple Sudoku game

## Characteristic
1. Cross platform : Linux/Windows/macOs

## Dependence
1. Cmake 3.12 and above

## Build
1. Compile under Windows: `build.bat`
2. Compile under macOs/Linux: `sh build.sh` 

## Run
Program generated by construction step is in the `bin` directory
``` shell
./sudoku  # Direct start
./sudoku filename  # Read game progress file
./sudoku -h  # Get help
```

## Operating instructions
- w Move cursor up
- a Move cursor left
- s Cursor down
- d Move cursor right
- b Undo the previous action
- enter Try to clear the customs
- esc Exit the game

## Program effect

![](.\effect.bmp)

## Project structure
```bash
│--.gitignore  
│--build.bat         // Windows one click compilation script
│--build.sh          // Linux one click compilation script
│--CMakeLists.txt    // Cmake project documents
│--README.md     
└--src               // Source code directory  
   │--main.cpp       // main
   │--gotoxy.h       // Cursor movement function
   │--gotoxy.cpp
   |--draw.h         // Draw function
   │--draw.cpp
   │--CreateSudoku.h // Sudoku game function
   │--CreateSudoku.cpp
   │--public.h      // Public header file
   └--public.cpp
```

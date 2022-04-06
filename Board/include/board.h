#ifndef _BOARD_H
#define _BOARD_H

#include <unordered_map>
#include <string>
#include <stdio.h>

#include "../include/cell.h"

using namespace std;
class Cell;
class Board {
    public:
        unordered_map<string, Cell*> cells;

        Board();
        void CreateOrGetCell(char x, char y);
};

#endif
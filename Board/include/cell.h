#ifndef _CELL_H
#define _CELL_H

#include <unordered_map>
#include <string>
#include <stdio.h>
#include <iostream>

#include "../include/board.h"

using namespace std;
class Board;
class Cell {
    private:
        char _x, _y;
        string _name;
        Board* _board;
        int _num_of_neighbours = 0;

    public:
        std::unordered_map<int, Cell*> neighbours;
        Cell(char x, char y, Board* board);
        void FindNeighbours();
};

#endif
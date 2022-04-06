#ifndef _CELL_H
#define _CELL_H

#include <unordered_map>
#include <string>
#include <stdio.h>
#include <iostream>

#include "../include/board.h"

using namespace std;

namespace ChessBoard{

class Board;
    class Cell {
        
        public:
            char x, y;
            string name;
            Board* board;
            int _num_of_neighbours = 0;
            std::unordered_map<int, Cell*> neighbours;

            Cell(char x, char y, Board* board);
            void FindNeighbours();
            
    };
}

#endif
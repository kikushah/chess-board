#ifndef _Piece_H
#define _Piece_H

#include <unordered_map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "../../Board/include/board.h"

using namespace std;

namespace ChessBoard{

    class Board;
    class Cell;

    class Piece{

        public:
            Board *board;
            Cell *current_cell, *initial_cell;
            string initial_position;
            int max_distance;
            vector<int> allowed_directions;
            vector<string> legal_moves;
            
            string FindAllAllowedCells(string initial_position);
            void Traverse(int allowed_distance, int direction);

    };

    class King : public Piece{
        public:
        King(Board *board);
    };

    class Queen : public Piece{
        public:
        Queen(Board *board);
    };

    class Pawn : public Piece{
        public:
        Pawn(Board *board);
    };
}

#endif
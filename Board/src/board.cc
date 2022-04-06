#include "../include/board.h"

using namespace ChessBoard;

Board::Board(char x, char y){

    // This creates a board of all cells like a graph and inserts each cell into the map
    // As every new cell created tries to find its neighbours or creates them
    // The Starting cell can be any of the 64 cells
    this->CreateOrGetCell(x, y);
}

Cell* Board::CreateOrGetCell(char x, char y){
    string name;
    name += x;
    name += y;

    auto it = this->cells.find(name);

    Cell *cell;

    if (it == this->cells.end()){
         cell = new Cell(x, y, this);        
    }
    else{
        cell = it->second;
    }

    return cell;
}
#include "../include/board.h"

Board::Board(){

    // This creates a board of all cells like a graph and inserts each cell into the map
    // As every new cell created tries to find its neighbours or creates them
    this->CreateOrGetCell('A', '1');
}

void Board::CreateOrGetCell(char x, char y){
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
}
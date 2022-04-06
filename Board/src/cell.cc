#include "../include/cell.h"
#include "../include/board.h"

using namespace std;
using namespace ChessBoard;

Cell::Cell(char x, char y, Board* board){

    this->x = x;
    this->y = y;
    this->name += x;
    this->name += y;

    this->board = board;
    this->board->cells[this->name] = this;

    this->FindNeighbours();

    // cout << "Created cell: " << this->_name << " with " << this->_num_of_neighbours << " neighbours" << endl;
}

void Cell::FindNeighbours(){

    for(int directions = 0; directions < 8; directions++){
        char newx, newy;
        switch (directions)
        {
            case 0: //right
            newx = this->x + 1;
            newy = this->y;
            break;
            case 1: //right up
            newx = this->x + 1;
            newy = this->y + 1;
            break;
            case 2: // up
            newx = this->x;
            newy = this->y + 1;
            break;
            case 3: // left up
            newx = this->x - 1;
            newy = this->y + 1;
            break;
            case 4: // left
            newx = this->x - 1;
            newy = this->y;
            break;
            case 5: // left down
            newx = this->x - 1;
            newy = this->y - 1;
            break;
            case 6: // down
            newx = this->x;
            newy = this->y - 1;
            break;
            case 7: // right down
            newx = this->x + 1;
            newy = this->y - 1;           

        }

        if(newx >= 'A' && newx <= 'H' && newy >= '1' && newy <= '8'){
            this->neighbours[directions] = this->board->CreateOrGetCell(newx, newy);
            this->_num_of_neighbours++;
        }
        else{
            // this->neighbours[directions] = nullptr;
        }
        
         

    }

    
    if(this->x == 'A'){

    }
}
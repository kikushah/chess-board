#include "../include/cell.h"
#include "../include/board.h"
using namespace std;

Cell::Cell(char x, char y, Board* board){

    this->_x = x;
    this->_y = y;
    this->_name += x;
    this->_name += y;

    this->_board = board;
    this->_board->cells[this->_name] = this;

    this->FindNeighbours();

    cout << "Created cell: " << this->_name << " with " << this->_num_of_neighbours << " neighbours" << endl;
}

void Cell::FindNeighbours(){

    for(int directions = 0; directions < 8; directions++){
        char newx, newy;
        switch (directions)
        {
            case 0: //right
            newx = this->_x + 1;
            newy = this->_y;
            break;
            case 1: //right up
            newx = this->_x + 1;
            newy = this->_y + 1;
            break;
            case 2: // up
            newx = this->_x;
            newy = this->_y + 1;
            break;
            case 3: // left up
            newx = this->_x - 1;
            newy = this->_y + 1;
            break;
            case 4: // left
            newx = this->_x - 1;
            newy = this->_y;
            break;
            case 5: // left down
            newx = this->_x - 1;
            newy = this->_y - 1;
            break;
            case 6: // down
            newx = this->_x;
            newy = this->_y - 1;
            break;
            case 7: // right down
            newx = this->_x + 1;
            newy = this->_y - 1;           

        }

        if(newx >= 'A' && newx <= 'H' && newy >= '1' && newy <= '8'){
            this->_board->CreateOrGetCell(newx, newy);
            this->_num_of_neighbours++;
        }
        else{
            this->neighbours[directions] = nullptr;
        }
        
         

    }

    
    if(this->_x == 'A'){

    }
}
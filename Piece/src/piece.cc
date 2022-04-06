#include "../include/piece.h"
#include "../../Board/include/board.h"

using namespace std;
using namespace ChessBoard;

string Piece::FindAllAllowedCells(string initial_position){
    
    this->initial_position = initial_position;
    this->initial_cell = this->board->cells[initial_position];
    this->legal_moves.clear();
    
    for(int i: this->allowed_directions){
        // Traversing in all the allowed directions
    
        this->current_cell = this->initial_cell;        // This is to revert to initial position after traversing through a direction

        this->Traverse(this->max_distance, i);
    }

    string allowed_cells;

    // legal_moves is a vector of all the valid moves
    if(this->legal_moves.empty()){

        allowed_cells = "\nNo legal moves from " + this->initial_cell->name;
        allowed_cells += "\n\n";
    }
    else{
        
        for(string cell: this->legal_moves){

            allowed_cells += cell + ", ";
        }
    }
    
    allowed_cells = "\nLegal Moves: " + allowed_cells;
    allowed_cells = allowed_cells.substr(0, allowed_cells.size() - 2);  // Removing the extra , and space from the end
    allowed_cells += "\n\n";
    
    return allowed_cells;
}

void Piece::Traverse(int allowed_distance, int direction){

    if(allowed_distance > 0){
        //This is to recurse in the same direction

        auto it = this->current_cell->neighbours.find(direction);
        
        if(it != this->current_cell->neighbours.end()){
            
            this->current_cell = it->second;
            
            this->legal_moves.push_back(this->current_cell->name);
            allowed_distance--;            

            this->Traverse(allowed_distance, direction);

        }
    }    
}

King::King(Board *board){
    
    this->board = board;
    this->max_distance = 1;

    for(int i = 0; i < 8; i++){
        // All directions are allowed
        this->allowed_directions.push_back(i);
    }
}

Queen::Queen(Board *board){
    
    this->board = board;
    this->max_distance = 7;

    for(int i = 0; i < 8; i++){
        // All directions are allowed
        this->allowed_directions.push_back(i);
    }
}

Pawn::Pawn(Board *board){
    
    this->board = board;
    this->max_distance = 1;

    for(int i = 0; i < 8; i++){
        // Only direction up is allowed
        if(i == 2)      
            this->allowed_directions.push_back(i);
    }
}
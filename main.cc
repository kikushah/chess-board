#include "Board/include/board.h"
#include "Piece/include/piece.h"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace ChessBoard;

enum piece {
    eKing,
    eQueen,
    ePawn,
    eExit,
    eUnknown
};

piece hashit(string const& input){
    if(input == "King" || input == "king") return eKing;
    else if(input == "Queen" || input == "queen") return eQueen;
    else if(input == "Pawn" || input == "pawn") return ePawn;
    else return eUnknown;
    
}


int main(int argc, char **argv){
    
    cout << "Hi!! Welcome to Chessboard Simulation" << endl << endl;
    
    Board *board = new Board();

    cout << "The Board is created successfully !!" << endl;

    King *king = new King(board);
    Queen *queen = new Queen(board);
    Pawn *pawn = new Pawn(board);    

    string piece, initial_position;

    while(true){

        bool exit = false;
        cout << "Enter an input in this format \"Pawn, G1\". You may press Ctrl + C to exit" << endl;

        cin >> piece >> initial_position;

        switch(hashit(piece)){
            
            case eKing:
            cout << king->FindAllAllowedCells(initial_position);
            break;

            case eQueen:
            cout << queen->FindAllAllowedCells(initial_position);
            break;

            case ePawn:
            cout << pawn->FindAllAllowedCells(initial_position);
            break;

            case eUnknown:
            cout << "Uncrecognized Input, Try Again !!" << endl;
        }

        if(exit)
        break;

    }
    
}
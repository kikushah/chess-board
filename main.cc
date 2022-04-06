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

bool ValidateInitialPosition(string initial_position){
    char x = initial_position.at(0);
    char y = initial_position.at(1);
    if(x >= 'A' && x <= 'H' && y >= '1' && y <= '8')
        return true;
    else
        return false;
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

        //Clean the input
        piece.erase(remove(piece.begin(), piece.end(), ','), piece.end());
        initial_position.erase(remove(initial_position.begin(), initial_position.end(), ','), initial_position.end());

        try{

            if(!ValidateInitialPosition(initial_position)){
                cout << "Invalid Initial Position, Try Again !!" << endl;
                continue;

            }
        }
        catch(...){
                cout << "Invalid Input Format, Try Again !!" << endl;
                continue;
        }

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
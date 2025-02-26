#include<iostream>
#include<string>
#include"ChessBoard.h"
using namespace std;

class Poll {
protected:
    ChessBoard board;
public:
    void init() {
        board.placePiece(new Rook("white", 0, 0), 0, 0);
        board.placePiece(new Knight("white", 0, 1), 0, 1);
        board.placePiece(new Bishop("white", 0, 2), 0, 2);
        board.placePiece(new Queen("white", 0, 3), 0, 3);
        board.placePiece(new King("white", 0, 4), 0, 4);
        board.placePiece(new Bishop("white", 0, 5), 0, 5);
        board.placePiece(new Knight("white", 0, 6), 0, 6);
        board.placePiece(new Rook("white", 0, 7), 0, 7);
        for (int i = 0; i < 8; ++i) {
            board.placePiece(new Pawn("white", 1, i), 1, i);
        }

        board.placePiece(new Rook("black", 7, 0), 7, 0);
        board.placePiece(new Knight("black", 7, 1), 7, 1);
        board.placePiece(new Bishop("black", 7, 2), 7, 2);
        board.placePiece(new Queen("black", 7, 3), 7, 3);
        board.placePiece(new King("black", 7, 4), 7, 4);
        board.placePiece(new Bishop("black", 7, 5), 7, 5);
        board.placePiece(new Knight("black", 7, 6), 7, 6);
        board.placePiece(new Rook("black", 7, 7), 7, 7);
        for (int i = 0; i < 8; ++i) {
            board.placePiece(new Pawn("black", 6, i), 6, i);
        }
    }
    void display() {
        board.display();
    }
};



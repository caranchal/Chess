#pragma
#include<iostream>
#include<string>
#include"ChessBoard.h"
using namespace std;

class Poll {
protected:
    ChessBoard board;
public:
    void init() {
        board.placePiece(new Rook("white", "Rook", 0, 0), 0, 0);
        board.placePiece(new Knight("white", "Knight", 0, 1), 0, 1);
        board.placePiece(new Bishop("white", "Bishop", 0, 2), 0, 2);
        board.placePiece(new Queen("white", "Queen", 0, 3), 0, 3);
        board.placePiece(new King("white", "King", 0, 4), 0, 4);
        board.placePiece(new Bishop("white", "Bishop", 0, 5), 0, 5);
        board.placePiece(new Knight("white", "Knight", 0, 6), 0, 6);
        board.placePiece(new Rook("white", "Rook", 0, 7), 0, 7);
        for (int i = 0; i < 8; ++i) {
            board.placePiece(new Pawn("white", "Pawn", 1, i), 1, i);
        }

        board.placePiece(new Rook("black", "Rook", 7, 0), 7, 0);
        board.placePiece(new Knight("black", "Knight", 7, 1), 7, 1);
        board.placePiece(new Bishop("black", "Bishop", 7, 2), 7, 2);
        board.placePiece(new Queen("black", "Queen", 7, 3), 7, 3);
        board.placePiece(new King("black", "King", 7, 4), 7, 4);
        board.placePiece(new Bishop("black", "Bishop", 7, 5), 7, 5);
        board.placePiece(new Knight("black", "Knight", 7, 6), 7, 6);
        board.placePiece(new Rook("black", "Rook", 7, 7), 7, 7);
        for (int i = 0; i < 8; ++i) {
            board.placePiece(new Pawn("black", "Pawn", 6, i), 6, i);
        }
    }
    void display() {
        board.display();
    }
    void Move(int x1, int y1, int x2, int y2) {
        board.movePiece(x2, y1, x2, y2);
        board.display();
    }
};



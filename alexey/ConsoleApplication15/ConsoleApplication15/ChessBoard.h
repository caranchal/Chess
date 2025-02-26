#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include <iostream>
#include <string>
using namespace std;

class ChessBoard {
private:
    ChessPiece* board[8][8]; // ��������� ����� 8x8

public:
    ChessBoard();
    ~ChessBoard();

    void initializeBoard(); // ������������� �����
    void displayBoard() const; // ����������� �����
};

#endif

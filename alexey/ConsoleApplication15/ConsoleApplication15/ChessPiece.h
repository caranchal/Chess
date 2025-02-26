#pragma once
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <string>
using namespace std;

// Базовый класс для шахматной фигуры
class ChessPiece {
protected:
    string color; // Цвет фигуры (например, "white" или "black")
    string name;  // Название фигуры (например, "Pawn", "Rook", etc.)

public:
    ChessPiece(const string& color, const string& name);
    virtual ~ChessPiece();

    // Виртуальный метод для получения возможных ходов фигуры
    virtual string getPossibleMoves(const string& currentPosition) const = 0;

    // Метод для получения цвета фигуры
    string getColor() const;

    // Метод для получения имени фигуры
    string getName() const;

    // Метод для отображения информации о фигуре
    void display() const;
};

// Класс для пешки
class Pawn : public ChessPiece {
public:
    Pawn(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

// Класс для ладьи
class Rook : public ChessPiece {
public:
    Rook(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

// Класс для коня
class Knight : public ChessPiece {
public:
    Knight(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

// Класс для слона
class Bishop : public ChessPiece {
public:
    Bishop(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

// Класс для ферзя
class Queen : public ChessPiece {
public:
    Queen(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

// Класс для короля
class King : public ChessPiece {
public:
    King(const string& color);
    string getPossibleMoves(const string& currentPosition) const override;
};

#endif
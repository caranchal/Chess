#include<iostream>
#include<string>
using namespace std;
int absolute(int value) {
    return (value < 0) ? -value : value;
}
class Figure{
protected:
    string color;
    int x, y;

public:
    Figure(const string& color, int x, int y) : color(color), x(x), y(y) {}

    virtual ~Figure() {}

    // Виртуальный метод для проверки возможности хода
    virtual bool canMove(int newX, int newY) const = 0;

    // Метод для перемещения фигуры
    void move(int newX, int newY) {
        if (canMove(newX, newY)) {
            x = newX;
            y = newY;
            cout << "Moved to (" << x << ", " << y << ")\n";
        }
        else {
            cout << "Invalid move\n";
        }
    }

    // Метод для получения цвета фигуры
    string getColor() const {
        return color;
    }

    // Метод для получения текущих координат
    pair<int, int> getPosition() const {
        return { x, y };
    }

    // Виртуальный метод для получения символа фигуры
    virtual char getSymbol() const = 0;
};

// Класс для пешки
class Pawn : public Figure {
public:
    Pawn(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        int direction = (color == "white") ? 1 : -1;
        return (newX == x) && (newY == y + direction);
    }

    char getSymbol() const override {
        return (color == "white") ? 'P' : 'p';
    }
};

// Класс для ладьи
class Rook : public Figure {
public:
    Rook(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x) || (newY == y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'R' : 'r';
    }
};

// Класс для коня
class Knight : public Figure {
public:
    Knight(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        int dx = absolute(newX - x);
        int dy = absolute(newY - y);
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }

    char getSymbol() const override {
        return (color == "white") ? 'N' : 'n';
    }
};

// Класс для слона
class Bishop : public Figure {
public:
    Bishop(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return absolute(newX - x) == absolute(newY - y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'B' : 'b';
    }
};

// Класс для ферзя
class Queen : public Figure {
public:
    Queen(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x)  (absolute(newX - x) == absolute(newY - y));
    }

    char getSymbol() const override {
        return (color == "white") ? 'Q' : 'q';
    }
};

// Класс для короля
class King : public Figure {
public:
    King(const string& color, int x, int y) : Figure(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        int dx = absolute(newX - x);
        int dy = absolute(newY - y);
        return (dx <= 1 && dy <= 1);
    }

    char getSymbol() const override {
        return (color == "white") ? 'K' : 'k';
    }
};
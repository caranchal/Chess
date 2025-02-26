#include<iostream>
#include<string>
using namespace std;
int absolute(int value) {
    return (value < 0) ? -value : value;
}
class Figure {
protected:
    string color;
    string name;
    int x, y;

public:
    Figure(const string& color, string Name, int x, int y) {
        this->color = color;
        this->name = name;
        this->x = x;
        this->y = y;
    }
    string getName() {
        return name;
    }
    virtual ~Figure() {}


    virtual bool canMove(int newX, int newY) const = 0;


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


    string getColor() const {
        return color;
    }


    pair<int, int> getPosition() const {
        return { x, y };
    }


    virtual char getSymbol() const = 0;
};


class Pawn : public Figure {
public:
    Pawn(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        int direction = (color == "white") ? 1 : -1;
        return (newX == x) && (newY == y + direction);
    }

    char getSymbol() const override {
        return (color == "white") ? 'P' : 'p';
    }
};


class Rook : public Figure {
public:
    Rook(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x) || (newY == y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'R' : 'r';
    }
};


class Knight : public Figure {
public:
    Knight(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        int dx = absolute(newX - x);
        int dy = absolute(newY - y);
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }

    char getSymbol() const override {
        return (color == "white") ? 'N' : 'n';
    }
};


class Bishop : public Figure {
public:
    Bishop(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        return absolute(newX - x) == absolute(newY - y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'B' : 'b';
    }
};


class Queen : public Figure {
public:
    Queen(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x) || (absolute(newX - x) == absolute(newY - y));
    }

    char getSymbol() const override {
        return (color == "white") ? 'Q' : 'q';
    }
};


class King : public Figure {
public:
    King(const string& color, string name, int x, int y) : Figure(color, name, x, y) {}

    bool canMove(int newX, int newY) const override {
        int dx = absolute(newX - x);
        int dy = absolute(newY - y);
        return (dx <= 1 && dy <= 1);
    }

    char getSymbol() const override {
        return (color == "white") ? 'K' : 'k';
    }
};
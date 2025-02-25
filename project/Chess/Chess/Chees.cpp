
#include <iostream>
#include <string>

using namespace std;

// Функция для вычисления модуля числа
int absolute(int value) {
    return (value < 0) ? -value : value;
}

// Базовый класс для шахматной фигуры
class ChessPiece {
protected:
    string color;
    int x, y;

public:
    ChessPiece(const string& color, int x, int y) : color(color), x(x), y(y) {}

    virtual ~ChessPiece() {}

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
class Pawn : public ChessPiece {
public:
    Pawn(const string& color, int x, int y) : ChessPiece(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        int direction = (color == "white") ? 1 : -1;
        return (newX == x) && (newY == y + direction);
    }

    char getSymbol() const override {
        return (color == "white") ? 'P' : 'p';
    }
};

// Класс для ладьи
class Rook : public ChessPiece {
public:
    Rook(const string& color, int x, int y) : ChessPiece(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x) || (newY == y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'R' : 'r';
    }
};

// Класс для коня
class Knight : public ChessPiece {
public:
    Knight(const string& color, int x, int y) : ChessPiece(color, x, y) {}

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
class Bishop : public ChessPiece {
public:
    Bishop(const string& color, int x, int y) : ChessPiece(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return absolute(newX - x) == absolute(newY - y);
    }

    char getSymbol() const override {
        return (color == "white") ? 'B' : 'b';
    }
};

// Класс для ферзя
class Queen : public ChessPiece {
public:
    Queen(const string& color, int x, int y) : ChessPiece(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        return (newX == x) ?????????????(absolute(newX - x) == absolute(newY - y));
    }

    char getSymbol() const override {
        return (color == "white") ? 'Q' : 'q';
    }
};

// Класс для короля
class King : public ChessPiece {
public:
    King(const string& color, int x, int y) : ChessPiece(color, x, y) {}

    bool canMove(int newX, int newY) const override {
        int dx = absolute(newX - x);
        int dy = absolute(newY - y);
        return (dx <= 1 && dy <= 1);
    }

    char getSymbol() const override {
        return (color == "white") ? 'K' : 'k';
    }
};

// Класс для шахматной доски
class ChessBoard {
private:
    static const int SIZE = 8;
    ChessPiece* board[SIZE][SIZE];

public:
    ChessBoard() {
        // Инициализация доски пустыми указателями
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = nullptr;
            }
        }
    }

    ~ChessBoard() {
        // Освобождение памяти
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] != nullptr) {
                    delete board[i][j];
                }
            }
        }
    }

    // Метод для размещения фигуры на доске
    void

   
    placePiece(ChessPiece* piece, int x, int y) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            board[x][y] = piece;
        }
    }

    // Метод для отображения доски
    void display() const {
        cout << "  a b c d e f g h\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << 8 - i << " ";
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] != nullptr) {
                    cout << board[i][j]->getSymbol() << " ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << 8 - i << "\n";
        }
        cout << "  a b c d e f g h\n";
    }

    // Метод для перемещения фигуры
    void movePiece(int x1, int y1, int x2, int y2) {
        if (x1 >= 0 && x1 < SIZE && y1 >= 0 && y1 < SIZE &&
            x2 >= 0 && x2 < SIZE && y2 >= 0 && y2 < SIZE) {
            ChessPiece* piece = board[x1][y1];
            if (piece != nullptr && piece->canMove(x2, y2)) {
                board[x2][y2] = piece;
                board[x1][y1] = nullptr;
                piece->move(x2, y2);
            }
            else {
                cout << "Invalid move\n";
            }
        }
        else {
            cout << "Out of board bounds\n";
        }
    }
};

int main() {
    ChessBoard board;

    // Размещение фигур на доске
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

    // Отображение доски
    board.display();

    // Пример хода
    board.movePiece(1, 0, 2, 0); // Белая пешка
    board.movePiece(6, 0, 5, 0); // Черная пешка
    board.display();

    return 0;
}

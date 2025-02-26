#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = nullptr;
        }
    }
    initializeBoard();
}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete board[i][j];
        }
    }
}

void ChessBoard::initializeBoard() {
    // Расстановка фигур
    board[0][0] = new Rook("black");
    board[0][1] = new Knight("black");
    board[0][2] = new Bishop("black");
    board[0][3] = new Queen("black");
    board[0][4] = new King("black");
    board[0][5] = new Bishop("black");
    board[0][6] = new Knight("black");
    board[0][7] = new Rook("black");

    for (int i = 0; i < 8; ++i) {
        board[1][i] = new Pawn("black");
    }

    for (int i = 0; i < 8; ++i) {
        board[6][i] = new Pawn("white");
    }

    board[7][0] = new Rook("white");
    board[7][1] = new Knight("white");
    board[7][2] = new Bishop("white");
    board[7][3] = new Queen("white");
    board[7][4] = new King("white");
    board[7][5] = new Bishop("white");
    board[7][6] = new Knight("white");
    board[7][7] = new Rook("white");
}

void ChessBoard::displayBoard() const {
    // Верхняя граница доски
    cout << "   ";
    for (int i = 0; i < 8; ++i) {
        cout << "+-----";
    }
    cout << "+" << endl;

    // Отображение строк доски
    for (int i = 0; i < 8; ++i) {
        cout << " " << 8 - i << " "; // Номер строки
        for (int j = 0; j < 8; ++j) {
            cout << "|";
            if (board[i][j] == nullptr) {
                cout << "     "; // Пустая клетка
            }
            else {
                string pieceName = board[i][j]->getName();
                string color = board[i][j]->getColor();
                string symbol = pieceName.substr(0, 1); // Первая буква названия фигуры
                if (color == "black") {
                    symbol = "\033[1;31m" + symbol + "\033[0m"; // Красный цвет для черных фигур
                }
                else {
                    symbol = "\033[1;34m" + symbol + "\033[0m"; // Синий цвет для белых фигур
                }
                cout << "  " << symbol << "  "; // Фигура с отступами
            }
        }
        cout << "| " << 8 - i << endl; // Номер строки

        // Горизонтальная линия между строками
        cout << "   ";
        for (int j = 0; j < 8; ++j) {
            cout << "+-----";
        }
        cout << "+" << endl;
    }

    // Буквы для обозначения столбцов
    cout << "     ";
    for (int i = 0; i < 8; ++i) {
        cout << "  " << char('a' + i) << "   ";
    }
    cout << endl;
}
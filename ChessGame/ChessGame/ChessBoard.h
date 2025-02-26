#include<string>
#include"Figure.h"
class ChessBoard
{
private:
    static const int SIZE = 8;
    Figure* board[SIZE][SIZE];

public:
    ChessBoard() {

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = nullptr;
            }
        }
    }

    ~ChessBoard() {

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] != nullptr) {
                    delete board[i][j];
                }
            }
        }
    }


    void placePiece(Figure* piece, int x, int y) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            board[x][y] = piece;
        }
    }


    void display() const {
        cout << "   ";
        for (int i = 0; i < 8; ++i) {
            cout << "+-----";
        }
        cout << "+" << endl;

        // ����������� ����� �����
        for (int i = 0; i < 8; ++i) {
            cout << " " << 8 - i << " "; // ����� ������
            for (int j = 0; j < 8; ++j) {
                cout << "|";
                if (board[i][j] == nullptr) {
                    cout << "     "; // ������ ������
                }
                else {
                    string pieceName = board[i][j]->getName();
                    string color = board[i][j]->getColor();
                    string symbol = pieceName.substr(0, 1); // ������ ����� �������� ������
                    if (color == "black") {
                        symbol = "\033[1;31m" + symbol + "\033[0m"; // ������� ���� ��� ������ �����
                    }
                    else {
                        symbol = "\033[1;34m" + symbol + "\033[0m"; // ����� ���� ��� ����� �����
                    }
                    cout << "  " << symbol << "  "; // ������ � ���������
                }
            }
            cout << "| " << 8 - i << endl; // ����� ������

            // �������������� ����� ����� ��������
            cout << "   ";
            for (int j = 0; j < 8; ++j) {
                cout << "+-----";
            }
            cout << "+" << endl;
        }

        // ����� ��� ����������� ��������
        cout << "     ";
        for (int i = 0; i < 8; ++i) {
            cout << "  " << char('a' + i) << "   ";
        }
        cout << endl;
    }


    void movePiece(int x1, int y1, int x2, int y2) {
        if (x1 >= 0 && x1 < SIZE && y1 >= 0 && y1 < SIZE &&
            x2 >= 0 && x2 < SIZE && y2 >= 0 && y2 < SIZE) {
            Figure* piece = board[x1][y1];
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
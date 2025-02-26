#include"Figure.h"
__interface IViewChess
{
	void placePiece(Figure* piece, int x, int y);
	void display() const;
};
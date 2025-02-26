#include<iostream>
#include"ChessBoard.h"
#include"Poll.h"
class MCore {
protected:
	Poll chessboard;
public:
	void starGame() {
		chessboard.init();
		chessboard.display();
	}
	
};
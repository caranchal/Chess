#pragma
#include<iostream>
#include"Poll.h"
class MCore {
protected:
	Poll chessboard;
public:
	MCore() 
	{

	}
	void starGame() {
		chessboard.init();
		chessboard.display();
	}
	void Move(int x1, int y1, int x2, int y2) {
		chessboard.Move(x1, y1, x2, y2);
	}

};
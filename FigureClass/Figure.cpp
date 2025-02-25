#include<iostream>
#include<string>
using namespace std;
class Figure {
protected:
	string color;
	int x, y;
public:
	string getColor() {
		return color;
	}
	void setColor(string color) {
		this->color = color;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setX(int x) {
		this->y = y;
	}
	Figure(string color, int x, int y) {
		this->color = color;
		this->x = x;
		this->y = y;
	}
	Figure() {
		this->color = "";
		this->x = 0;
		this->y = 0;
	}
	virtual void Init();
	virtual void Move();
	virtual bool IsDead();
};

class Queen : public Figure
{
public:
	Queen(string color,int x,int y) :Figure(color,x,y){

	}
	void Init(){}
	void Move(){}
	bool IsDead() {}
};
class Pawn : public Figure
{
public:
	Pawn(string color, int x, int y) :Figure(color, x, y) {

	}
	void Init(){}
	void Move(){}
	bool IsDead(){}
};
class King : public Figure
{
public:
	King(string color, int x, int y) :Figure(color, x, y) {

	}
	void Init() {}
	void Move() {}
	bool IsDead(){}
};
class Elephant : public Figure
{
public:
	Elephant(string color, int x, int y) :Figure(color, x, y) {}
	void Init(){}
	void Move(){}
	bool IsDead() {}
};
class Rook : public Figure
{
public:
	Rook(string color, int x, int y) :Figure(color, x, y){}
	void Init(){}
	void Move(){}
	bool IsDead() {}
};
class Knight : public Figure
{
public:
	Knight(string color, int x, int y) :Figure(color, x, y){}
	void Init(){}
	void Move(){}
	bool IsDead() {}
};

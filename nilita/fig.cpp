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
	virtual void Init()=0;
	virtual void Move()=0;
	virtual bool IsDead()=0;
};

class Queen : public Figure {
public:
	Queen(string color, int x, int y) : Figure(color, x, y) {}

	void Init() override  {//указываем, что этот метод предназначен для переопределения.
		cout << "Queen postavili na pos (" << this->x << ", " << this->y << ") with color " << this->color << endl;//выводим королеву на поз,потом используем указатель this->x чтобы опеределить местеположение фигуры,аналогично с y.
	};
	bool Move(int newX, int newY) {
		int dx = std::abs(newX - x); //вычисляем разность между новыми кор,и старыми.
		int dy = std::abs(newY - y);//вычисляем разность между новыми кор,и старыми.
		return (dx == dy) || (dx == 0) || (dy == 0);//проверяем ход королевы .
	}
	bool IsDead() {
		
		return false; 
	}
	};
class Pawn : public Figure {
public:
	Pawn(string color, int x, int y) : Figure(color, x, y) {}

	void Init() {
		                           
		if (color == "white") {// Устанавливаем начальные позиции для пешек.
			y = 1; // Пешка белого цвета начинает  на второй  линии.
		}
		else if (color == "black") {
			y = 6; // Пешка черного цвета стартует на седьмой линии.
		}
	}

	bool Move(int newX, int newY) {
		int direction = (color == "white") ? 1 : -1;//используем тернарный оператор,чтобы опередлить будет ли фигура белой?или всё таки черной?
		return (newX == this->x) && (newY == this->y + direction);// Используем this-> для доступа к x и y, если они защищены в базовом классе.
	}
	bool IsDead() {

		return false;
};
};
class King : public Figure
{
public:
	King(string color, int x, int y) :Figure(color, x, y) {}

	void Init() {
	}
	bool Move(int newX, int newY) {
		int dx = abs(newX - x);//вычисляем разность между новыми кор,и старыми.
		int dy = abs(newY - y);//вычисляем разность между новыми кор,и старыми.
		return (dx <= 1 && dy <= 1);//проверяем ход короля.
	};
};
bool IsDead() {
	return false;
};

	
	class Elephant : public Figure
	{
	public:
		Elephant(string color, int x, int y) :Figure(color, x, y) {}
		void Init() {
		}
		bool Move(int newX, int newY) {
			return abs(newX - x) == abs(newY - y);//вычисляем разность между новыми кор,и старыми.
		}
		bool IsDead(){
			return false;
}
};
class Rook : public Figure
{
public:
	Rook(string color, int x, int y) :Figure(color, x, y) {}
	void Init() {
	}
	bool Move(int newX, int newY) {
		return (newX == x) || (newY == y);//вычисляем разность между новыми кор,и старыми.
	}
	bool IsDead() {
		return false;
	};

};
class Knight : public Figure
{
public:
	Knight(string color, int x, int y) :Figure(color, x, y) {}
	void Init() {
	}
	bool Move(int newX, int newY) {
		int dx = abs(newX - x);//вычисляем разность между новыми кор,и старыми.
		int dy = abs(newY - y);//вычисляем разность между новыми кор,и старыми.
		return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);//проверяем ход коня.
	};
	
	bool IsDead() {
		return false;
	};
};

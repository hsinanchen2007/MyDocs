//d:\Ex13\Ex1301.cpp
//Point �P Square �~�����O
#include <iostream>
using namespace std;

class Point
{
protected:
	int x, y;
public:
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	void setpoint(int x1, int y1)
	{
		x = x1; y = y1;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};

class Square: public Point
{
protected:
	int area()
	{
		return x * y;
	}
public:
	Square(int x2, int y2): Point(x, y)
	{
		setpoint(x2, y2);
	}
	int getarea()
	{
		return area();
	}
};

int main(int argc, char** argv) {
	Square p(5, 5);
	cout << "�y�� = " << "p(" << p.getx() << ", " << p.gety() << ')' << endl
		 << "���n = " << p.getarea() << " ���褽��" << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}

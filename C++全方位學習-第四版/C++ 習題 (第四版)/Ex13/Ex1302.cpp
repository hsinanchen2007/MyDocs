//d:\Ex13\Ex1302.cpp
//Point 與 Square 包含類別
#include <iostream>
using namespace std;

class Point
{
protected:
	int x, y;
public:
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

class Square
{
protected:
	int area()
	{
		return ps.getx() * ps.gety();
	}
public:
	Point ps;
	int getarea()
	{
		return area();
	}
};

int main(int argc, char** argv) {
	Square p;
	p.ps.setpoint(5, 5);
	cout << "座標 = " << "p(" << p.ps.getx() << ", " << p.ps.gety() << ')' << endl
		 << "面積 = " << p.getarea() << " 平方公分" << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}

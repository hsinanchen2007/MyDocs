//d:\Ex14\Ex1401.cpp
//Point、Square、Circle 虛擬繼承類別
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
protected:
	double x;
public:
	Point(double x1)
	{
		x = x1;
	}
	void setPoint(double x1)
	{
		x = x1;
	}
	double getX()
	{
		return x;
	}
	virtual double getArea() const = 0;
};

class Square: public Point
{
protected:
	double area() const
	{
		return pow(x, 2);
	}
public:
	Square(double x2): Point(x)
	{
		setPoint(x2);
	}
	double getArea() const
	{
		return area();
	}
};

class Circle: public Point
{
protected:
	double area() const
	{
		return 3.1415926 * pow(x, 2);
	}
public:
	Circle(double x2): Point(x)
	{
		setPoint(x2);
	}
	double getArea() const
	{
		return area();
	}
};

int main(int argc, char** argv) {
	Square s(5);
	Circle c(4);
	cout << "正方形面積 = " << s.getArea() << " 平方公分" << endl;
	cout << "圓形面積 = " << c.getArea() << " 平方公分" << endl;
	system("PAUSE");
	return 0;
}

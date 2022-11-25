//d:\Ex14\Ex1402.cpp
//Point、Square、Circle 與 Cylinder 虛擬繼承類別
#include <iostream>
#include <math.h>
using namespace std;

class Point
{
protected:
	double r, h;
public:
	Point(double r1, double h1)
	{
		r = r1; h = h1;
	}
	void setPoint(double r1, double h1)
	{
		r = r1; h = h1;
	}
	double getR()
	{
		return r;
	}
	double getH()
	{
		return h;
	}
};

class Rectangle: public Point
{
protected:
	double area() const
	{
		return pow(h, 2);
	}
public:
	Rectangle(double r2, double h2): Point(r2, h2)
	{	}
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
		return 3.1415926 * pow(r, 2);
	}
public:
	Circle(double r2, double h2): Point(r2, h2)
	{	}
	double getArea() const
	{
		return area();
	}
};

class Cylinder: public Rectangle, public Circle
{
protected:
	int volume() const
	{
		return Circle::getArea() * Rectangle::h;
	}
public:
	Cylinder(double r3, double h3): Circle(r3, h3), Rectangle(r3, h3)
	{
		Circle::setPoint(r3, h3);
	}
	int getVolume() const
	{
		return volume();
	}
};

int main(int argc, char** argv) {
	Cylinder cy(5, 6);
	cout << "正方形面積 = " << cy.Rectangle::getArea() << " 平方公分" << endl;
	cout << "圓面積 = " << cy.Circle::getArea() << " 平方公分" << endl;
	cout << "圓柱體積 = " << cy.getVolume() << " 立方公分" << endl;
	system("PAUSE");
	return 0;
}

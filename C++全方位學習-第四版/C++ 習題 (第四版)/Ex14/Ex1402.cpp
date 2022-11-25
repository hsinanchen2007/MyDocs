//d:\Ex14\Ex1402.cpp
//Point�BSquare�BCircle �P Cylinder �����~�����O
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
	cout << "����έ��n = " << cy.Rectangle::getArea() << " ���褽��" << endl;
	cout << "�ꭱ�n = " << cy.Circle::getArea() << " ���褽��" << endl;
	cout << "��W��n = " << cy.getVolume() << " �ߤ褽��" << endl;
	system("PAUSE");
	return 0;
}

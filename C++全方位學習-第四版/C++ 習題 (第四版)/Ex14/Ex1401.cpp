//d:\Ex14\Ex1401.cpp
//Point�BSquare�BCircle �����~�����O
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
	cout << "����έ��n = " << s.getArea() << " ���褽��" << endl;
	cout << "��έ��n = " << c.getArea() << " ���褽��" << endl;
	system("PAUSE");
	return 0;
}

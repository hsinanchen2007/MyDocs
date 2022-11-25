//d:\Ex11\Ex1101.cpp
//長方形類別
#include <iostream>
using namespace std;

class Rectangle
{
	int length;
	int width;
public:
	Rectangle()
	{
		length = 1;
		width = 1;
	}
	void setlength(int l)
	{
		length = l;
	}
	void setwidth(int w)
	{
		width = w;
	}
	int getlength()
	{
		return length;
	}
	int getwidth()
	{
		return width;
	}
	int perimeter()
	{
		return 2 * (length + width);
	}
	int area()
	{
		return length * width;
	}
};

int main(int argc, char** argv) {
	Rectangle rect;
	int l, w;
	cout << "請輸入長方形的長 (公分)：";
	cin >> l;
	rect.setlength(l);
	cout << "請輸入長方形的寬 (公分)：";
	cin >> w;
	rect.setwidth(w);
	cout << "長方形周長 = " << rect.perimeter() << "公分" << endl;
	cout << "長方形面積 = " << rect.area() << "平方公分" << endl;
	system("PAUSE");
	return 0;
}

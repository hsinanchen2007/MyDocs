//d:\Ex11\Ex1101.cpp
//��������O
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
	cout << "�п�J����Ϊ��� (����)�G";
	cin >> l;
	rect.setlength(l);
	cout << "�п�J����Ϊ��e (����)�G";
	cin >> w;
	rect.setwidth(w);
	cout << "����ΩP�� = " << rect.perimeter() << "����" << endl;
	cout << "����έ��n = " << rect.area() << "���褽��" << endl;
	system("PAUSE");
	return 0;
}

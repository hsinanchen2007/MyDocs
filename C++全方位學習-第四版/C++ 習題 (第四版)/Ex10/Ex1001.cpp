//d:\Ex10\Ex1001.cpp
//����ε��c
#include <iostream>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int perimeter(int l, int w)
{
	return 2 * (l + w);
}

int area(int l, int w)
{
	return l * w;
}

int main(int argc, char** argv) {
	Rectangle rect;
	cout << "�п�J����Ϊ��� (����)�G";
	cin >> rect.length;
	cout << "�п�J����Ϊ��e (����)�G";
	cin >> rect.width;
	cout << "����ΩP�� = " << perimeter(rect.length, rect.width) << "����" << endl;
	cout << "����έ��n = " << area(rect.length, rect.width) << "���褽��" << endl;
	system("PAUSE");
	return 0;
}

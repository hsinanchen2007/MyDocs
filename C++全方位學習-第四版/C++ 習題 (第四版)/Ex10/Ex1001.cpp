//d:\Ex10\Ex1001.cpp
//長方形結構
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
	cout << "請輸入長方形的長 (公分)：";
	cin >> rect.length;
	cout << "請輸入長方形的寬 (公分)：";
	cin >> rect.width;
	cout << "長方形周長 = " << perimeter(rect.length, rect.width) << "公分" << endl;
	cout << "長方形面積 = " << area(rect.length, rect.width) << "平方公分" << endl;
	system("PAUSE");
	return 0;
}

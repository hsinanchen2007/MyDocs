//d:\EX03\Ex0301.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	float radius;
	cout << "請輸入圓半徑：";
	cin >> radius;

	float pi = (float)3.14159;
	float perimeter = 2 * pi * radius;
	float area = pi * radius * radius;

	cout << "半徑 = " << radius << " 公分" << endl
		 << "圓周長 = " << perimeter << " 公分" << endl
		 << "圓面積 = " << area << " 平方公分" << endl;
	system("PAUSE");
	return 0;
}

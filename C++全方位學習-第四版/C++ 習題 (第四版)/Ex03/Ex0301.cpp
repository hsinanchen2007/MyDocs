//d:\EX03\Ex0301.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	float radius;
	cout << "�п�J��b�|�G";
	cin >> radius;

	float pi = (float)3.14159;
	float perimeter = 2 * pi * radius;
	float area = pi * radius * radius;

	cout << "�b�| = " << radius << " ����" << endl
		 << "��P�� = " << perimeter << " ����" << endl
		 << "�ꭱ�n = " << area << " ���褽��" << endl;
	system("PAUSE");
	return 0;
}

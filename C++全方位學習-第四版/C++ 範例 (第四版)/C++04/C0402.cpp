//�x�s�ɦW�Gd:\C++04\C0402.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a = 1, b = 4, c = 4;	//�ŧi�ñҩl a, b, c ��
	bool x = !(a < b && b == c || c <=a);	//�ŧi�ë��w x ��
	cout << "a=" << a << endl;	//��X�r��Ba �ȡB����
	cout << "b=" << b << endl;	//��X�r��Bb �ȡB����
	cout << "c=" << c << endl;	//��X�r��Bc �ȡB����
	cout << "!(a<b && b==c || c<=a) = " << x << endl;	//��X�r��Bx ��
	return 0;
}

//�x�s�ɦW�Gd:\C++04\C0401.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a = 1, b = 4, c = 4;	//�ŧi�ñҩl a, b, c ��
	cout << "a=" << a << endl;	//��X�r��Ba �ȡB����
	cout << "b=" << b << endl;	//��X�r��Bb �ȡB����
	cout << "c=" << c << endl;	//��X�r��Bc �ȡB����
	bool x = a<b, y = c>=a;
	cout << "a<b �� " << x << endl;	//��X�r��Ba<b ��
	cout << "c>=a �� " << y << endl;	//��X�r��Bc>=a ��
	cout << "a!=b �� " << (a!=b) << endl;	//��X�r��Ba!=b ��
	cout << "a==c �� " << (a==c) << endl;	//��X�r��Ba==c ��
	return 0;
}

//�x�s�ɦW�Gd:\C++05\C0517.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	int x;	//while�j����
	double sine;	//�ŧix�ܼ�
	cout << " x\t" << "sin(x)\n";	//��X�r��
	for (x=0; x<=90; x+=15)	//�P�_x<=90��A�[15
	{
		sine = sin(PI * x / 180);	//�p��sin(x)
		cout << setprecision(3) << setiosflags(ios::fixed);	//�]�w��X�榡
		cout << setw(2) << x << '\t';	//��X�p�ƭ�
		cout << setw(6) << sine << endl;	//��Xsin��
	}
	return 0;
}

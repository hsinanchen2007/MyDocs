//�x�s�ɦW�Gd:\C++03\C0307.cpp
#include <iostream>
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	cout.precision(2); 	//�]�w2�즳�Ħ��
	cout.setf(ios::fixed);	//�אּ2��p�Ʀ��ļƦr
	cout.width(10);	//�]�w��X�Ŷ���10��
	cout << PI * -1 << endl;	//��XPI*-1
	cout.width(10);	//�]�w��X�Ŷ���10��
	cout << PI * 100 << endl;	//��XPI*100
	cout.width(10);	//�]�w��X�Ŷ���10��
	cout << PI * 10000 << endl; 	//��XPI*10000
	return 0;
}

//�x�s�ɦW�Gd:\C++03\C0306.cpp
#include <iostream>
#include <iomanip>	//�]�tsetprecision()
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	cout << setprecision(2) << setiosflags(ios::fixed);	//�]�w2��p�Ʀ��ļ�
	cout << setw(10) << PI * -1 << endl; 	//�]�w10�Ŷ���XPI*-1
	cout << setw(10) << PI * 100 << endl; 	//�]�w10�Ŷ���XPI*100
	cout << setw(10) << PI * 10000 << endl; 	//�]�w10�Ŷ���XPI*10000
	return 0;
}

//�x�s�ɦW�Gd:\C++03\C0324.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//�ƭȨ�Ƽ��D��
using namespace std;

int main(int argc, char** argv)
{
	float x;	//�ŧi�B�I���ܼ�

	cout << "�п�J�B�I�ơG";
	cin >> x;	//���o��L��J
	cout << setprecision(2) << setiosflags(ios::fixed);	//�]�w���Ħ��
	cout << "x = " << x;	//��X�ƭ�
	cout << "\npow(" << x << ") = " << pow(x, 2);	//��Xx�������
	cout << "\nsqrt(" << x << ") = " << sqrt(x);	//��Xx���}���
	cout << endl;     //��X���� 
	return 0;
}

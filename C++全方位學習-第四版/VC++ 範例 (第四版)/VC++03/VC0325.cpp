//�x�s�ɦW�Gd:\VC++03\VC0325\VC0325.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//�ƭȨ�Ƽ��D��

using namespace std;

int main(int argc, char** argv)
{
	float x;	//�ŧi�B�I���ܼ�

	cout << "�п�J�B�I�ơG";
	cin >> x;	//���o��L��J
	cout << "x = " << x;	//��X�ƭ�
	cout << "\nceil(" << x << ") = " << ceil(x);	//��X�j��x�����
	cout << "\nfloor(" << x << ") = " << floor(x);	//��X�p��x�����
	cout << endl;           //��X���� 
	return 0;
}

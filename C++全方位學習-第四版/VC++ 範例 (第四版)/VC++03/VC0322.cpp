//�x�s�ɦW�Gd:\VC++03\VC0322\VC0322.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//�ƭȨ�Ƽ��D��
using namespace std;

int main(int argc, char** argv)
{
	float degree = (3.1415926f) / 180;	//degree=�|/��
	int d;		//�ŧi����ܼ�

	cout << "�п�J��ơG";
	cin >> d;	//���o��L��J
	cout << setprecision(3) << setiosflags(ios::fixed);	//�]�w���Ħ��
	cout << "d = " << d << endl;	//��X����
	cout << "sin(" << d << ") = " << sin(degree*d) << endl;	//��X������ƭ�
	cout << "cos(" << d << ") = " << cos(degree*d) << endl;	//��X�l����ƭ�
	cout << "tan(" << d << ") = " << tan(degree*d) << endl;	//��X������ƭ�
	return 0;
}

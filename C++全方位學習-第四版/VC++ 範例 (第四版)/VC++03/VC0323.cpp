//�x�s�ɦW�Gd:\VC++03\VC0323\VC0323.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//�ƭȨ�Ƽ��D��
using namespace std;

int main(int argc, char** argv)
{
	int x;		//�ŧi����ܼ�

	cout << "�п�J��ơG";
	cin >> x;	//���o��L��J
	cout << setprecision(3) << setiosflags(ios::fixed);	//�]�w���Ħ��
	cout << "x = " << x;	//��X�ƭ�
	cout << "\nlog(" << x << ") = " << log(x);	//��X�۵M��ƭ�
	cout << "\nlog10(" << x << ") = " << log10(x);	//��X��10��ƭ�
	cout << "\nexp(" << x << ") = " << exp(x);	//��X e ��x�����
	cout << endl;
	return 0;
}

//�x�s�ɦW�Gd:\VC++04\VC0405\VC0405.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cout << "�п�J�@��ơG";
	int number;	//�ŧi����ܼ�
	cin >> number;	//��Jnumber���
	if (number % 2 == 0)	//�Ynumber/2�l�Ƭ�0
		cout << number << " �O����\n";	//�h��ܰT��1
	else			//�_�h
		cout << number << " �O�_��\n";	//�h��ܰT��2
	return 0;
}

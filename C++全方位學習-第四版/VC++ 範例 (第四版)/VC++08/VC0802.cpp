//�ɮצW�١Gd:\VC++08\VC0802\VC0802.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int number = 10;	//�ŧi����ܼ�
	int *numPtr = 0;	//�ŧi�����ܼ�
	cout << "number = " << number << endl;	//��Xnumber��
	cout << "numPtr(���_�l) = " << numPtr << endl;	//��X���_�l����

	numPtr = &number;	//numPtr�Onumber����
	cout << "*numPtr = " << *numPtr << endl;	//��X�������o�����
	cout << "numPtr = &number = " << numPtr << endl;    //��Xnumber����
	return 0;
}

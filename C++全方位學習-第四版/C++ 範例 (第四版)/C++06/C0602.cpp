//�x�s�ɦW�Gd:\C++06\C0602.cpp
#include <iostream>
using namespace std;

void sub1(void)	//�ϥΪ̨��1
{
	cout << "�i�J sub1 ���\n";
}

void sub2(void)	//�ϥΪ̨��2
{
	cout << "�i�J sub2 ���\n";
}

int main(int argc, char** argv)
{
	cout << "�_�l main ���\n";
	sub1();		//�I�ssub1
	cout << "��^ main ���\n";
	sub2();		//�I�ssub2
	cout << "��^ main ���\n";
	return 0;
}

//�x�s�ɦW�Gd:\C++06\C0603.cpp
#include <iostream>
using namespace std;

void grandUser(void)	//�ϥΪ̨��2
{
	cout << "�i�J grandUser ���\n";
}

void childUser(void)	//�ϥΪ̨��1
{
	cout << "�i�J childUser ���\n";
	grandUser();	//�I�sgrandUser���
	cout << "��^ childUser ���\n";
}

int main(int argc, char** argv)
{
	cout << "�_�l main ���\n";
	childUser();	//�I�schildUser
	cout << "��^ main ���\n";
	return 0;
}

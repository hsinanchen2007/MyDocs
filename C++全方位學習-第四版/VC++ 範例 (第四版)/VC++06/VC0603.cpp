//�x�s�ɦW�Gd:\VC++06\VC0603\VC0603.cpp
#include <iostream>
using namespace std;

void grandUser(void)	//�ϥΪ̨��2
{
	cout << "�i�J grandUser ���\n";
}

void subUser(void)	//�ϥΪ̨��1
{
	cout << "�i�J subUser ���\n";
	grandUser();	//�I�sgrandUser���
	cout << "��^ subUser ���\n";
}

int main(int argc, char** argv)
{
	cout << "�_�l main ���\n";
	subUser();	//�I�ssubUser
	cout << "��^ main ���\n";
	return 0;
}

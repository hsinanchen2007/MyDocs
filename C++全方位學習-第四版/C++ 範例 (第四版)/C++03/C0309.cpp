//�x�s�ɦW�Gd:\C++03\C0309.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char string[5];	//�ŧi�r���ܼ�string
	cout << "�п�J�r��G";	//��X�T���r��
	cin.width(5);	//�]�w��J�r����
	cin >> string;	//���o��J�r��
	cout << "��J�r��O�G" << string << endl;	//��ܰT���P��J�r��
	return 0;
}

//�x�s�ɦW�Gd:\VC++03\VC0309\VC0309.cpp
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

//�x�s�ɦW�Gd:\C++03\C0312.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int num;	//�ŧi����ܼ�
	char key;	//�ŧi�r���ܼ�
	cout << "�п�J�@��ơG";	//��X�T���r��
	cin >> num;	//Ū���ƭȨæs�Jnum
	cin.ignore();	//�����e�@��J�r��Enter
	cout << "�Ы�Enter�����G";	//��X�T���r��
	cin.get(key);	//���o��L����
	cout << "���¡I\n";	//��ܰT��
	return 0;
}

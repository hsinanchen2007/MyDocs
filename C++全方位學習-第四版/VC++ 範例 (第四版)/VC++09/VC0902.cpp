//�ɮצW�١Gd:\VC++09\VC0902\VC0902.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

int main(int argc, char** argv)
{
	char source[80], target[80];
	cout << "�п�J�ӷ��r��G";	//��ܰT���r��
	cin.getline(source, 80, '\n');	//���o�ӷ��r��
	strcpy_s(target, source);	//�ƻs�r��
	cout << "�ƻs��ت��r��G" << target;	//��ܥت��r��
	cout << endl;
	return 0;
}

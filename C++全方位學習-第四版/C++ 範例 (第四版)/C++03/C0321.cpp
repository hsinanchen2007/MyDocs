//�x�s�ɦW�Gd:\C++03\C0321.cpp
#include <iostream>	//���J�r����D��
#include <cstdlib>	//���J�üƨ�Ƽ��D��
#include <ctime>	//���J�ɶ���Ƽ��D��
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));	//�H�ɶ���Ƭ��ؤl��
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//��X1-10�������ü�
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//��X1-10�������ü�
	cout << 1 + rand() % (10 - 1 + 1) << endl;	//��X1-10�������ü�
	return 0;
}

//�x�s�ɦW�Gd:\VC++03\VC0320\VC0320.cpp
#include <iostream>
#include <cstdlib>	//���J�üƨ�Ƽ��D��
#include <ctime>	//���J�ɶ���Ƽ��D��
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));	//�H�ɶ���Ƭ��ؤl��
	cout << rand() << endl;	//��X�ü�
	cout << rand() << endl;	//��X�ü�
	cout << rand() << endl;	//��X�ü�
	return 0;
}

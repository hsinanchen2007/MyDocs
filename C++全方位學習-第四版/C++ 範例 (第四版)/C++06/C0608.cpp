// �x�s�ɦW�Gd:\C++06\C0608.cpp
#include <iostream>
using namespace std;

void calculate(int, int, int);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	int chinese, english, math;	//�ŧi����ܼ�

	for (int i=0; i<3; i++)
	{
		cout << "�п�J���, �^��, �ƾǤ��ơG";
		cin >> chinese >> english >> math;	//��J3�Ӽƭ�
		calculate(chinese, english, math);	//�ǻ�3�ӰѼƵ�sum���
	}
	return 0;
}

void calculate(int c, int e, int m)	//�p���`�M�P�������
{
	cout << "�`�� = " << c + e + m << endl;	//�p��ÿ�X�`�M
	cout << "���� = " << float((c + e + m) / 3);	//�p��ÿ�X����
	cout  << endl;
}

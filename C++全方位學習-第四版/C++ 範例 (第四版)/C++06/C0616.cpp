//�x�s�ɦW�Gd:\C++06\C0616.cpp
#include <iostream>
#include <iomanip>
#include "C0616.h"	//���J�۫ؼ��D��
using namespace std;

double c;		//�ŧi�����ܼ�

int main(int argc, char** argv)
{
	cout << "���\t �ؤ�\n";	//��ܦr��
	cout << setprecision(2);	//�]�w2�즳�Ħ��
	cout << setiosflags(ios::fixed|ios::right);	//�אּ2��p�Ʀ��Ħ��
	for (c = 36; c <= 40; c++)	//���ū�=�p��
	{
		cout << setw(5) << c << '\t';	//��ܭ^�ح�
		cout << setw(6) << degree() << '\n';	//��ܨ�ƶǦ^���ح�
	}
	return 0;
}

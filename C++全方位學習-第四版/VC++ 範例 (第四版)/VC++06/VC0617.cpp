//�x�s�ɦW�Gd:\VC++06\VC0617\VC0617.cpp
#include <iostream>
#include <iomanip>
using namespace std;

double degree(double);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	register double f;	//�ŧi�Ȧs���ܼ�
	cout << " �ؤ�\t  ���\n";	//��ܦr��
	cout << setprecision(2);	//�]�w2�즳�Ħ��
	cout << setiosflags(ios::fixed | ios::right);	//�אּ2��p�Ʀ��Ħ��
	for (f = 96; f <= 104; f += 2)	//���ū�=�p��
	{
		cout << setw(6) << f << '\t';	//��ܵؤ��
		cout << setw(6) << degree(f) << '\n';	//��ܨ�ƶǦ^����
	}
	return 0;
}

double degree(double fahr)	//�ū��ഫ���
{
	register double c;	//�ŧi�Ȧs���ܼ�
	c = (fahr - 32) * 5 / 9;	//�ؤ��ন���
	return c;	//��^�öǻ�c
}

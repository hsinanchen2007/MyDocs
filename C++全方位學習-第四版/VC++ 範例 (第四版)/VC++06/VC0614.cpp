//�x�s�ɦW�Gd:\VC++06\VC0614\VC0614.cpp
#include <iostream>
#include <iomanip>
using namespace std;

double length(int);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	int ft = 0;	//�ŧi�ϰ��ܼ�

	cout << "�^�`\t" << " ����\n";	//��ܦr��
	cout << setprecision(4);	//�]�w4�즳�Ħ��
	cout << setiosflags(ios::fixed | ios::right);	//�אּ4��p�Ʀ��Ħ��
	for (ft = 1; ft <= 10; ft++)	//�H�^�`���p�ƭ�
	{
		cout << setw(3) << ft << '\t';	//��ܭ^�ح�
		cout << setw(6) << length(ft) << '\n';	//��ܨ�ƶǦ^���ح�
	}
	return 0;
}

double length(int ft)	//���q�ഫ���
{
	double m = 0.0;	//�ŧi�ϰ��ܼ�
	m = 0.3048 * double(ft);	//�^�`�ন����
	return m;	//��^�öǻ�m
}

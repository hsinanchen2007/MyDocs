//�x�s�ɦW�Gd:\VC++06\VC0615\VC0615.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void length(void);	//�ŧi��ƭ쫬
int m;		//�ŧi�����ܼ�
double ft;		//�ŧi�����ܼ�

int main(int argc, char** argv)
{
	cout << "����\t  �^�`\n";	//��ܦr��
	cout << setprecision(4);	//�]�w4�즳�Ħ��
	cout << setiosflags(ios::fixed | ios::right);	//�אּ4��p�Ʀ��Ħ��
	for (m = 1; m <= 10; m++)	//�H���ج��p�ƭ�
	{
		length();	//�I�s���
		cout << setw(3) << m << '\t';	//��X���ح�
		cout << setw(7) << ft << '\n';	//��X�^�`��
	}
	return 0;
}

void length(void)	//�����ഫ���
{
	ft = 3.20808 * double(m);	//�����ন�^�`
}

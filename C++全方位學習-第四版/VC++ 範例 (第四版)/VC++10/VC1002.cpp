//�ɮצW�١Gd:\VC++10\VC1002\VC1002.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[25];	//Booklist��1�����ܼ�
	char auther[10];	//Booklist��2�����ܼ�
	char number[10];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

int main(int argc, char** argv)
{
	Booklist CPP;	//�إ�Booklist���A�ܼ�
	strcpy_s(CPP.title, "C++ ����ɦV�{���]�p");	//���wCPP��1�������
	strcpy_s(CPP.auther, "�j�[�d\t");	//���wCPP��2�������
	strcpy_s(CPP.number, "AEL008900");	//���wCPP��3�������
	CPP.price = 520.00;	//���wCPP��4�������

	Booklist VB;	//�إ�Booklist���A�ܼ�
	strcpy_s(VB.title, "VB 2008 �оǽd��");	//���wVB��1�������
	strcpy_s(VB.auther, "�j�[�d\t");	//���wVB��2�������
	strcpy_s(VB.number, "AEL005531");	//���wVB��3�������
	VB.price = 530.00;	//���wVB��4�������

	cout.precision(2); cout.setf(ios::fixed);
	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	cout << CPP.title << '\t';	//��XCPP��1�������
	cout << CPP.auther << '\t';	//��XCPP��2�������
	cout << CPP.number << '\t';	//��XCPP��3�������
	cout << CPP.price << '\n';	//��XCPP��4�������

	cout << VB.title << '\t';	//��XVB��1�������
	cout << VB.auther << '\t';	//��XVB��2�������
	cout << VB.number << '\t';	//��XVB��3�������
	cout << VB.price << '\n';	//��XVB��4�������
	return 0;
}

//�ɮצW�١Gd:\VC++10\VC1003\VC1003.cpp
#include <iostream>
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[21];	//Booklist��1�����ܼ�
	char auther[7];	//Booklist��2�����ܼ�
	char number[10];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

int main(int argc, char** argv)
{
	//�w�q�ð_�lCPP���
	Booklist CPP = { "C++ ����ɦV�{���]�p", "�j�[�d", "AEL008900", 520.00 };
	//�w�q�ð_�lVB���
	Booklist VB = { "VB 2008 �оǽd��    ", "�j�[�d", "AEL005531", 530.00 };

	cout.precision(2); cout.setf(ios::fixed);
	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	cout << CPP.title << '\t';	//��XCPP��1�������
	cout << CPP.auther << "\t\t";	//��XCPP��2�������
	cout << CPP.number << '\t';	//��XCPP��3�������
	cout << CPP.price << '\n';	//��XCPP��4�������

	cout << VB.title << '\t';	//��XVB��1�������
	cout << VB.auther << "\t\t";	//��XVB��2�������
	cout << VB.number << '\t';	//��XVB��3�������
	cout << VB.price << '\n';	//��XVB��4�������
	return 0;
}

//�x�s�ɦW�Gd:\C++05\C0511.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char inkey;
	short num;
	short  plus = 0, minus = 0, zero = 0;
	do
	{
		cout << "�п�J -32768 �� 32767 ���ƭȡG";
		cin >> num;	//��J�������
		if (num != 0)	//�Y num ������ 0
			(num > 0) ? plus++ : minus++;	//�������B��ԭz
		else		//�_�h
			zero++;	//zero = zero + 1
		cout << "�O�_��J�U�@���ƭ� (y/n)�G";
		cin >> inkey;	//��J�r��
	} while (inkey == 'Y' || inkey == 'y');	//�Y�r��='Y'�h���ưj��
	cout << "\n���Ʀ�" << plus << "��";	//��ܥ��ƭӼ�
	cout << "\n�t�Ʀ�" << minus << "��";	//��ܭt�ƭӼ�
	cout << "\n�s��" << zero << "��\n";	//��ܹs���Ӽ�
	return 0;
}

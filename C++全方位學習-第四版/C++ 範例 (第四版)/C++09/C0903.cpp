//�ɮצW�١Gd:\C++09\C0903.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

int main(int argc, char** argv)
{
	char password[80] = "2021";	//�w�q�ñҩl�K�X
	char instring[80];
	cout << "�z�� 3 �����|�A";
	for (int i = 1; i <=3; i++)	//��J�K�X�j��
	{
		cout << "�п�J�K�X�G";
		cin.getline (instring, 80, '\n');	//���o�ӷ��r��
		int flag = strcmp(password, instring);	//����r��
		if (flag == 0)
		{
			cout << "���߱z�I�K�X���T�C";	//��ܥت��r��
			break;	//���_�j��
		}
		else
		{
			if (i != 3)	//�H�p�ƭȨM�w�A
				cout << "�٦� " << 3-i << " �����|�A";	//��ܪ��r��
			else
				cout << "�藍�_�I�S���|�F�C";
		}
	}
	cout << endl;
	return 0;
}

//�ɮצW�١Gd:\C++07\C0722.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	bool flag = false;	//�ŧi���L�ȺX��
	int i, search;	//�ŧi����ܼ�
	int number[5] = {57, 19, 33, 92, 6};	//�ŧi�ð_�lnumber�}�C
	cout << "��ܸ�ơG";
	for (i = 0; i <= 4; i++)	//��X�}�C��ưj��
		cout << number[i] << ' ';
	cout << "\n��J��ơG";
	cin >> search;		//Ū����L��J
	for (i = 0; i <= 4; i++)	//��M��ưj��
	{
		if (number[i] == search)	//�Y���==�w�ľ���
			flag = 1;
	}
	if (flag)	//�Y�����
		cout << "����ơG" << search << endl;
	else
		cout << "�䤣���ơG" << search << endl;
	return 0;
}

//�ɮצW�١Gd:\VC++07\VC0721\VC0721.cpp
#include <iostream>
using namespace std;

const int MAX = 5;	//MAX = �}�C�̤j�d��

int main(int argc, char** argv)
{
	int i, j, minimum, mindex;	//�ŧi����ܼ�
	int number[MAX] = { 57, 19, 33, 92, 6 };	//�ŧi�@���}�C
	cout << "�Ƨǫe�G";	//��ܱƧǫe���
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	for (i = 0; i < MAX - 1; i++)	//�Ƨǥ~�j��
	{
		mindex = i;	//mindex=�̤p�ȯ���
		minimum = number[i];	//minimum=�̤p��
		for (j = i + 1; j < MAX; j++)	//�ƧǤ��j��
		{
			if (number[j] < minimum)	//�Ynumber[j]<�̤p��
			{
				minimum = number[j];	//minimum=�s�̤p��
				mindex = j;	//mindex=�s�̤p�ȯ���
			}
		}
		number[mindex] = number[i];	//number[�̤p�ȯ���]=���j��
		number[i] = minimum;	//number[i]=�̤p��
	}
	cout << "\n�Ƨǫ�G";	//��ܱƧǫ���
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

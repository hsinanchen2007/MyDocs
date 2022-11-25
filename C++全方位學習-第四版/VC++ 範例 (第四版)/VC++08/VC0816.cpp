//�ɮצW�١Gd:\VC++08\VC0816\VC0816.cpp
#include <iostream>
using namespace std;

void sortArray(const int *, int *);	//�ŧi��ƭ쫬

int main(int argc, char** argv)
{
	const int SIZE = 5;	//�ŧi��`�ƲŸ�
	int number[SIZE] = { 57, 19, 33, 92, 6 };	//�ŧi�@���}�C

	cout << "�Ƨǫe�G";	//��ܱƧǫe���
	for (int i = 0; i < SIZE; i++)
		cout << number[i] << '\0';

	sortArray(&SIZE, number);	//��number���е�sortArray

	cout << "\n�Ƨǫ�G";	//��ܱƧǫ���
	for (int j = 0; j<SIZE; j++)
		cout << number[j] << '\0';
	cout << endl;
	return 0;
}

void sortArray(const int *MAX, int *array)	//��ܱƧǨ��
{
	int minimum, mindex;	//�ŧi�w�ľ��ܼ�
	for (int i = 0; i<*MAX - 1; i++)	//�Ƨǥ~�j��
	{
		mindex = i;	//mindex=�̤p�ȯ���
		minimum = *(array + i);	//minimum=�̤p��
		for (int j = i + 1; j<*MAX; j++)	//�ƧǤ��j��
		{
			if (*(array + j) < minimum)	//�Y*(array+j)<�̤p��
			{
				minimum = *(array + j);	//minimum=�s�̤p��
				mindex = j;	//mindex=�s�̤p�ȯ���
			}
		}
		*(array + mindex) = *(array + i);	//*(array+�̤p�ȯ���)=���j��
		*(array + i) = minimum;	//*(array+i)=�̤p��
	}
}

//�ɮצW�١Gd:\VC++07\VC0720\VC0720.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const int max = 5;	//�ŧi��`�ƲŸ�
	int i, j, buffer;	//�ŧi����ܼ�
	int number[max] = { 57, 19, 33, 92, 6 };	//�ŧi�@���}�C
	cout << "�Ƨǫe�G";	//��ܱƧǫe���
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	for (i = 0; i < max - 1; i++)	//�Ƨǥ~�j��
		for (j = i; j < max; j++)	//�ƧǤ��j��
			if (number[i] > number[j])	//�Y���n�h���
			{
				buffer = number[i];
				number[i] = number[j];
				number[j] = buffer;
			}
	cout << "\n�Ƨǫ�G";	//��ܱƧǫ���
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

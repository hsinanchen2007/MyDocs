//�ɮצW�١Gd:\VC++07\VC++07\VC0723.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const int max = 5;	//�ŧi�`�ƲŸ�
	int i, j, buffer;	//�ŧi����ܼ�
	int search, low = 0, high = max - 1, middle;	//�ŧi����ܼ�
	int number[max] = { 57, 19, 33, 92, 6 };	//�ŧi��ư}�C
	cout << "�Ƨǫe�G";	//��ܱƧǫe����
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	cout << "\n�п�J�n�j�M�ƭȡG"; cin >> search;	//��J�j�M��
	for (i = 0; i < max - 1; i++)	//�Ƨǰj��
		for (j = i; j < max; j++)
			if (number[i] > number[j])
			{
				buffer = number[i];
				number[i] = number[j];
				number[j] = buffer;
			}
	cout << "\n�Ƨǫ�G";	//��ܱƧǫᤧ��
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	do				//�j�M�j��
	{
		if ((low + high) % 2 > 0.5)	//�p��j�M��m
			middle = (low + high) / 2 + 1;
		else
			middle = (low + high) / 2;

		if (search < number[middle])	//�p��j�M�W��
			high = middle - 1;
		else if (search > number[middle])	//�p��j�M�U��
			low = middle + 1;
		else if (search == number[middle])	//���۲żƭ�
			break;
	} while (low <= high);
	if (low > high)	//��ܷj�M���G
		cout << "\n�䤣��ƭȡG" << search << endl;
	else
		cout << "\n���ƭȡG" << search << endl;
	return 0;
}

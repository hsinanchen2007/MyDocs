//d:\Ex07\Ex0706.cpp
//�u�ʷj�M
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	bool flag = false;
	int i, search;
	int number[12] = {37, 5, 84, 92, 10, 49, 56, 81, 63, 21, 75, 52};

	cout << "��ܸ�ơG";
	for (i = 0; i < 12; i++)
		cout << number[i] << ' ';
	cout << "\n��J��ơG";
	cin >> search;
	for (i = 0; i < 12; i++)
	{
		if (number[i] == search)
			flag = 1;
	}
	if (flag)
		cout << "����ơG" << search << endl;
	else
		cout << "�䤣���ơG" << search << endl;
	system("PAUSE");
	return 0;
}

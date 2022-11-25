//d:\Ex07\Ex0706.cpp
//線性搜尋
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	bool flag = false;
	int i, search;
	int number[12] = {37, 5, 84, 92, 10, 49, 56, 81, 63, 21, 75, 52};

	cout << "顯示資料：";
	for (i = 0; i < 12; i++)
		cout << number[i] << ' ';
	cout << "\n輸入資料：";
	cin >> search;
	for (i = 0; i < 12; i++)
	{
		if (number[i] == search)
			flag = 1;
	}
	if (flag)
		cout << "找到資料：" << search << endl;
	else
		cout << "找不到資料：" << search << endl;
	system("PAUSE");
	return 0;
}

//d:\Ex08\Ex0801.cpp
// 找尋輸入值中的最大值
#include <iostream>
using namespace std;

int findMax(int []);
int len;

int main(int argc, char** argv) {
	int counti = 0;
	int number[100];
	do {
		cout << "第 " << counti << " 筆資料" << "，輸入 0 則結束：";
		cin >> number[counti];
	} while(number[counti++] != 0);
	len = counti-1;

	cout << "\n最大值：" << findMax(number) << endl;
	system("PAUSE");
	return 0;
}

int findMax(int array[])
{
	int max = 0;
	for (int i = 0; i<len; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

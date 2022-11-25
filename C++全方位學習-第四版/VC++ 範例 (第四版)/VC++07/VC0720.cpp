//檔案名稱：d:\VC++07\VC0720\VC0720.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const int max = 5;	//宣告整常數符號
	int i, j, buffer;	//宣告整數變數
	int number[max] = { 57, 19, 33, 92, 6 };	//宣告一維陣列
	cout << "排序前：";	//顯示排序前資料
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	for (i = 0; i < max - 1; i++)	//排序外迴圈
		for (j = i; j < max; j++)	//排序內迴圈
			if (number[i] > number[j])	//若須要則對調
			{
				buffer = number[i];
				number[i] = number[j];
				number[j] = buffer;
			}
	cout << "\n排序後：";	//顯示排序後資料
	for (i = 0; i < max; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

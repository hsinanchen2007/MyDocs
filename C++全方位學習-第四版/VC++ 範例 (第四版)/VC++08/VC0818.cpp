//檔案名稱：d:\VC++08\VC0818\VC0818.cpp
#include <iostream>
using namespace std;

int *maximum(int *);	//宣告函數原型

int main(int argc, char** argv)
{
	int number[5] = { 57, 19, 33, 92, 6 };	//宣告一維陣列
	cout << "資料列：";
	for (int i = 0; i <= 4; i++)	//輸出陣列資料迴圈
		cout << *(number + i) << ' ';
	cout << "\n最大值：" << *maximum(number);	//取得maximum的指標
	cout << endl;
	return 0;
}

int *maximum(int *array)	//搜尋最大值函數
{
	static int value;	//宣告整數變數
	static int *max = &value;	//宣告並起始max指標
	*max = 0;	//起始*max內含值
	for (int i = 0; i <= 4; i++)	//找尋最大值迴圈
	{
		if (*max < *(array + i))	//若*max值<陣列元素值
			*max = *(array + i);
	}
	return max;	//傳回max指標
}

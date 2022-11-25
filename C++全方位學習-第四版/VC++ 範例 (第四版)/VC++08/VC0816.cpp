//檔案名稱：d:\VC++08\VC0816\VC0816.cpp
#include <iostream>
using namespace std;

void sortArray(const int *, int *);	//宣告函數原型

int main(int argc, char** argv)
{
	const int SIZE = 5;	//宣告整常數符號
	int number[SIZE] = { 57, 19, 33, 92, 6 };	//宣告一維陣列

	cout << "排序前：";	//顯示排序前資料
	for (int i = 0; i < SIZE; i++)
		cout << number[i] << '\0';

	sortArray(&SIZE, number);	//傳number指標給sortArray

	cout << "\n排序後：";	//顯示排序後資料
	for (int j = 0; j<SIZE; j++)
		cout << number[j] << '\0';
	cout << endl;
	return 0;
}

void sortArray(const int *MAX, int *array)	//選擇排序函數
{
	int minimum, mindex;	//宣告緩衝器變數
	for (int i = 0; i<*MAX - 1; i++)	//排序外迴圈
	{
		mindex = i;	//mindex=最小值索引
		minimum = *(array + i);	//minimum=最小值
		for (int j = i + 1; j<*MAX; j++)	//排序內迴圈
		{
			if (*(array + j) < minimum)	//若*(array+j)<最小值
			{
				minimum = *(array + j);	//minimum=新最小值
				mindex = j;	//mindex=新最小值索引
			}
		}
		*(array + mindex) = *(array + i);	//*(array+最小值索引)=較大值
		*(array + i) = minimum;	//*(array+i)=最小值
	}
}

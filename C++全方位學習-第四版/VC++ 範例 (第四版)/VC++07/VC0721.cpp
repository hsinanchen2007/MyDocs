//檔案名稱：d:\VC++07\VC0721\VC0721.cpp
#include <iostream>
using namespace std;

const int MAX = 5;	//MAX = 陣列最大範圍

int main(int argc, char** argv)
{
	int i, j, minimum, mindex;	//宣告整數變數
	int number[MAX] = { 57, 19, 33, 92, 6 };	//宣告一維陣列
	cout << "排序前：";	//顯示排序前資料
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	for (i = 0; i < MAX - 1; i++)	//排序外迴圈
	{
		mindex = i;	//mindex=最小值索引
		minimum = number[i];	//minimum=最小值
		for (j = i + 1; j < MAX; j++)	//排序內迴圈
		{
			if (number[j] < minimum)	//若number[j]<最小值
			{
				minimum = number[j];	//minimum=新最小值
				mindex = j;	//mindex=新最小值索引
			}
		}
		number[mindex] = number[i];	//number[最小值索引]=較大值
		number[i] = minimum;	//number[i]=最小值
	}
	cout << "\n排序後：";	//顯示排序後資料
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

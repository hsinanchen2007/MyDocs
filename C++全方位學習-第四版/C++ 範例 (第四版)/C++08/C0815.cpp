//檔案名稱：d:\C++08\C0815.cpp
#include <iostream>
using namespace std;

void sortArray(int []);	//宣告函數原型

int main(int argc, char** argv)
{
	int i;	//宣告整數變數
	int number[5] = {57, 19, 33, 92, 6};	//宣告一維陣列
	cout << "排序前：";	//顯示排序前資料
	for (i=0; i<5; i++)
		cout << number[i] << '\0';
	sortArray(number);	//傳number給sortArray
	cout << "\n排序後：";	//顯示排序後資料
	for (i=0; i<5; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

void sortArray(int array[])	//氣泡排序函數
{
	int buffer;	//宣告緩衝器變數
	for (int i=0; i<4; i++)	//排序外迴圈
		for (int j=i; j<5; j++)	//排序內迴圈
			if (array[i] > array[j])	//若須要則對調
			{
				buffer = array[i];
				array[i] = array[j];
				array[j] = buffer;
			}
}

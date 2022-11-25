//檔案名稱：d:\VC++07\VC0715\VC0715.cpp
#include <iostream>
using namespace std;

void showArray(int, int, int);	//宣告函數原型

int main(int argc, char** argv)
{
	int source[3] = { 5, 9, 3 };	//宣告並起始source陣列
	int target[3];	//宣告target陣列
	cout << "複製前\n";
	for (int i = 0; i <= 2; i++)	//輸出陣列迴圈
		showArray(i, source[i], target[i]);	//呼叫showArray函數

	for (int j = 0; j <= 2; j++)	//複製迴圈
	{
		target[j] = source[j];	//複製source到target
	}
	cout << "\n複製後\n";
	for (int k = 0; k <= 2; k++)	//輸出陣列迴圈
		showArray(k, source[k], target[k]);	//呼叫showArray函數

	for (int l = 0; l <= 2; l++)	//清除迴圈
	{
		target[l] = 0;	//清除target
	}
	cout << "\n清除target後\n";
	for (int m = 0; m <= 2; m++)	//輸出陣列迴圈
		showArray(m, source[m], target[m]);	//呼叫showArray函數
	return 0;
}

void showArray(int index, int s, int t)	//輸出資料函數
{
	cout << "source[" << index << "] = " << s << '\t';	//輸出參數s值
	cout << "target[" << index << "] = " << t << endl;	//輸出參數t值
}

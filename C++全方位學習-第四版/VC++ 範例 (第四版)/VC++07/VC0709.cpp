//檔案名稱：d:\VC++07\VC0709\VC0709.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int source[3] = { 5, 9, 3 };	//宣告一維陣列變數
	int target[3] = { 0 };	//起始target元素為0
	cout << "複製前\n";
	for (int i = 0; i <= 2; i++)	//輸出來源迴圈
	{
		cout << "source[" << i << "] = " << source[i] << '\t';
		cout << "target[" << i << "] = " << target[i] << endl;
	}
	for (int j = 0; j <= 2; j++)	//複製迴圈
	{
		target[j] = source[j];	//複製source到target
	}
	cout << "\n複製後\n";
	for (int k = 0; k <= 2; k++)	//輸出目的迴圈
	{
		cout << "source[" << k << "] = " << source[k] << '\t';
		cout << "target[" << k << "] = " << target[k] << endl;
	}
	return 0;
}

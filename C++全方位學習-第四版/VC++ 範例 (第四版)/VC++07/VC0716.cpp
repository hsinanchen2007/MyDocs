//檔案名稱：d:\VC++07\VC0716\VC0716.cpp
#include <iostream>
using namespace std;

void showArray(int[], int[]);	//宣告函數原型

int main(int argc, char** argv)
{
	int source[3] = { 5, 9, 3 };	//宣告並起始source陣列
	int target[3];	//宣告target陣列
	cout << "複製前\n";
	showArray(source, target);	//呼叫showArray函數
	for (int j = 0; j <= 2; j++)	//複製迴圈
	{
		target[j] = source[j];	//複製source到target
	}
	cout << "\n複製後\n";
	showArray(source, target);	//呼叫showArray函數
	for (int k = 0; k <= 2; k++)	//清除迴圈
	{
		target[k] = 0;	//清除target
	}
	cout << "\n清除target後\n";
	showArray(source, target);	//呼叫showArray函數
	return 0;
}

void showArray(int s[], int t[])
{
	for (int i = 0; i <= 2; i++)	//輸出迴圈
	{
		cout << "source[" << i << "] = " << s[i] << '\t';	//輸出s[i]值
		cout << "target[" << i << "] = " << t[i] << endl;	//輸出t[i]值
	}
}

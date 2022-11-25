//儲存檔名：d:\C++06\C0611.cpp
#include <iostream>
using namespace std;

int total(int);	//宣告函數原型

int main(int argc, char** argv)
{
	cout << "1+2+3+...+10=" << total(10);	//顯示函數傳回值
	cout << "\n1+2+3+...+100=" << total(100);	//顯示函數傳回值
	cout << "\n1+2+3+...+1000=" << total(1000);	//顯示函數傳回值
	cout << endl;
	return 0;
}

int total(int n)	//計算1+2+…+n函數
{
	int sum = 0;	//宣告區域變數
	for (int i = 1; i <= n; i++)	//計算總和迴圈
		sum += i;
	return sum;	//傳回sum給呼叫敘述
}

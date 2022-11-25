// 儲存檔名：d:\VC++06\VC0606\VC0606.cpp
#include <iostream>
using namespace std;

void sum(int, int, int);	//宣告函數原型

int main(int argc, char** argv)
{
	sum(95, 24, 657);	//傳遞3個參數給sum函數
	sum(562, 194, 817);	//傳遞3個參數給sum函數
	sum(16, 256, 1024);	//傳遞3個參數給sum函數
	return 0;
}

void sum(int a, int b, int c)	//計算總和函數
{
	cout << a << " + " << b << " + " << c;
	cout << " = " << a + b + c << endl;	//計算並輸出總和
}

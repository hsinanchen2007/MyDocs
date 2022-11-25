//檔案名稱：d:\C++08\C0801.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int intVar1 = 12345;	//宣告與起始布林值變數
	int intVar2 = 2147483647;	//宣告與起始整數變數
	float floatVar = 123.45e+12f;	//宣告與起始單精度變數
	double doubleVar = 98765.43e-308;	//宣告與起始倍精度變數
	
	cout << "  變數   \t  位址\n";	//輸出表頭
	cout << "---------\t--------\n";	//輸出分隔線
	cout << "intVar1  \t" << &intVar1 << endl;	//輸出intVar1位址
	cout << "intVar2  \t" << &intVar2 << endl;	//輸出intVar2位址
	cout << "floatVar \t" << &floatVar << endl;	//輸出floatVar位址
	cout << "doubleVar\t" << &doubleVar << endl;	//輸出doubleVar位址
	return 0;
}

// 儲存檔名：d:\VC++06\VC0609\VC0609.cpp
#include <iostream>
using namespace std;

void swap(int &, int &);	//宣告函數原型

int main(int argc, char** argv)
{
	int var1 = 53, var2 = 75;	//宣告整數變數

	cout << "對調前： ";
	cout << "A = " << var1 << '\t';	//顯示對調前的數值A
	cout << "B = " << var2 << endl;	//顯示對調前的數值B
	swap(var1, var2);	//傳遞var1與var2的位址
	cout << "對調後： ";
	cout << "A = " << var1 << '\t';	//顯示對調後的數值A
	cout << "B = " << var2 << endl;	//顯示對調後的數值B
	return 0;
}

void swap(int &num1, int &num2)	//資料對調函數
{
	int buffer;
	buffer = num1;
	num1 = num2;
	num2 = buffer;
}

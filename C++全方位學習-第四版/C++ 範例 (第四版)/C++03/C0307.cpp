//儲存檔名：d:\C++03\C0307.cpp
#include <iostream>
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	cout.precision(2); 	//設定2位有效位數
	cout.setf(ios::fixed);	//改為2位小數有效數字
	cout.width(10);	//設定輸出空間為10個
	cout << PI * -1 << endl;	//輸出PI*-1
	cout.width(10);	//設定輸出空間為10個
	cout << PI * 100 << endl;	//輸出PI*100
	cout.width(10);	//設定輸出空間為10個
	cout << PI * 10000 << endl; 	//輸出PI*10000
	return 0;
}

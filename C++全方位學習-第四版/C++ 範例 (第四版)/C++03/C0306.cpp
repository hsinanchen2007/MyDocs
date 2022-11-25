//儲存檔名：d:\C++03\C0306.cpp
#include <iostream>
#include <iomanip>	//包含setprecision()
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	cout << setprecision(2) << setiosflags(ios::fixed);	//設定2位小數有效數
	cout << setw(10) << PI * -1 << endl; 	//設定10空間輸出PI*-1
	cout << setw(10) << PI * 100 << endl; 	//設定10空間輸出PI*100
	cout << setw(10) << PI * 10000 << endl; 	//設定10空間輸出PI*10000
	return 0;
}

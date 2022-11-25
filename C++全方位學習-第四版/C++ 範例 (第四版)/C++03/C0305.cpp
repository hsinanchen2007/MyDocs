//儲存檔名：d:\C++03\C0305.cpp
#include <iostream>
#include <iomanip>	//包含setprecision()
using namespace std;
const double PI = 3.141592653;

int main(int argc, char** argv)
{
	cout << setprecision(10);	//設定10位有效數字
	cout << setw(12) << PI * -1 << endl; 	//設定12空間輸出PI*-1
	cout << setw(12) << PI * 100 << endl; 	//設定12空間輸出PI*100
	cout << setw(12) << PI * 10000 << endl; 	//設定12空間輸出PI*10000
	return 0;
}

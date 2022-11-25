//檔案名稱：d:\VC++09\VC0907\VC0907.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>	//轉換數值標題檔
using namespace std;

int main(int argc, char** argv)
{
	char intArray[10];

	_itoa_s(1234, intArray, 8);	//1234轉成字串"2322"
	cout << "1234轉成八進位型態字串：\"" << intArray << "\"\n";

	_itoa_s(1234, intArray, 10);	//1234轉成字串"1234"
	cout << "1234轉成十進位型態字串：\"" << intArray << "\"\n";

	_itoa_s(1234, intArray, 16);	//1234轉成字串"4d2"
	cout << "1234轉成十六進位型態字串：\"" << intArray << "\"\n";
	return 0;
}

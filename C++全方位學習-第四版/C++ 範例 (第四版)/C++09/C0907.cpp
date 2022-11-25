//檔案名稱：d:\C++09\C0907.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>	//轉換數值標題檔
using namespace std;

int main(int argc, char** argv)
{
	char intArray[10];

	itoa(1234, intArray, 8);	//1234轉成字串"2322"
	cout << "1234轉成八進位型態字串：\"" << intArray << "\"\n";

	itoa(1234, intArray, 10);	//1234轉成字串"1234"
	cout << "1234轉成十進位型態字串：\"" << intArray << "\"\n";

	itoa(1234, intArray, 16);	//1234轉成字串"4d2"
	cout << "1234轉成十六進位型態字串：\"" << intArray << "\"\n";
	return 0;
}

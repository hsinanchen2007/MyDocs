// 儲存檔名：d:\VC++06\VC0607\VC0607.cpp
#include <iostream>
#include <iomanip>
using namespace std;

void area(float, float);	//宣告函數原型

int main(int argc, char** argv)
{
	const float PI = 3.1415926f;	//宣告常數符號
	cout << "圓半徑\t  圓面積\n";	//輸出表頭字串
	area(PI, 5.0);	//傳遞2個參數給area函數
	area(PI, 15.0);	//傳遞2個參數給area函數
	area(PI, 25.0);	//傳遞2個參數給area函數
	return 0;
}

void area(float pi, float r)	//計算圓面積函數
{
	cout.precision(2);	//設定輸出格式
	cout.setf(ios::fixed | ios::right);	//設定輸出有效位數
	cout << setw(6) << r << '\t';	//輸出圓半徑值
	cout << setw(8) << pi * r * r << endl;	//計算並輸出圓面積
}

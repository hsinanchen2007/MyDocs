//儲存檔名：d:\C++03\C0325.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//數值函數標題檔

using namespace std;

int main(int argc, char** argv)
{
	float x;	//宣告浮點數變數

	cout << "請輸入浮點數：";
	cin >> x;	//取得鍵盤輸入
	cout << "x = " << x;	//輸出數值
	cout << "\nceil("<< x << ") = " << ceil(x);	//輸出大於x的整數
	cout << "\nfloor("<< x << ") = " << floor(x);	//輸出小於x的整數
	cout << endl;           //輸出跳行 
	return 0;
}

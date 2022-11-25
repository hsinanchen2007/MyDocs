//儲存檔名：d:\C++03\C0324.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//數值函數標題檔
using namespace std;

int main(int argc, char** argv)
{
	float x;	//宣告浮點數變數

	cout << "請輸入浮點數：";
	cin >> x;	//取得鍵盤輸入
	cout << setprecision(2) << setiosflags(ios::fixed);	//設定有效位數
	cout << "x = " << x;	//輸出數值
	cout << "\npow(" << x << ") = " << pow(x, 2);	//輸出x的平方值
	cout << "\nsqrt(" << x << ") = " << sqrt(x);	//輸出x的開方值
	cout << endl;     //輸出跳行 
	return 0;
}

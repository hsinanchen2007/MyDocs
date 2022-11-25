//儲存檔名：d:\VC++03\VC0323\VC0323.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//數值函數標題檔
using namespace std;

int main(int argc, char** argv)
{
	int x;		//宣告整數變數

	cout << "請輸入整數：";
	cin >> x;	//取得鍵盤輸入
	cout << setprecision(3) << setiosflags(ios::fixed);	//設定有效位數
	cout << "x = " << x;	//輸出數值
	cout << "\nlog(" << x << ") = " << log(x);	//輸出自然對數值
	cout << "\nlog10(" << x << ") = " << log10(x);	//輸出基底10對數值
	cout << "\nexp(" << x << ") = " << exp(x);	//輸出 e 的x次方值
	cout << endl;
	return 0;
}

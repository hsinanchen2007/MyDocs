//儲存檔名：d:\C++03\C0322.cpp
#include <iostream>
#include <iomanip>
#include <cmath>	//數值函數標題檔
using namespace std;

int main(int argc, char** argv)
{
	float degree = (3.1415926f) / 180;	//degree=徑/度
	int d;		//宣告整數變數

	cout << "請輸入整數：";
	cin >> d;	//取得鍵盤輸入
	cout << setprecision(3) << setiosflags(ios::fixed);	//設定有效位數
	cout << "d = " << d << endl;	//輸出角度
	cout << "sin("<< d << ") = " << sin(degree*d) << endl;	//輸出正弦函數值
	cout << "cos("<< d << ") = " << cos(degree*d) << endl;	//輸出餘弦函數值
	cout << "tan("<< d << ") = " << tan(degree*d) << endl;	//輸出正切函數值
	return 0;
}

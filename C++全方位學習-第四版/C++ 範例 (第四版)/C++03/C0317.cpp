//儲存檔名：d:\C++03\C0317.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	float a, b, c, d, x = 6;	// 宣告變數a,b,c,d,x
	int f = 20;	// 宣告變數 f = 20
	a = b = c = d  = float(f);	// 令 a=b=c=d= 20
	cout << "a = b = c = d = f = 20, x = 6"	// 輸出字串
		<< "\na += x => a = " << (a += x)	// 輸出跳行、字串、a 值
		<< "\nb -= x => b = " << (b -= x)	// 輸出跳行、字串、b 值
		<< "\nc *= x => c = " << (c *= x)	// 輸出跳行、字串、c 值
		<< "\nd /= x => d = " << (d /= x)	// 輸出跳行、字串、d 值
		<< "\nf %= x => f = " << (f %= x)	// 輸出跳行、字串、f 值
		<< endl;	// 輸出跳行
	return 0;
}

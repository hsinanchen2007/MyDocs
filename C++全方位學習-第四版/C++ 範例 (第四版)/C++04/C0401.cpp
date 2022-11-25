//儲存檔名：d:\C++04\C0401.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a = 1, b = 4, c = 4;	//宣告並啟始 a, b, c 值
	cout << "a=" << a << endl;	//輸出字串、a 值、跳行
	cout << "b=" << b << endl;	//輸出字串、b 值、跳行
	cout << "c=" << c << endl;	//輸出字串、c 值、跳行
	bool x = a<b, y = c>=a;
	cout << "a<b 為 " << x << endl;	//輸出字串、a<b 值
	cout << "c>=a 為 " << y << endl;	//輸出字串、c>=a 值
	cout << "a!=b 為 " << (a!=b) << endl;	//輸出字串、a!=b 值
	cout << "a==c 為 " << (a==c) << endl;	//輸出字串、a==c 值
	return 0;
}

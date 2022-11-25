//儲存檔名：d:\C++04\C0402.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a = 1, b = 4, c = 4;	//宣告並啟始 a, b, c 值
	bool x = !(a < b && b == c || c <=a);	//宣告並指定 x 值
	cout << "a=" << a << endl;	//輸出字串、a 值、跳行
	cout << "b=" << b << endl;	//輸出字串、b 值、跳行
	cout << "c=" << c << endl;	//輸出字串、c 值、跳行
	cout << "!(a<b && b==c || c<=a) = " << x << endl;	//輸出字串、x 值
	return 0;
}

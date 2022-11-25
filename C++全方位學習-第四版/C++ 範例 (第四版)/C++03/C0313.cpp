//儲存檔名：d:\C++03\C0313.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a = 1, b = 4, c = 4;	//宣告並啟始 a, b, c 值
	int x = b * b - 4 * a * c;	//宣告並指定 x 值
	cout << "a=" << a << endl	//輸出字串、a 值、跳行
		   << "b=" << b << endl	//輸出字串、b 值、跳行
		   << "c=" << c << endl	//輸出字串、c 值、跳行
		   << "b*b-4*a*c=" << x << endl;	//輸出字串、x 值、跳行
	return 0;
}

// 自动存储期和静态存储期

#include <iostream>

using namespace std;

int fx = 0;				// 静态存储期+文件作用域

void func()
{
	static int sx = 0;	// 静态存储期+块作用域
	int 	   ax = 0;	// 自动存储期+块作用域

	fx++; sx++; ax++; 
	cout << fx << "  " << sx << "  " << ax << '\n';
}

int main()
{
	cout << "fx sx ax\n";
	cout << "--------\n";
	for (int i = 0; i < 8; i++)
		func();
}

// 生成随机数（每次运行时生成相同的随机数）

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int x = rand();			// 生成大于等于0且小于等于RAND_MAX的随机数
	int y = rand();			// 生成大于等于0且小于等于RAND_MAX的随机数

	cout << "x的值是" << x << "，y的值是" << y << "。\n";
}

// 生成随机数（每次运行时生成不同的随机数）

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));		// 由当前时刻确定种子

	int x = rand();			// 生成大于等于0且小于等于RAND_MAX的随机数
	int y = rand();			// 生成大于等于0且小于等于RAND_MAX的随机数

	cout << "x的值是" << x << "，y的值是" << y << "。\n";
}

// 显示bool型的值

#include <iostream>

using namespace std;

int main()
{
	cout << true << ' ' << false << '\n';

	cout << boolalpha;				// 以字母形式输出布尔值
	cout << true << ' ' << false << '\n';

	cout << noboolalpha;			// 以数值形式输出布尔值
	cout << true << ' ' << false << '\n';
}

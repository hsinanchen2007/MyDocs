// 发出警报的函数（默认实参）

#include <iostream>

using namespace std;

//--- 发出n次警报 ---//
void alerts(int n = 3)
{
	while (n-- > 0)
		cout << '\a';
}

int main()
{
	alerts();
	cout << "警报！\n";

	alerts(5);
	cout << "再次警报！\n";
}

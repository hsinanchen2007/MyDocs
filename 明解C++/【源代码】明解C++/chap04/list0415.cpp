// 从0.0按增量0.001递增至1.0，并显示它们的和（用float控制循环）

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	float sum = 0.0F;
	cout << fixed << setprecision(6);
	for (float x = 0.0F; x <= 1.0F; x += 0.001F) {
		cout << "x = " << x << '\n';
		sum += x;
	}
	cout << "sum = " << sum << '\n';
}

// 从0.0按增量0.001递增至1.0，并显示它们的和（用int控制循环）

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	float sum = 0.0F;
	cout << fixed << setprecision(6);
	for (int i = 0; i <= 1000; i++) {
		float x = static_cast<float>(i) / 1000;
		cout << "x = " << x << '\n';
		sum += x;
	}
	cout << "sum = " << sum << '\n';
}

// 显示double型的特性

#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << "最小值：" << numeric_limits<double>::min() << '\n';
	cout << "最大值：" << numeric_limits<double>::max() << '\n';
	cout << "尾数部分：" << numeric_limits<double>::radix  << "进制"
					   << numeric_limits<double>::digits << "位\n";
	cout << "位数：" << numeric_limits<double>::digits10 << '\n';
	cout << "机械极小值：" << numeric_limits<double>::epsilon()<< '\n';
	cout << "最大的舍入误差：" << numeric_limits<double>::round_error() << '\n';
	cout << "舍入方式：";

	switch (numeric_limits<double>::round_style) {
	 case round_indeterminate:
						cout << "无法确定。\n"; break;
	 case round_toward_zero:
						cout << "向0舍入。\n"; break;
	 case round_to_nearest:
						cout << "舍入为可以表示的最邻近的值。\n"; break;
	 case round_toward_infinity:
						cout << "向无限大舍入。\n"; break;
	 case round_toward_neg_infinity:
						cout << "向负无限大舍入。\n"; break;
	}
}

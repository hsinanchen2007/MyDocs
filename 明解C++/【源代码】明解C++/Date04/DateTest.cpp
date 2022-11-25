// 日期类Date（第4版）的使用例程

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date today;		// 今天

	cout << "今天的日期：" << today << '\n';

	cout << "昨天的日期：" << today.preceding_day() << '\n';
	cout << "前天的日期：" << today.preceding_day().preceding_day() << '\n';

	cout << "明天的日期：" << today.following_day() << '\n';
	cout << "后天的日期：" << today.following_day().following_day() << '\n';

	cout << "从元旦开始经过了" << today.day_of_year() << "天。\n";

	cout << "今年"
		 << (today.is_leap() ? "是闰年。" : "不是闰年。") << '\n';

	int y, m, d;

	cout << "公历年：";
	cin >> y;

	cout << "该年"
		 << (Date::is_leap(y) ? "是闰年。" : "不是闰年。") << '\n';
}

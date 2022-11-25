// 显示当前的日期和时间

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	time_t current = time(NULL);				// 当前日历时间
	struct tm* timer = localtime(&current);		// 分解时间（当地时间）
	char* wday_name[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

	cout << "当前日期和时间是"
		 << timer->tm_year + 1900     << "年"
		 << timer->tm_mon + 1         << "月"
		 << timer->tm_mday            << "日（"
		 << wday_name[timer->tm_wday] << "）"
		 << timer->tm_hour            << "时"
		 << timer->tm_min             << "分"
		 << timer->tm_sec             << "秒。\n";
}

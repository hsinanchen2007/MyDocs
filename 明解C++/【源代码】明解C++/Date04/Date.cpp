// 日期类Date（第4版：源文件）

#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

// 平年的各月的天数
int Date::dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//--- 计算y年m月的天数 ---//
int Date::days_of_month(int y, int m)
{
	return dmax[m - 1] + (is_leap(y) && m == 2);
}

//--- Date的默认构造函数（设置为当前日期）---//
Date::Date()
{
	time_t current = time(NULL);				// 获取当前日历时间
	struct tm* local = localtime(&current);		// 转换为分解时间

	y = local->tm_year + 1900;		// 年：tm_year为公历年-1900
	m = local->tm_mon + 1;			// 月：tm_mon为0~11
	d = local->tm_mday;
}

//--- Date的构造函数（设置为指定的年、月、日）---//
Date::Date(int yy, int mm, int dd)
{
	y = yy;
	m = mm;
	d = dd;
}

//--- 返回某年内的经过天数 ---//
int Date::day_of_year() const
{
	int days = d;	// 某年内的经过天数

	for (int i = 1; i < m; i++)			// 累加1月~(m-1)月的天数
		days += days_of_month(y, i);
	return days;
}

//--- 返回前一天的日期 ---//
Date Date::preceding_day() const
{
	Date temp = *this;		// 同一日期

	if (temp.d > 1)
		temp.d--;
	else {
		if (--temp.m < 1) {
			temp.y--;
			temp.m = 12;
		}
		temp.d = days_of_month(temp.y, temp.m);
	}
	return temp;
}

//--- 返回后一天的日期 ---//
Date Date::following_day() const
{
	Date temp = *this;		// 同一日期

	if (temp.d < days_of_month(temp.y, temp.m))
		temp.d++;
	else {
		if (++temp.m > 12) {
			temp.y++;
			temp.m = 1;
		}
		temp.d = 1;
	}
	return temp;
}

//--- 返回字符串表示 ---//
string Date::to_string() const
{
	ostringstream s;
	s << y << "年" << m << "月" << d << "日";
	return s.str();
}

//--- 返回星期（星期日~星期六对应0~6）---//
int Date::day_of_week() const
{
	int yy = y;
	int mm = m;
	if (mm == 1 || mm == 2) {
		yy--;
		mm += 12;
	}
	return (yy + yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

//--- 向输出流s插入x ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return s << x.to_string();
}

//--- 从输入流s提取日期并存入x ---//
istream& operator>>(istream& s, Date& x)
{
	int yy, mm, dd;
	char ch;

	s >> yy >> ch >> mm >> ch >> dd;
	x = Date(yy, mm, dd);
	return s;
}

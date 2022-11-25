// 日期类Date（第2版：源文件）

#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

//--- Date的默认构造函数（设置为当前日期）---//
Date::Date()
{
	time_t current = time(NULL);				// 获取当前的日历时间
	struct tm* local = localtime(&current);		// 转换为分解时间

	y = local->tm_year + 1900;		// 年：tm_year为公元年-1900
	m = local->tm_mon + 1;			// 月：tm_mon为0 ~ 11
	d = local->tm_mday;				// 日
}

//--- Date的构造函数（设置为指定年月日）---//
Date::Date(int yy, int mm, int dd)
{
	y = yy;
	m = mm;
	d = dd;
}

//--- 返回前一天的日期（不支持闰年的处理） ---//
Date Date::preceding_day() const
{
	int dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Date temp = *this;		// 同一日期

	if (temp.d > 1)
		temp.d--;
	else {
		if (--temp.m < 1) {
			temp.y--;
			temp.m = 12;
		}
		temp.d = dmax[temp.m - 1];
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

//--- 向输出流s插入x ---//
ostream& operator<<(ostream& s, const Date& x)
{
	return s << x.to_string();
}

//--- 从输入流s提取日期存入x ---//
istream& operator>>(istream& s, Date& x)
{
	int yy, mm, dd;
	char ch;

	s >> yy >> ch >> mm >> ch >> dd;
	x = Date(yy, mm, dd);
	return s;
}


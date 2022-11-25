// 日期类Date（第5版：源文件）

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
	return dmax[m - 1] + (m == 2 && leap_year(y));
}

//--- year年的天数（平年...365/闰年...366）---//
int Date::days_of_year(int year)
{
	return 365 + leap_year(year);
}

//--- 被调整的月（调整1~12的范围之外的不正确的值）---//
int Date::adjusted_month(int m)
{
	return m < 1 ? 1 : m > 12 ? 12 : m;
}

//--- 被调整的y年m月的d日（调整1~28/29/30/31的范围之外的不正确的值）---//
int Date::adjusted_day(int y, int m, int d)
{
	if (d < 1)
		return 1;

	int max_day = days_of_month(y, m);		// y年m月的天数

	return d > max_day ? max_day : d;
}

//--- Date的默认构造函数（设置为当前日期）---//
Date::Date()
{
	time_t current = time(NULL);				// 获取当前日历时间
	struct tm* local = localtime(&current);		// 转换为分解时间

	y = local->tm_year + 1900;		// 年：tm_year为公历年-1900
	m = local->tm_mon + 1;			// 月：tm_mon为0~11
	d = local->tm_mday;				// 日
}

//--- Date的构造函数（设置为指定年月日）---//
Date::Date(int yy, int mm, int dd)
{
	set(yy, mm, dd);				// 设置日期为yy年mm月dd日
}

//--- 设置年为yy ---//
void Date::set_year(int yy)
{
	y = yy;							// 年
	d = adjusted_day(y, m, d);		// 日（调整不正确的值）
}

//--- 设置月为mm ---//
void Date::set_month(int mm)
{
	m = adjusted_month(mm);			// 月（调整不正确的值）
	d = adjusted_day(y, m, d);		// 日（调整不正确的值）
}

//--- 设置日为dd ---//
void Date::set_day(int dd)
{
	d = adjusted_day(y, m, dd);		// 日（调整不正确的值）
}

//--- 设置日期为yy年mm月dd日 ---//
void Date::set(int yy, int mm, int dd)
{
	y = yy;							// 年
	m = adjusted_month(mm);			// 月（调整不正确的值）
	d = adjusted_day(y, m, dd);		// 日（调整不正确的值）
}

//--- 返回前一天的日期 ---//
Date Date::preceding_day() const
{
	Date temp(*this);				// 创建*this的副本
	return --temp;					// 计算副本的前一天日期并返回
}

//--- 返回后一天的日期 ---//
Date Date::following_day() const
{
	Date temp(*this);				// 创建*this的副本
	return ++temp;					// 计算副本的后一天日期并返回
}

//--- 返回某年内的经过天数 ---//
int Date::day_of_year() const
{
	int days = d;	// 某年内的经过天数

	for (int i = 1; i < m; i++)			// 累加1月~(m-1)月的天数
		days += days_of_month(y, i);
	return days;
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

//--- 返回字符串表示 ---//
string Date::to_string() const
{
	ostringstream s;
	s << y << "年" << m << "月" << d << "日";
	return s.str();
}

//--- 向后一天（前置递增：++(*this)）---//
Date& Date::operator++()
{
	if (d < days_of_month(y, m))	// 如果比月末靠前
		d++;						// 只需递增日
	else {							// 到下一月
		if (++m > 12) {				// 如果超过12月
			y++;					// 到下一年的...
			m = 1;					// 1月
		}
		d = 1;						// 变为下一月的1日
	}
	return *this;
}

//--- 向后一天（后置递增：(*this)++）---//
Date Date::operator++(int)
{
	Date temp(*this);				// 复制递增前的值
	++(*this);						// 使用前置递增运算符++来递增
	return temp;					// 返回副本
}

//--- 向前一天（前置递减：--(*this)）---//
Date& Date::operator--()
{
	if (d > 1)						// 如果是月初
		d--;						// 只需递减日
	else {							// 到前一月
		if (--m <= 1) {				// 如果超过1月
			y--;					// 到前一年的
			m = 12;					// 12月
		}
		d = days_of_month(y, m);	// 变为前一月的月末
	}
	return *this;
}

//--- 向前一天（后置递减：(*this)--）---//
Date Date::operator--(int)
{
	Date temp(*this);				// 复制递减前的值
	--(*this);						// 使用前置递减运算符--来递减
	return temp;					// 返回副本
}

//--- 向后n天（复合赋值：*this += n）---//
Date& Date::operator+=(int n)
{
	if (n < 0)							// 如果n为负
		return *this -= -n;			// 委托运算符-=处理

	d += n;							// 日加n

	while (d > days_of_month(y, m)) {	// 调整年月使得日在月的天数范围内
		d -= days_of_month(y, m);
		if (++m > 12) {
			y++;
			m = 1;
		}
	}
	return *this;
}

//--- 向前n天（复合赋值：*this -= int）---//
Date& Date::operator-=(int n)
{
	if (n < 0)							// 如果n为负
		return *this += -n;			// 委托运算符+=处理

	d -= n;							// 日减n

	while (d < 1) {						// 调整年月使得日为正
		if (--m < 1) {
			y--;
			m = 12;
		}
		d += days_of_month(y, m);
	}
	return *this;
}

//--- 求n天后的日期（加法：*this + n）---//
Date Date::operator+(int n) const
{
	Date temp(*this);
	return temp += n;						// 使用运算符+=
}

//--- 求day的n天后的日期（加法：n + day）---//
Date operator+(int n, const Date& day)
{
	return day + n;						// 委托Date + int的运算符+处理
}

//--- 求date的n天前的日期（减法：*this - n）---//
Date Date::operator-(int n) const
{
	Date temp(*this);
	return temp -= n;						// 使用运算符-=
}

//--- 求日期的差（减法：*this - day）---//
long Date::operator-(const Date& day) const
{
	long count;
	long count1 = this->day_of_year();	// *this的年内经过天数
	long count2 = day.day_of_year();	// day  的年内经过天数

	if (y == day.y)										// *this和day为同一年
		count = count1 - count2;
	else if (y > day.y) {								// *this靠后
		count = days_of_year(day.y) - count2 + count1;
		for (int yy = day.y + 1; yy < y; yy++)
			count += days_of_year(yy);
	} else {											// *this靠前
		count = -(days_of_year(y) - count1 + count2);
		for (int yy = y + 1; yy < day.y; yy++)
			count -= days_of_year(yy);
	}

	return count;
}

//--- 与day相同吗？（相等：*this == day）---//
bool Date::operator==(const Date& day) const
{
	return y == day.y && m == day.m && d == day.d;
}

//--- 与day不同吗？（相等：*this != day）---//
bool Date::operator!=(const Date& day) const
{
	return !(*this == day);						// 使用运算符==
}

//--- 比day靠后的新日期吗？（关系：*this > day）---//
bool Date::operator>(const Date& day) const
{
	if (y > day.y) return true;		// 不同年（新）
	if (y < day.y) return false;	// 不同年（旧）

	if (m > day.m) return true;		// 相同年-不同月（新）
	if (m < day.m) return false;	// 相同年-不同月（旧）

	return d > day.d;				// 相同年-相同月（比较日）
}

//--- day之后的日期吗？（关系：*this >= day）---//
bool Date::operator>=(const Date& day) const
{
	return !(*this < day);						// 使用运算符<
}

//--- 比day靠前的旧日期吗？（关系：*this < day）---//
bool Date::operator<(const Date& day) const
{
	if (y < day.y) return true;		// 不同年（旧）
	if (y > day.y) return false;	// 不同年（新）

	if (m < day.m) return true;		// 相同年-不同月（旧）
	if (m > day.m) return false;	// 相同年-不同月（新）

	return d < day.d;				// 相同年-相同月（比较日）
}

//--- day之前的日期吗？（关系：*this <= day）---//
bool Date::operator<=(const Date& day) const
{
	return !(*this > day);						// 使用运算符>
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
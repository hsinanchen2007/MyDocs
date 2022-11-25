// 日期类Date（第4版：头文件）

#ifndef ___Class_Date
#define ___Class_Date

#include <string>
#include <iostream>

//===== 日期类 =====//
class Date {
	int y;	// 公历年
	int m;	// 月
	int d;	// 日
	static int dmax[];
	static int days_of_month(int y, int m);		// y年m月的天数

public:
	Date();										// 默认构造函数
	Date(int yy, int mm = 1, int dd = 1);		// 构造函数

	// year年是闰年吗？
	static bool is_leap(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	int year()  const { return y; }			// 返回年
	int month() const { return m; }			// 返回月
	int day()   const { return d; }			// 返回日
	bool is_leap() const { return is_leap(y); }		// 是闰年吗？
	Date preceding_day() const;				// 返回前一天的日期
	Date following_day() const;				// 返回后一天的日期

	int day_of_year() const;				// 返回某年内的经过天数

	int day_of_week() const;				// 返回星期

	std::string to_string() const;			// 返回字符串表示
};

std::ostream& operator<<(std::ostream& s, const Date& x);		// 插入符
std::istream& operator>>(std::istream& s, Date& x);				// 提取符

#endif

// 日期类Date（第5版：头文件）

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
	static int days_of_year(int y);				// y年的天数
	static int days_of_month(int y, int m);		// y年m月的天数

	// 被调整的月（调整1~12的范围之外的不正确的值）
	static int adjusted_month(int m);

	// 被调整的y年m月的d日（调整1~28/29/30/31的范围之外的不正确的值）
	static int adjusted_day(int y, int m, int d);

public:
	Date();										// 默认构造函数
	Date(int yy, int mm = 1, int dd = 1);		// 构造函数

	//--- year年是闰年吗？ ---//
	static bool leap_year(int year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}

	int year()  const { return y; }			// 返回年
	int month() const { return m; }			// 返回月
	int day()   const { return d; }			// 返回日

	void set_year( int yy);					// 设置年为yy
	void set_month(int mm);					// 设置月为mm
	void set_day(  int dd);					// 设置日为dd

	void set(int yy, int mm, int dd);		// 设置日期为yy年mm月dd日

	bool leap_year() const { return leap_year(y); }		// 是闰年吗？

	Date preceding_day() const;				// 返回前一天的日期
	Date following_day() const;				// 返回后一天的日期

	int day_of_year() const;				// 返回某年内的经过天数

	int day_of_week() const;				// 返回星期

	std::string to_string() const;			// 返回字符串表示

	Date& operator++();							// 向后一天（前置递增）
	Date  operator++(int);						// 向后一天（后置递增）

	Date& operator--();							// 向前一天（前置递减）
	Date  operator--(int);						// 向前一天（后置递减）

	Date& operator+=(int n);					// 向后n天（Date += int）
	Date& operator-=(int n);					// 向前n天（Date -= int）

	Date operator+(int n) const;					 // 求n天后的日期（Date + int）
	friend Date operator+(int n, const Date& date);  // 求n天后的日期（int + Date）

	Date operator-(int n) const;				// 求n天前的日期（Date - int）

	long operator-(const Date& day) const;		// 求日期的差（Date - Date）

	bool operator==(const Date& day) const;		// 与day相同吗？
	bool operator!=(const Date& day) const;		// 与day不同吗？

	bool operator> (const Date& day) const;		// 比day靠后吗？
	bool operator>=(const Date& day) const;		// 在day之后吗？
	bool operator< (const Date& day) const;		// 比day靠前吗？
	bool operator<=(const Date& day) const;		// 在da之前吗？
};

std::ostream& operator<<(std::ostream& s, const Date& x);	// 插入符
std::istream& operator>>(std::istream& s,       Date& x);	// 提取符

#endif

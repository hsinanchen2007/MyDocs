// 日期类Date（第2版：头文件）

#include <string>
#include <iostream>

class Date {
	int y;		// 公历年
	int m;		// 月
	int d;		// 日

public:
	Date();									// 默认构造函数
	Date(int yy, int mm = 1, int dd = 1);	// 构造函数

	int year()  const { return y; }		// 返回年
	int month() const { return m; }		// 返回月
	int day()   const { return d; }		// 返回日

	Date preceding_day() const;			// 返回前一天的日期（不支持闰年的处理）

	std::string to_string() const;		// 返回字符串表示
};

std::ostream& operator<<(std::ostream& s, const Date& x);	// 插入符
std::istream& operator>>(std::istream& s, Date& x);			// 提取符
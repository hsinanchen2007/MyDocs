// 日期类Date（添加成员函数调用次数）

#include <iostream>

using namespace std;

class Date {
	int y;		// 公历年
	int m;		// 月
	int d;		// 日
	mutable int counter;	// 成员函数的调用次数

public:
	Date(int yy, int mm, int dd) {					// 构造函数
		y = yy;  m = mm;  d = dd;  counter = 0;
	}
	int year()  const { counter++; return y; }		// 返回年
	int month() const { counter++; return m; }		// 返回月
	int day()   const { counter++; return d; }		// 返回日
	int count() const { return counter; }			// 返回次数
};

int main()
{
	const Date birthday(1963, 11, 18);		// 生日

	cout << "birthday = " << birthday.year()  << "年"
						  << birthday.month() << "月"
						  << birthday.day()	  << "日\n";
	cout << "birthday的成员函数被调用了" << birthday.count() << 
			"次。\n";
}

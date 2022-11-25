// 日期类Date（第5版）的使用例程

#include <iostream>
#include "Date.h"

using namespace std;

//--- 显示日期的相关信息 ---//
void display(const Date& day)
{
	string dw[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
	cout << "日期" << day << "的相关信息\n";
	cout << "  它是" << dw[day.day_of_week()] << "";
	cout << "  年内经过天数是" << day.day_of_year() << "天";
	cout << "  该年" << (day.leap_year() ? "是闰年" : "不是闰年。") << '\n';
}

//--- 修改日期 ---//
void change(Date& day)
{
	while (true) {
		cout << "[1]修改年 [2]修改月 [3]修改日 [4]修改年月日 "
			 << "[5]向后n天 [6]向前n天 [0]返回：";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		int y, m, d, n;
		if (selected == 1 || selected == 4) { cout << "年：";   cin >> y; }
		if (selected == 2 || selected == 4) { cout << "月：";   cin >> m; }
		if (selected == 3 || selected == 4) { cout << "日：";   cin >> d; }
		if (selected == 5 || selected == 6) { cout << "天数："; cin >> n; }

		switch (selected) {
		 case 1: day.set_year(y);	break;		// 设置为y年
		 case 2: day.set_month(m);	break;		// 设置为m月
		 case 3: day.set_day(d);	break;		// 设置为d日
		 case 4: day.set(y, m, d);	break;		// 设置为y年m月d日
		 case 5: day += n;			break;		// 向后n天
		 case 6: day -= n;			break;		// 向前n天
		}
		cout << "修改为" << day << "。\n";
	}
}

//--- 使用递增和递减运算符 ---//
void inc_dec(Date& day)
{
	while (true) {
		cout << "[1]++day  [2]day++  [3]--day  [4]day-- [0]栠傞丗";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		switch (selected) {
		 case 1: cout << "++day = " << ++day << '\n';  break;	// 前置递增
		 case 2: cout << "day++ = " << day++ << '\n';  break;	// 后置递增
		 case 3: cout << "--day = " << --day << '\n';  break;	// 前置递减
		 case 4: cout << "day-- = " << day-- << '\n';  break;	// 后置递减
		}
		cout << "day   = " << day << '\n';
	}
}

//--- 求之前和之后的日期 ---//
void before_after(Date& day)
{
	while (true) {
		cout << "[1]后一天 [2]前一天 [3]n天后(day+n) [4]n天后(n+day)"
			 << "[5]n天前 [0]返回：";
		int selected;
		cin >> selected;

		if (selected == 0) return;

		int n;
		if (selected >= 3 && selected <= 5) {
			cout << "天数：";  cin >> n;
		}

		cout << "它是";
		switch (selected) {
		 case 1: cout << day.following_day();	break;	// 后一天
		 case 2: cout << day.preceding_day();	break;	// 前一天
		 case 3: cout << day + n;				break;	// n天后（Date + int）
		 case 4: cout << n   + day;				break;	// n天后（int  + Date）
		 case 5: cout << day - n;				break;	// n天前（Date - int）
		}
		cout << "。\n";
	}
}

//--- 与其他日期比较 ---//
void compare(const Date& day)
{
	int y, m, d;
	cout << "请输入比较对象的日期day2。\n";
	cout << "年：";  cin >> y;
	cout << "月：";  cin >> m;
	cout << "日：";  cin >> d;

	Date day2(y, m, d);	// 比较对象的日期

	cout << boolalpha;
	cout << "day  = " << day  << '\n';
	cout << "day2 = " << day2 << '\n';
	cout << "day  -  day2  = " << (day  -  day2) << '\n';
	cout << "day2 -  day   = " << (day2 -  day ) << '\n';
	cout << "day  == day2  = " << (day  == day2) << '\n';
	cout << "day  != day2  = " << (day  != day2) << '\n';
	cout << "day  >  day2  = " << (day  >  day2) << '\n';
	cout << "day  >= day2  = " << (day  >= day2) << '\n';
	cout << "day  <  day2  = " << (day  <  day2) << '\n';
	cout << "day  <= day2  = " << (day  <= day2) << '\n';
}

int main()
{
	int y, m, d;
	cout << "请输入日期day。\n";
	cout << "年：";  cin >> y;
	cout << "月：";  cin >> m;
	cout << "日：";  cin >> d;

	Date day(y, m, d);	// 读入的日期

	while (true) {
		cout << "[1]显示信息 [2]修改日期 [3]递增和递减运算符 [4]之前和之后的日期 "
			 << "[5]比较 [0]结束：";

		int selected;
		cin >> selected;

		if (selected == 0) break;

		switch (selected) {
		 case 1: display(day);		break;	// 显示日期的相关信息
		 case 2: change(day);		break;	// 修改日期
		 case 3: inc_dec(day);		break;	// 递增运算符和递减运算符
		 case 4: before_after(day);	break;	// 求之前和之后的日期
		 case 5: compare(day);		break;	// 与其他日期比较
		}
	}
}

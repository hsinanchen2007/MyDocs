// 日期类Date（第1版：头文件）

class Date {
	int y;		// 公历年
	int m;		// 月
	int d;		// 日

public:
	Date(int yy, int mm, int dd);	// 构造函数
	int year()  { return y; }		// 返回年
	int month() { return m; }		// 返回月
	int day()   { return d; }		// 返回日
};

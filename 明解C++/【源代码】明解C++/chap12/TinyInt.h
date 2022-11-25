#ifndef ___TinyInt
#define ___TinyInt

#include <climits>
#include <iostream>

//--- 小整数类 ---//
class TinyInt {
	int v;			// 值

public:
	TinyInt(int value = 0) : v(value) { }		//--- 构造函数 ---//

	operator int() const { return v; }			//--- int的转换函数  ---//

	bool operator!() const { return v == 0; }	//--- 逻辑非运算符 ---//

	TinyInt& operator++() { 		//--- 前置递增运算符 ---//
		if (v < INT_MAX) v++;			// 值的上限为INT_MAX
		return *this;					// 返回自身的引用
	}

	TinyInt operator++(int) {		//--- 后置递增运算符 ---//
		TinyInt x = *this;				// 保存递增前的值
		++(*this);						// 使用前置递增运算符执行递增
		return x;						// 返回刚才保存的值
	}

	friend TinyInt operator+(const TinyInt& x, const TinyInt& y) {	// x + y
		return TinyInt(x.v + y.v);
	}

	//--- 复合赋值运算符 ---//
	TinyInt& operator+=(const TinyInt& x) { v += x.v; return *this; }

	friend bool operator==(const TinyInt& x, const TinyInt& y) { return x.v == y.v; }

	friend bool operator!=(const TinyInt& x, const TinyInt& y) { return x.v != y.v; }

	friend bool operator> (const TinyInt& x, const TinyInt& y) { return x.v >  y.v; }

	friend bool operator>=(const TinyInt& x, const TinyInt& y) { return x.v >= y.v; }

	friend bool operator< (const TinyInt& x, const TinyInt& y) { return x.v <  y.v; }

	friend bool operator<=(const TinyInt& x, const TinyInt& y) { return x.v <= y.v; }

	friend std::ostream& operator<<(std::ostream& s, const TinyInt& x) {
		return s << x.v;
	}
};

#endif

// 计数器类Counter（第2版）

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

//===== 计数器类 =====//
class Counter {
	unsigned cnt;		// 计数器

public:
	//--- 构造函数 ---//
	Counter() : cnt(0) { }

	//--- unsigned型的转换函数  ---//
	operator unsigned() const { return cnt; }

	//--- 逻辑非运算符 ---//
	bool operator!() const { return cnt == 0; }

	//--- 前置递增运算符 ---//
	Counter& operator++() {
		if (cnt < UINT_MAX) cnt++;	// 计数器的上限为UINT_MAX
		return *this;				// 返回自身的引用
	}

	//--- 后置递增运算符 ---//
	Counter operator++(int) {
		Counter x = *this;			// 保存递增前的值
		++(*this);					// 由前置递增运算符执行递增
		return x;					// 返回刚才保存的值
	}

	//--- 前置递减运算符 ---//
	Counter& operator--() {
		if (cnt > 0) cnt--;			// 计数器的下限为0
		return *this;				// 返回自身的引用
	}

	//--- 后置递减运算符 ---//
	Counter operator--(int) {
		Counter x = *this;			// 保存递减前的值
		--(*this);					// 由前置递减运算符执行递减
		return x;					// 返回刚才保存的值
	}
};

#endif

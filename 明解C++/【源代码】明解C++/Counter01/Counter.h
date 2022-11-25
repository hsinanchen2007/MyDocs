// 计数器类Counter（第1版）

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

//===== 计数器类 =====//
class Counter {
	unsigned cnt;		// 计数器

public:
	//--- 构造函数 ---//
	Counter() : cnt(0) { }

	//--- 向上计数 ---//
	void increment() {
		if (cnt < UINT_MAX) cnt++;		// 计数器的上限为UINT_MAX
	}

	//--- 向下计数 ---//
	void decrement() {
		if (cnt > 0) cnt--;				// 计数器的下限为0
	}

	//--- 返回计数器 ---//
	unsigned value() {					// cnt的获取器
		return cnt;
	}
};

#endif

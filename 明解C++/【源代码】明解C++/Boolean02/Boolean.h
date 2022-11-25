// 布尔值类Boolean（第2版：增加逻辑非运算符!）

#ifndef ___Class_Boolean
#define ___Class_Boolean

#include <iostream>

//===== 布尔值类 =====//
class Boolean {
public:
	enum boolean {False, True};			// False为假，True为真

private:
	boolean v;			// 布尔值

public:
	//--- 默认构造函数---//
	Boolean() : v(False) { }				// 初始化为假

	//--- 构造函数 ---//
	Boolean(int val) : v(val == 0 ? False : True) { }

	//--- int型的转换函数 ---//
	operator int() const { return v; }

	//--- const char*型的转换函数 ---//
	operator const char*() const { return v == False ? "False" : "True"; }

	//--- 逻辑非运算符! ---//
	bool operator!() const { return !v; }
};

//--- 向输出流s插入x ---//
inline std::ostream& operator<<(std::ostream& s, Boolean& x)
{
	return s << static_cast<const char*>(x);
}

#endif

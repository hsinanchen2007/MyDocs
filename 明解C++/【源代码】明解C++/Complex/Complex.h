// 复数类Complex

#ifndef ___Class_Complex
#define ___Class_Complex

#include <iostream>

//===== 复数类 =====//
class Complex {
	double re;		// 实部
	double im;		// 虚部

public:
	Complex(double r = 0, double i = 0) : re(r), im(i) { }	 // 构造函数

	double real() const { return re; }		// 返回实部
	double imag() const { return im; }		// 返回虚部

	Complex operator+() const { return *this; }				 // 一元+运算符
	Complex operator-() const { return Complex(-re, -im); }	 // 一元-运算符

	//--- 复合赋值运算符 ---//
	Complex& operator+=(const Complex& x) {
		re += x.re;
		im += x.im;
		return *this;
	}

	//--- 复合赋值运算符 ---//
	Complex& operator-=(const Complex& x) {
		re -= x.re;
		im -= x.im;
		return *this;
	}

	//--- 相等运算符 ---//
	friend bool operator==(const Complex& x, const Complex& y) {
		return x.re == y.re && x.im == y.im;
	}

	//--- 相等运算符 ---//
	friend bool operator!=(const Complex& x, const Complex& y) {
		return !(x == y);
	}

	//--- 二元+运算符（Complex + Complex）---//
	friend Complex operator+(const Complex& x, const Complex& y) {
		return Complex(x.re + y.re, x.im + y.im);
	}

	//--- 二元+运算符（double + Complex）---//
	friend Complex operator+(double x, const Complex& y) {
		return Complex(x + y.re, y.im);
	}

	//--- 二元+运算符（Complex + double）---//
	friend Complex operator+(const Complex& x, double y) {
		return Complex(x.re + y, x.im);
	}
};

//--- 向输出流s插入x ---//
inline std::ostream& operator<<(std::ostream& s, const Complex& x)
{
	return s << '(' << x.real() << ", " << x.imag() << ')';
}

#endif

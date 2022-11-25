// 初始化和赋值、值传递和引用传递的验证

#include <iostream>

using namespace std;

//===== 用于验证的类 =====//
class Test {
public:
	Test() {							// 默认构造函数
		 cout << "初始化：Test()\n";
	}

	Test(const Test& t) {				// 复制构造函数
		cout << "初始化：Test(const Test&)\n";
	}

	Test& operator=(const Test& t) {	// 赋值运算符
		cout << "赋值：Test = Test\n";  return *this;
	}
};

//--- 值传递 ---//
void value(Test a) { }

//--- 引用传递 ---//
void reference(Test& a)  { }

int main()
{
	Test x;		  // 默认构造函数
	Test y = x;	  // 复制构造函数
	Test z(x);	  // 复制构造函数
	y = x;		  // 赋值运算符
	value(x);	  // 函数调用（值传递）
	reference(x); // 函数调用（引用传递）
}

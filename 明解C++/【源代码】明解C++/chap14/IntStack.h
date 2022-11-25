#ifndef ___IntStack
#define ___IntStack

#include <iostream>

//--- 整数栈类 ---//
class IntStack {
	int nelem;		// 栈的容量（数组的元素个数）
	int* stk;		// 指向第一个元素的指针
	int ptr;		// 栈指针（当前积压的数据个数）

public:
	//--- 显式构造函数 ---//
	explicit IntStack(int sz) : nelem(sz), ptr(0) { stk = new int[nelem]; }

	IntStack(const IntStack& x) {			  //--- 复制构造函数 ---//
		nelem = x.nelem;						// 使容量与x相同
		ptr = x.ptr;							// 初始化栈指针
		stk = new int[nelem];					// 为数组主体分配空间
		for (int i = 0; i < nelem; i++)			// 复制所有元素
			stk[i] = x.stk[i];
	}

	~IntStack() { delete[] stk; }			  //--- 析构函数 ---//

	int size() const { return nelem; }		  //--- 返回容量 ---//

	bool empty() const { return ptr == 0; }	  //--- 栈为空？ ---//

	IntStack& operator=(const IntStack& x) {  //--- 赋值运算符= ---//
		if (&x != this) {						// 如果赋值源不是自己……
			if (nelem != x.nelem) {				// 如果赋值前后的元素个数不同……
				delete[] stk;					// 释放原本分配的空间
				nelem = x.nelem;				// 新的容量
				ptr = x.ptr;					// 新的栈指针
				stk = new int[nelem];			// 重新分配空间
			}
			for (int i = 0; i < ptr; i++)		// 复制积压的元素
				stk[i] = x.stk[i];
		}
		return *this;
	}

	//--- 压栈：向末尾压入数据 ---//
	void push(int x) { if (ptr < nelem) stk[ptr++] = x; }

	//--- 出栈：从末尾取出积压的数据 ---//
	int pop() { if (ptr > 0) return stk[--ptr]; else throw 1; }
};

#endif

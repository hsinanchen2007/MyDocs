// 整数数组类（第3版：源文件）

#include <cstddef>
#include "IntArray.h"

//--- 复制构造函数 ---//
IntArray::IntArray(const IntArray& x)
{
	if (&x == this) { 						// 如果初始值为自己……
		nelem = 0;
		vec = NULL;
	} else {
		nelem = x.nelem;					// 使元素个数与x相同
		vec = new int[nelem];				// 为数组主体分配空间
		for (int i = 0; i < nelem; i++)		// 复制所有元素
			vec[i] = x.vec[i];
	}
}

//--- 赋值运算符 ---//
IntArray& IntArray::operator=(const IntArray& x)
{
	if (&x != this) {						// 如果赋值源不是自己……
		if (nelem != x.nelem) {				// 如果赋值前后的元素个数不同……
			delete[] vec;					// 释放原本分配的空间
			nelem = x.nelem;				// 新的元素个数
			vec = new int[nelem];			// 重新分配空间
		}
		for (int i = 0; i < nelem; i++)		// 复制所有元素
			vec[i] = x.vec[i];
	}
	return *this;
}

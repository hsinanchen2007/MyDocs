// 整数数组类IntArray（第2版）

#ifndef ___Class_IntArray
#define ___Class_IntArray

//===== 整数数组类 ======//
class IntArray {
	int nelem;		// 数组的元素个数
	int* vec;		// 指向第一个元素的指针

public:
	//--- 显式构造函数 ---//
	explicit IntArray(int size) : nelem(size) { vec = new int[nelem]; }

	//--- 析构函数 ---//
	~IntArray() { delete[] vec; }

	//--- 返回元素个数 ---//
	int size() const { return nelem; }

	//--- 下标运算符 ---//
	int& operator[](int i) { return vec[i]; }
};

#endif

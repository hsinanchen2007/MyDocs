#ifndef ___Point2D
#define ___Point2D

#include <iostream>

//--- 带标识号的二维坐标类 ---//
class Point2D {
	int xp, yp;					// X坐标和Y坐标
	int id_no;					// 标识号
	static int counter;			// 已经赋予的标识号数量【声明】

public:
	Point2D(int x = 0, int y = 0);		// 构造函数【声明】

	int id() const { return id_no; }	// 标识号

	void print() const {				// 显示坐标
		std::cout << "(" << xp << "," << yp << ")";
	}

	static int get_max_id();			// 返回标识号的最大值【声明】
};

#endif

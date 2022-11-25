#include "Point2D.h"

int Point2D::counter = 0;		// 已经赋予的标识号数量【定义】

//--- 构造函数【定义】---//
Point2D::Point2D(int x, int y) : xp(x), yp(y) {
	id_no = ++counter;		// 赋予标识号
}

//--- 返回标识号的最大值【定义】---//
int Point2D::get_max_id() {
	return counter;			// 返回标识号的最大值
}

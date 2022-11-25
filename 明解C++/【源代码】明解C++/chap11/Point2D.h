#ifndef ___Point2D
#define ___Point2D

//--- 二维坐标类 ---//
class Point2D {
	int xp, yp;		// X坐标和Y坐标

public:
	Point2D(int x = 0, int y = 0) : xp(x), yp(y) { }

	int x() const { return xp; }				// X坐标
	int y() const { return yp; }				// Y坐标

	void print() const { std::cout << "(" << xp << "," << yp << ")"; } // 显示
};

#endif

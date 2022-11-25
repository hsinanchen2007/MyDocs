// 汽车类

#include <cmath>
#include <string>
#include <iostream>

class Car {
	std::string name;			// 名称
	int width, length, height;	// 车宽、车长、车高
	double xp, yp;				// 当前位置坐标
	double fuel_level;			// 剩余燃料

public:
	//--- 构造函数 ---//
	Car(std::string n, int w, int l, int h, double f) {
		name = n;  width = w;  length = l;  height = h;  fuel_level = f;
		xp = yp = 0.0;
	}

	double x() { return xp; }				// 返回当前位置的X坐标
	double y() { return yp; }				// 返回当前位置的Y坐标

	double fuel() { return fuel_level; }	// 返回剩余燃料

	void print_spec() {						// 显示规格
		std::cout << "名称：" << name   << "\n"; 
		std::cout << "车宽：" << width  << "mm\n"; 
		std::cout << "车长：" << length << "mm\n"; 
		std::cout << "车高：" << height << "mm\n"; 
	}

	bool move(double dx, double dy) {	// 在X方向移动dx，在Y方向移动dy
		double dist = sqrt(dx * dx + dy * dy);		// 移动距离

		if (dist > fuel_level)
			return false;				// 燃料不足
		else {
			fuel_level -= dist;			// 减少与移动距离相应的燃料
			xp += dx;
			yp += dy;
			return true;
		}
	}
};

// 汽车类的使用例程

#include <iostream>
#include "Car.h"

using namespace std;

int main()
{
	string name;
	int width, length, height;
	double gas;

	cout << "请输入汽车的数据。\n";
	cout << "名称：";  cin >> name;
	cout << "车宽：";  cin >> width;
	cout << "车长：";  cin >> length;
	cout << "车高：";  cin >> height;
	cout << "汽油量：";  cin >> gas;

	Car myCar(name, width, length, height, gas);

	myCar.print_spec();		// 显示规格

	while (true) {
		cout << "当前位置(" << myCar.x() << ", " << myCar.y() << ")\n";
		cout << "剩余燃料：" << myCar.fuel() << '\n';
		cout << "移动[0...No/1...Yes]：";
		int move;
		cin >> move;
		if (move == 0) break;

		double dx, dy;
		cout << "X方向的移动距离：";  cin >> dx;
		cout << "Y方向的移动距离：";  cin >> dy;
		if (!myCar.move(dx, dy))
			cout << "\a燃料不足！\n";
	}
}

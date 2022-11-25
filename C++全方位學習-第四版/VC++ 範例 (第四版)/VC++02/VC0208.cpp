//儲存檔名：d:\VC++02\VC0208\VC0208.cpp
#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159f;	//宣告浮點常數符號PI

int main(int argc, char** argv)
{
	float area, circu;	//宣告浮點數area,circu
	float radius = 5;	//宣告浮點數radius=5

	area = PI * float(pow(radius, 2));	//area=圓面積1
	circu = 2 * PI * radius;	//circu=圓周長1
	cout << "圓面積1 = " << area
		<< "\t圓周長1 = " << circu;
	radius = 10;	//改變radius=10
	area = PI * float(pow(radius, 2));	//area=圓面積2
	circu = 2 * PI * radius;	//circu=圓周長2
	cout << "\n圓面積2 = " << area
		<< "\t圓周長2 = " << circu << endl;
	return 0;
}

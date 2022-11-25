//d:\Ex06\Ex0603.cpp
//計算球的表面積與體積
#include <iostream>
using namespace std;

double sArea(float pi, float r);
double sVolumn(float pi, float r);

int main(int argc, char** argv) {
	double PI = 3.1415926;
	cout << "半徑\t\t表面積\t\t體積" << endl;
	for (float r=5; r<=10; r++)
	{
		cout << r << "\t\t" << sArea(PI, r) << "\t\t" << sVolumn(PI, r) << endl;
	}
	system("PAUSE");
	return 0;
}

double sArea(float pi, float r)
{
	return 4 * pi * r * r * r;
}

double sVolumn(float pi, float r)
{
	return (4 / 3) * (pi * r * r * r);
}

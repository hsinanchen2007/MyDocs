// Overload.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// 函數的原型
double Max(double, double);
double Max(double, double, double);
//------- 主程式 -----------------------------------
int main()
{
	double a=5.0, b=6.0, c=7.0;
	cout << "Max(a, b)    的值是: " << Max(a, b) << endl;
	cout << "Max(a, b, c) 的值是: "
		<< Max(a, b, c)  << endl;

	system("PAUSE");
	return 0;
}
// --- 函數的定義 ----------------------------------
double Max(double x, double y)
{ 
	return (x>=y) ? x : y;
}

double Max(double x, double y, double z)
{
	double Temp = x;
	if (x<y) Temp = y;
	if (Temp<z) Temp = z;
	return Temp;
}  	
// Default.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- 宣告函數Area() --------------------
double Area(double Width, double Length = 12.0);

// --- 主程式 ----------------------------
int main()
{
	double A;
	A = Area(6.5);				// 只用一個參數呼叫
	cout << "A is : " << A << endl;
	system("PAUSE");
	return 0;
}

// --- 定義函數Area() --------------------
double Area(double Width, double Length)
{ 
	return Width*Length; 
}

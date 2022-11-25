// Swap2F.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- 函數 SwapF () 的宣告 ----------------
void SwapF(double* x, double* y);

// --- 主程式 -----------------------------
int main()
{
	double a = 2, b = 5;
	cout << "執行 SwapF() 前, \n";
	cout << "  a 是: " << a
		<< "  b 是: " << b << endl;
	SwapF(&a, &b);
	cout << "執行 SwapF() 後, \n";
	cout << "  a 是: " << a
		<< "  b 是: " << b << endl;
	system ("pause");
	return 0;
}

// --- 函數 SwapF () 的定義 ----------------
void SwapF(double* x, double* y)
{
	double Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
	return;
}

// Swap2F.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- ��� SwapF () ���ŧi ----------------
void SwapF(double* x, double* y);

// --- �D�{�� -----------------------------
int main()
{
	double a = 2, b = 5;
	cout << "���� SwapF() �e, \n";
	cout << "  a �O: " << a
		<< "  b �O: " << b << endl;
	SwapF(&a, &b);
	cout << "���� SwapF() ��, \n";
	cout << "  a �O: " << a
		<< "  b �O: " << b << endl;
	system ("pause");
	return 0;
}

// --- ��� SwapF () ���w�q ----------------
void SwapF(double* x, double* y)
{
	double Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
	return;
}

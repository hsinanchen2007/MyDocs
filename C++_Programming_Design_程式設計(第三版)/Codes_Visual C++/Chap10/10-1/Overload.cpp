// Overload.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ��ƪ��쫬
double Max(double, double);
double Max(double, double, double);
//------- �D�{�� -----------------------------------
int main()
{
	double a=5.0, b=6.0, c=7.0;
	cout << "Max(a, b)    ���ȬO: " << Max(a, b) << endl;
	cout << "Max(a, b, c) ���ȬO: "
		<< Max(a, b, c)  << endl;

	system("PAUSE");
	return 0;
}
// --- ��ƪ��w�q ----------------------------------
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
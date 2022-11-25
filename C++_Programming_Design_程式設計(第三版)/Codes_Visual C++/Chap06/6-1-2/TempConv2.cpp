// TempConv2.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

//----------------------------------------
double C2F(double C)
{
	double F;
	F = C*9.0/5.0 + 32.0;
	return F;
}
//----- 以下為主程式 -------------------
int main()
{
	double CTemp;
	cout << "  攝氏   華氏 " << endl ;
	cout << "-----------------"  << endl ;
	for ( int i = 1 ; i <= 10 ; i++ )
	{
		CTemp = 10.0*i;
		cout << setw(5) << CTemp << "  "
			<< setw(5) << C2F(CTemp) << endl ;
	}
	cout << "-----------------"  << endl ;
	system("PAUSE");
	return 0;
}



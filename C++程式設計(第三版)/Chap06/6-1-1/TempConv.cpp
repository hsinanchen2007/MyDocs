// TempConv.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;
// --- ���C2F () ���ŧi ------------------------
double C2F(double); 
//------ �D�{�� -------------------------------
int main()
{
	double CTemp;
	cout << "  ���   �ؤ� " << endl ;
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

double C2F(double C)
{
	double F;
	F = C*9.0/5.0 + 32.0;
	return F;
}

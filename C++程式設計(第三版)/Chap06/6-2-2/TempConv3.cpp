// TempConv3.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

void C2F(double, double&); // the function prototype
//------ �D�{�� -------------------------------
int main()
{
	double CTemp, FTemp;
	cout << "  ���   �ؤ� " << endl ;
	cout << "-----------------"  << endl ;
	for ( int i = 1 ; i <= 10 ; i++ )
	{
		CTemp = 10.0*i;
		C2F(CTemp, FTemp);
		cout << setw(5) << CTemp << "  "
			<< setw(5) << FTemp << endl ;
	}
	cout << "-----------------"  << endl ;

	system("PAUSE");
	return 0;
}

void C2F(double C, double& F)
{
	F = C*9.0/5.0 + 32.0;
	return;
}

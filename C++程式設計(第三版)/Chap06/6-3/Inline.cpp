// Inline.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

// ---inline ��� C2F () ���w�q -----------
inline double C2F(double C)
{ 
	return C*9.0/5.0 + 32.0; 
}

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



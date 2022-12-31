// Variable.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- 主程式 ------------------------
int main()
{
	double A = 2.5;

	cout << "A 的值為: "    << A << endl;
	cout << "A 所佔用的記憶體大小為: " << endl;
	cout << " sizeof(A) = "      << sizeof(A)      << " bytes "<<endl;
	cout << " 或是 " << endl;
	cout << " sizeof(double) = " << sizeof(double) << " bytes" << endl;
	cout << "A 所在位址為: "
		 << "0x"  <<   &A  << endl; 

	system ("pause");
	return 0 ;
}


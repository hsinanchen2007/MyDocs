// Variable.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- �D�{�� ------------------------
int main()
{
	double A = 2.5;

	cout << "A ���Ȭ�: "    << A << endl;
	cout << "A �Ҧ��Ϊ��O����j�p��: " << endl;
	cout << " sizeof(A) = "      << sizeof(A)      << " bytes "<<endl;
	cout << " �άO " << endl;
	cout << " sizeof(double) = " << sizeof(double) << " bytes" << endl;
	cout << "A �Ҧb��}��: "
		 << "0x"  <<   &A  << endl; 

	system ("pause");
	return 0 ;
}


// Default.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- �ŧi���Area() --------------------
double Area(double Width, double Length = 12.0);

// --- �D�{�� ----------------------------
int main()
{
	double A;
	A = Area(6.5);				// �u�Τ@�ӰѼƩI�s
	cout << "A is : " << A << endl;
	system("PAUSE");
	return 0;
}

// --- �w�q���Area() --------------------
double Area(double Width, double Length)
{ 
	return Width*Length; 
}

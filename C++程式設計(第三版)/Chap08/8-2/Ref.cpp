// Ref.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- �D�{�� ------------------------
int main()
{
	double x  = 1.0;
	double &y = x;
	double *p = &x;

	cout << "x ��Ӫ��ȬO " << x << endl;
	*p=5.0;
	cout << "���� *p= 5.0; ��\n";
	cout << "x ���ȬO     " << x << endl;
	y = 7.3;
	cout << "���� y = 7.3; ��\n";
	cout << "x ���ȬO     " << x << endl;
	system ("pause");
	return 0 ;
}


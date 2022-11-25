// Ref.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- 主程式 ------------------------
int main()
{
	double x  = 1.0;
	double &y = x;
	double *p = &x;

	cout << "x 原來的值是 " << x << endl;
	*p=5.0;
	cout << "執行 *p= 5.0; 後\n";
	cout << "x 的值是     " << x << endl;
	y = 7.3;
	cout << "執行 y = 7.3; 後\n";
	cout << "x 的值是     " << x << endl;
	system ("pause");
	return 0 ;
}


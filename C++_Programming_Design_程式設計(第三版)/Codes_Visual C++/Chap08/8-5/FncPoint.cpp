// FncPoint.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- 函數 F1()， F2()和Twice() 的宣告 --
double F1(int);
double F2(int);
double Twice(double (*)(int), int);

// --- 主程式 ---------------------------
int main()
{
	int A = 3;
	int B = 5;

	cout  << "Twice(F1, A)的值是: "
		  <<  Twice(F1, A) << endl;
	cout  << "Twice(F2, B)的值是: "
		  <<  Twice(F2, B) << endl;   
	system ("pause");
	return 0 ;
}

// ---- 函數F1()的定義 ---------------------
double F1(int N)
{ 
	return double (N*N);
}

// ---- 函數F2()的定義 ---------------------
double F2(int N)
{ 
	return double (N*N*N);
}

// ---  函數Twice()的定義 ------------------
double Twice(double (*pF)(int), int N)
{
	return 2.0*double(pF(N));
}

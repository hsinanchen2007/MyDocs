// SwapV.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// ---函數的宣告--------------------
void DisplayV1(double*, int);
void DisplayV2(double*, int);
void Swap(double** x, double** y);
// ---主程式------------------------
int main()
{
	const int SizeA = 5;
	const int SizeB = 7;
	double* A = new double [SizeA];
	double* B = new double [SizeB];

	for (int i=0; i<SizeA; i++)
		A[i]= 1.0*i;
	for (int i=0; i<SizeB; i++)
		B[i]= 3.0*i;

	cout << "執行 Swap() 前, \n";
	cout << "A 是 :\n";
	DisplayV1(A, SizeA);
	cout << "B 是 :\n";
	DisplayV2(B, SizeB);

	Swap(&A,&B);

	cout << "執行 Swap() 後, \n";
	cout << "A 是 :\n";
	DisplayV1(A, SizeB);
	cout << "B 是 :\n";
	DisplayV2(B, SizeA);

	delete [] A;
	delete B;
	system ("pause");
	return 0;
}

// ------ 函數DisplayV1()的定義 -------------
void DisplayV1(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << V[i] << " ";
	cout << endl;
	return;
}
// ------- 函數DisplayV2()的定義 -------------
void DisplayV2(double* V, int N)
{
	cout << endl;
	for(int i = 0; i < N; i++)
		cout << setw(5) << *(V+i) << " ";
	cout << endl;
	return;
}
// -------- 函數Swap()的定義 -----------------
void Swap(double** x, double** y)
{
	double* Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

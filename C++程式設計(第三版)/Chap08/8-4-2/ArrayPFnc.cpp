// ArrayPFnc.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---函數 Average()和MaxElem()的宣告
double Average(double *);
double MaxElem(double *);
const int Size =  5;

// ---主程式------------------------
int main()
{
	double P[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};

	cout  << "陣列 P 的平均值是: "
		<< Average(P) << endl;

	cout  << "陣列 P 的最大值是: "
		<< MaxElem(P) << endl;
	system ("pause");
	return 0 ;
}

// ---函數 Average() 的定義----------
double Average(double* V)
{
	double Sum = 0;
	for (int i = 0; i < Size; i++)
		Sum += V[i];
	return Sum/double(Size);
}

// ---函數 MaxElem() 的定義----------
double MaxElem(double* V)
{
	double MaxE;
	MaxE = V[0];
	for (int i = 1; i < Size; i++ )
		if (MaxE < V[i]) MaxE = V[i];
	return MaxE;
}
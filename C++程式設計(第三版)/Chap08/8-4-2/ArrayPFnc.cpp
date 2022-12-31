// ArrayPFnc.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---ㄧ计 Average()㎝MaxElem()
double Average(double *);
double MaxElem(double *);
const int Size =  5;

// ---祘Α------------------------
int main()
{
	double P[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};

	cout  << "皚 P キА琌: "
		<< Average(P) << endl;

	cout  << "皚 P 程琌: "
		<< MaxElem(P) << endl;
	system ("pause");
	return 0 ;
}

// ---ㄧ计 Average() ﹚竡----------
double Average(double* V)
{
	double Sum = 0;
	for (int i = 0; i < Size; i++)
		Sum += V[i];
	return Sum/double(Size);
}

// ---ㄧ计 MaxElem() ﹚竡----------
double MaxElem(double* V)
{
	double MaxE;
	MaxE = V[0];
	for (int i = 1; i < Size; i++ )
		if (MaxE < V[i]) MaxE = V[i];
	return MaxE;
}
// ArrayPFnc.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ---��� Average()�MMaxElem()���ŧi
double Average(double *);
double MaxElem(double *);
const int Size =  5;

// ---�D�{��------------------------
int main()
{
	double P[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};

	cout  << "�}�C P �������ȬO: "
		<< Average(P) << endl;

	cout  << "�}�C P ���̤j�ȬO: "
		<< MaxElem(P) << endl;
	system ("pause");
	return 0 ;
}

// ---��� Average() ���w�q----------
double Average(double* V)
{
	double Sum = 0;
	for (int i = 0; i < Size; i++)
		Sum += V[i];
	return Sum/double(Size);
}

// ---��� MaxElem() ���w�q----------
double MaxElem(double* V)
{
	double MaxE;
	MaxE = V[0];
	for (int i = 1; i < Size; i++ )
		if (MaxE < V[i]) MaxE = V[i];
	return MaxE;
}
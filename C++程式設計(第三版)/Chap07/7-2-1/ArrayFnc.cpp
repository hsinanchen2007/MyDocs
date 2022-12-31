// ArrayFnc.cpp
// --------------------------------------
#include <iostream>
using namespace std;
double Average(double [], int);		// ㄧ计 Average() 
double MaxElem(double [], int);	// ㄧ计 MaxElem() 
// -------- 祘Α ---------------------
int main()
{
	const int Size =  5;
	double P[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};
	P[0] = 3.2;
	P[3] = P[0]*2.0;

	cout  << "皚 P キА琌: " 
		<< Average(P, Size) << endl;

	cout  << "皚 P 程琌 "
		<< MaxElem(P, Size) << endl;

	system("PAUSE");
	return 0;
}

// ------ㄧ计 Average() ﹚竡 ---------------
double Average(double X[], int M)
{
	double Sum = 0;
	for (int i = 0; i < M; i++)
		Sum += X[i];
	return Sum/double(M);    	
}

// ------ㄧ计 MaxElem() ﹚竡 ---------------
double MaxElem(double Y[], int N)
{
	double MaxE;
	MaxE = Y[0];
	for (int i = 1; i < N; i++ )
		if (MaxE < Y[i]) MaxE = Y[i];
	return MaxE; 	
}
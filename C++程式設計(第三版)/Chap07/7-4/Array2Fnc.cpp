// Array2Fnc.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

// ---办跑计 -------------------
const int Row = 2;
const int Col = 3;

// ---ㄧ计 --------------------
void  ShowMatrix(double B[][Col]);
double MatrixAvg(double [ ][Col]);

// ------ 祘Α --------------------
int main()
{
	double A[Row][Col]={ 1.8, 4.9, 6.8,
		6.2, 2.1, 3.4};

	cout  << "皚 A 琌: " << endl;
	ShowMatrix(A);

	cout  << "皚 A キА琌: "
		<< MatrixAvg(A) << endl;

	cout  << "钡盢 A 块挡狦琌 "
		<< A << endl;
	
	system("PAUSE");
	return 0;
}

// ---ㄧ计 ShowMatrix() ﹚竡 ------
void ShowMatrix(double B[][Col])
{
	for (int i=0; i< Row; i++)
	{
		for (int j=0; j< Col; j++)
			cout << setw(5) << B[i][j];
		cout << endl;
	}
	cout << endl;
	return;
}

// ---ㄧ计 MatrixAvg() ﹚竡 ------
double MatrixAvg(double M[ ][Col])
{
	double Sum = 0;
	for (int i=0; i< Row; i++)
		for (int j=0; j< Col; j++)
			Sum+= M[i][j];
	return  Sum / double(Row*Col);
}

// Array2Fnc.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

// ---�����ܼƫŧi -------------------
const int Row = 2;
const int Col = 3;

// ---��ƪ��ŧi --------------------
void  ShowMatrix(double B[][Col]);
double MatrixAvg(double [ ][Col]);

// ------ �D�{�� --------------------
int main()
{
	double A[Row][Col]={ 1.8, 4.9, 6.8,
		6.2, 2.1, 3.4};

	cout  << "�}�C A �O: " << endl;
	ShowMatrix(A);

	cout  << "�}�C A �������ȬO: "
		<< MatrixAvg(A) << endl;

	cout  << "�����N A ��X�����G�O�G "
		<< A << endl;
	
	system("PAUSE");
	return 0;
}

// ---��� ShowMatrix() ���w�q ------
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

// ---��� MatrixAvg() ���w�q ------
double MatrixAvg(double M[ ][Col])
{
	double Sum = 0;
	for (int i=0; i< Row; i++)
		for (int j=0; j< Col; j++)
			Sum+= M[i][j];
	return  Sum / double(Row*Col);
}

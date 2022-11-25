// ShowMatrix.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

// --- 主程式 -----------------------------
int main()
{
	const int Row = 2;
	const int Col = 3;
	double B[Row][Col]={ 1.8, 4.9, 6.8,
		6.2, 2.1, 3.4};
	int i, j;
	cout  << "(1)陣列 B 是: " << endl;
	for (int i=0; i< Row; i++)
	{
		for (int j=0; j< Col; j++)
			cout << setw(5) << B[i][j];
		cout << endl;
	}
	cout << endl;

	cout  << "(2)陣列 B 是: " << endl;
	for (int i=0; i< Row; i++)
	{
		for (int j=0; j< Col; j++)
			cout << setw(5) << *(B[i] + j);
		cout << endl;
	}
	cout << endl;

	cout  << "(3)陣列 B 是: " << endl;
	for (int i=0; i< Row; i++)
	{
		for (int j=0; j< Col; j++)
			cout << setw(5) << *(*(B+i) + j);
		cout << endl;
	}
	system ("pause");  
	return 0;
}

// Factorial.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// --- �ŧi���j��� Factorial() --------------------
int Factorial(int);
// ---- �D�{�� -------------------------------------
int main()
{
	int N;
	cout << "�п�J�@�� 12 �H�U�������: ";
	cin >> N;
	if ( N < 0 )
		cout << "���~! �z��J�F�t��." << endl;
	else
		cout << N << " ! = " << Factorial( N ) << endl;
	system("PAUSE");
	return 0;
}
// --- �w�q���j��� Factorial() ----------------------
int Factorial( int N )
{
	if ( N <= 1 )
		return 1;
	else
		return N * Factorial( N - 1 );
}
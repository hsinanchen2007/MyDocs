// GCD.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// --- �ŧi��� GCD() -----------------------------
int GCD(int, int);
// ---- �D�{�� -------------------------------------
int main()
{
	int Num1, Num2;
	cout << "�п�J�Ĥ@�ӥ���� (�@���): " << endl;
	cin  >> Num1;
	cout << "�п�J�ĤG�ӥ���� (�@���): " << endl;;
	cin  >> Num2;
	cout << Num1 << " �M " << Num2 << " ���̤j�����ƬO "
		<< GCD(Num1, Num2) << endl;
	system("PAUSE");
	return 0;
}
// --- �w�q��� GCD() -----------------------------
int GCD(int M, int N )
{
	if ( (M%N) == 0 )
		return N;
	else
		return GCD(N, M%N);
}
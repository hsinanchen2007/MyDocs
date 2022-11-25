// GCD.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// --- 宣告函數 GCD() -----------------------------
int GCD(int, int);
// ---- 主程式 -------------------------------------
int main()
{
	int Num1, Num2;
	cout << "請輸入第一個正整數 (共兩個): " << endl;
	cin  >> Num1;
	cout << "請輸入第二個正整數 (共兩個): " << endl;;
	cin  >> Num2;
	cout << Num1 << " 和 " << Num2 << " 的最大公約數是 "
		<< GCD(Num1, Num2) << endl;
	system("PAUSE");
	return 0;
}
// --- 定義函數 GCD() -----------------------------
int GCD(int M, int N )
{
	if ( (M%N) == 0 )
		return N;
	else
		return GCD(N, M%N);
}
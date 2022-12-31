// Swap.cpp
// --------------------------------------
#include <iostream>
using namespace std;

void Swap (int&, int&);
void Swap2 (int, int);
//------ 主程式 -------------------------------
int main()
{
	int A=5, B=10;
	Swap(A, B);
	cout << "執行過 Swap()\n";
	cout << " A 的值是："
		<<  A
		<< "\n B 的值是："
		<<  B    << endl;
	cout <<  endl;

	Swap2(A, B);
	cout << "執行過 Swap2()\n";
	cout << " A 的值是："
		<<  A
		<< "\n B 的值是："
		<<  B    << endl;

	system("PAUSE");
	return 0;
}
//------------------------------------
void Swap (int& x, int& y)
{
	int Temp;
	Temp = x; 	x = y;	 y = Temp;
}

//------------------------------------
void Swap2 (int x, int y)
{
	int Temp;
	Temp = x; 	x = y;	 y = Temp;
}


// Swap.cpp
// --------------------------------------
#include <iostream>
using namespace std;

void Swap (int&, int&);
void Swap2 (int, int);
//------ �D�{�� -------------------------------
int main()
{
	int A=5, B=10;
	Swap(A, B);
	cout << "����L Swap()\n";
	cout << " A ���ȬO�G"
		<<  A
		<< "\n B ���ȬO�G"
		<<  B    << endl;
	cout <<  endl;

	Swap2(A, B);
	cout << "����L Swap2()\n";
	cout << " A ���ȬO�G"
		<<  A
		<< "\n B ���ȬO�G"
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


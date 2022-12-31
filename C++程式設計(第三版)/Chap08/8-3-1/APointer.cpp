// APointer.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- 主程式 ------------------------
int main()
{
	const int Size =  5;
	double V[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};
	double Sum = 0.0, Average;
	double *pV = V;
	int i;

	for (i=0; i<Size; i++)
		Sum += *pV++;
	cout  << "陣列 V 各元素的總合是  : "
		  << Sum << endl;
	cout  << "陣列 V 各元素的平均值是: "
		  << Sum / double(Size) << endl;
	system ("pause");
	return 0 ;
}
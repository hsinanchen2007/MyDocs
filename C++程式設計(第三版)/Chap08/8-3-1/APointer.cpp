// APointer.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// ----- �D�{�� ------------------------
int main()
{
	const int Size =  5;
	double V[Size]  = {48.4, 39.8, 40.5, 42.6, 41.2};
	double Sum = 0.0, Average;
	double *pV = V;
	int i;

	for (i=0; i<Size; i++)
		Sum += *pV++;
	cout  << "�}�C V �U�������`�X�O  : "
		  << Sum << endl;
	cout  << "�}�C V �U�����������ȬO: "
		  << Sum / double(Size) << endl;
	system ("pause");
	return 0 ;
}
// Array.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// -------- �D�{�� ---------------------
int main()
{
	const int Size =  5;
	double Average, Max, Sum = 0;
	double P[Size] = {48.4, 39.8, 40.5, 42.6, 41.2};
	int i;
	P[0] = 3.2;
	P[3] = P[0]*2.0;

	cout  << "�U�C���@���}�C P�G\n";
	for (i = 0; i < Size; i++)
		cout << P[i] << "  ";
	cout << endl;

	for (i = 0; i < Size; i++)
		Sum += P[i];
	Average = Sum / double(Size);

	cout  << "�}�C P ���M�O�G "
		  << Sum 
		  << "   �����ȬO: " 
		  << Average << endl;

	Max = P[0];
	for (i = 1; i < Size; i++ )
		if (Max < P[i])	 Max = P[i];

	cout  << "�}�C P ���̤j�ȬO�G "
		<< Max << endl;

	cout  << "�����N P ��X�����G�O�G "
		<< P << endl;

	system("PAUSE");
	return 0;
}
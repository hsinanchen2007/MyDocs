// Array.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// -------- 主程式 ---------------------
int main()
{
	const int Size =  5;
	double Average, Max, Sum = 0;
	double P[Size] = {48.4, 39.8, 40.5, 42.6, 41.2};
	int i;
	P[0] = 3.2;
	P[3] = P[0]*2.0;

	cout  << "下列為一維陣列 P：\n";
	for (i = 0; i < Size; i++)
		cout << P[i] << "  ";
	cout << endl;

	for (i = 0; i < Size; i++)
		Sum += P[i];
	Average = Sum / double(Size);

	cout  << "陣列 P 的和是： "
		  << Sum 
		  << "   平均值是: " 
		  << Average << endl;

	Max = P[0];
	for (i = 1; i < Size; i++ )
		if (Max < P[i])	 Max = P[i];

	cout  << "陣列 P 的最大值是： "
		<< Max << endl;

	cout  << "直接將 P 輸出的結果是： "
		<< P << endl;

	system("PAUSE");
	return 0;
}
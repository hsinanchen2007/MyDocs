// Sum.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
	int N, Sum, Count ;
	cout << "�п�J�n�֭p���ƥ�:" << endl;
	cin  >> N;
	Count = 1 ;
	Sum = 0;
	while ( Count <= N )
	{	
		Sum += Count ;
		Count++;
	}
	cout << "�`�M�O: " << Sum << endl ;
	system("pause");
	return 0;
}
// Sum2.cpp
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
	while ( true )
	{	
		Sum += Count ;
		Count++;
		if ( Count > N ) break;
	}
	cout << "�`�M�O: " << Sum << endl ;
	system("pause");
	return 0;
}

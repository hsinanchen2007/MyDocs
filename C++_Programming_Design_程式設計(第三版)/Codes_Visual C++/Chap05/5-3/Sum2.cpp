// Sum2.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{	
	int N, Sum, Count ;

	cout << "請輸入要累計的數目:" << endl;
	cin  >> N;
	Count = 1 ;
	Sum = 0;
	while ( true )
	{	
		Sum += Count ;
		Count++;
		if ( Count > N ) break;
	}
	cout << "總和是: " << Sum << endl ;
	system("pause");
	return 0;
}

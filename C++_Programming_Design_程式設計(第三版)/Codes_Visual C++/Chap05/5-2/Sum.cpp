// Sum.cpp
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
	while ( Count <= N )
	{	
		Sum += Count ;
		Count++;
	}
	cout << "總和是: " << Sum << endl ;
	system("pause");
	return 0;
}
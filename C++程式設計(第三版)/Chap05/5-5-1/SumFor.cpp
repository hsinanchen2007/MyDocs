// SumFor.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{	
  int N, Sum, Count ;

  cout << "請輸入要累計的數目:" << endl;
  cin  >> N;
  Sum = 0;

  for ( Count = 1 ; Count <= N ; Count++ )
		Sum += Count ;

  cout << "總合是: " << Sum << endl ;

  system("pause");
  return 0;
}
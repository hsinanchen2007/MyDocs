// SumFor2.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{	
  int N, Sum, Count ;
  cout << "�п�J�n�֭p���ƥ�:" << endl;
  cin  >> N;
  Sum = 0;
  Count = 1 ;
  for ( ; Count <= N ; )
  {	
    Sum += Count ;
    Count++ ;
  }
  
  cout << "�`�X�O: " << Sum << endl ;
  system("pause");
  return 0;
}
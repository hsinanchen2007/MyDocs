// SumFor.cpp
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

  for ( Count = 1 ; Count <= N ; Count++ )
		Sum += Count ;

  cout << "�`�X�O: " << Sum << endl ;

  system("pause");
  return 0;
}
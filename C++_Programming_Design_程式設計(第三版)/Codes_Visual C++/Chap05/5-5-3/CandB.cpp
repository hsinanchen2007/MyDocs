// CandB.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ ¥Dµ{¦¡ --------------------
int main()
{
  int i;
  for ( i = 2 ; i <= 20 ; cout << "C ", i=i+2 )
  {
    cout << i;
    if (i==6) continue;
    cout << "A";
    if (i==12)
       break;
    cout << "B";
  }
  cout << endl ;
  system("pause");
  return 0;
}
// Temp.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
// ------ 主程式 --------------------
int main() 
{
  double C;
  cout << "  攝氏   華氏 " << endl ;
  cout << "-----------------"  << endl ;
  int i;
  for ( i = 1 ; i <= 10 ; i++ )
  {
    C = 10.0*i;    // C = 10.0*double(i);
    cout << setw(5) << C << "  " << setw(5)
         << C*9.0/5.0 + 32.0     << endl ;
  }

  cout << "-----------------"  << endl ;
  system("pause");
  return 0;
}
// BoolCheck.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ---------------- ¥Dµ{¦¡ -------------------------
int main()
{
  bool b1, b2, b3, b4;
  b1= true;
  b2= false;
  b3= (3>1);
  b4= (3<1);

  cout << "b1 = " << b1 << endl;
  cout << "b2 = " << b2 << endl;
  cout << "b3 = " << b3 << endl;
  cout << "b4 = " << b4 << endl;
  cout << "Size of bool is : " << sizeof(bool)
       << " byte" << endl;
  cout << "Size of b1 is   : " << sizeof(b1)
       << " byte" << endl;

  system("PAUSE");
  return 0;
}

// BitOp.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ---------------- ¥Dµ{¦¡ -------------------------
int main()
{
  short Ia = 0x5678;
  short Ib = 0x12ff;
  short S1 = 52;
  short S2 = 14;
  char C1  = 'A';
  char C2  = 'b';
  cout << hex;
  cout << "Ia & Ib = ox"
       <<  (Ia & Ib) << endl;
  cout << "Ia ^ Ib = ox"
       << (Ia ^ Ib) << endl;
  cout << "Ia | Ib = ox"
       <<  (Ia | Ib) << endl;
  cout << "S1 & S2 = ox"
       << (S1 & S2) << endl;
  cout << "S1 ^ S2 = ox"
       << hex << (S1 ^ S2) << endl;
  cout << "S1 | S2 = ox"
       << hex << (S1 | S2) << endl;
  cout << "C1 & C2 = "  << (C1&C2) << endl;
  cout << "C1 ^ C2 = "  << (C1^C2) << endl;
  cout << "C1 | C2 = "  << (C1|C2) << endl;
  cout << "C1 & Ib = ox"<< (C1&Ib) << endl;
  cout << "   ~Ia  = ox"
       << (~Ia) << endl;
  cout << "   ~C1  = ox"
       << (~C1) << endl;
  cout << "S1 >> 2 = ox"
       << (S1 >> 2) << endl;
  cout << "C1 >> 2 = ox"
       << (C1>>2) << endl;

  system("PAUSE");
  return 0;
}
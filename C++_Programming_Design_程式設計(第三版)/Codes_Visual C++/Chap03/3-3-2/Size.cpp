// Size.cpp
// A program to check the size of data types
// --------------------------------------
#include <iostream>
using namespace std;
// ---------------- ¥Dµ{¦¡ -------------------------
int main()
{
  int a=5;
  cout << " Size of int is     : " << sizeof(int)
       << " bytes" << endl;
  cout << " Size of short is   : " << sizeof(short)
       << " bytes" << endl;
  cout << " Size of unsigned is: " << sizeof(unsigned)
       << " bytes" << endl;
  cout << " Size of long is    : " << sizeof(long)
       << " bytes" << endl;
  cout << " Size of float is   : " << sizeof(float)
       << " bytes" << endl;
  cout << " Size of double is  : " << sizeof(double)
       << " bytes" << endl;
  cout << " Size of char is    : " << sizeof(char)
       << " bytes" << endl;
  cout<<  " Size of 3.8  is    : " << sizeof(3.8)
       << " bytes" << endl;
  cout<<  " Size of 3.8 + a is : " << sizeof(3.8 + a)
       << " bytes" << endl;
  cout<<  " Size of 3.8f is    : " << sizeof(3.8f)
       << " bytes" << endl;
  cout<<  " Size of a is       : " << sizeof(a)
       << " bytes" << endl;
  cout<<  " Size of (3.8f + a) is: " << sizeof(3.8f + a)
       << " bytes" << endl;

  system("PAUSE");
  return 0;
}
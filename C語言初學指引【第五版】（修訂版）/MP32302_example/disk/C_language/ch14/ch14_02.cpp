/*    �ɦW:ch14_02.cpp    �\��:cin���󪺽m��    */

#include <iostream>

using namespace std;

int main()
{
  int   a1,a2;
  float b;
  char s[100];
  int* p;
  
  p=&a2;                 // p���Va2
  cout << "�п�Ja1,a2:";
  cin >> a1 >> *p;
  cout << "�п�Jb:";
  cin >> b;
  cout << "�п�Js�r��:";
  cin >> s;
  cout << "a1=" << a1 << "\ta2=" << a2 << "\tb=" << b << "\ts=" << s << endl;
  return 0;
}

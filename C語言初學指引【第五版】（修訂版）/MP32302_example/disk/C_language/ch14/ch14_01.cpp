/*    �ɦW:ch14_01.cpp    �\��:cout���󪺽m��    */

#include <iostream>

using namespace std;

int main()
{
  int   a=1;
  float b=2.3;
  char* s="Hello C++";    //�PC�y����char *s 
  int* p;                 //�PC�y���� int *p;
  
  p=&a;
  cout << "a=" << a << "\n";
  cout << "b=" << b << endl;
  cout << "s=" << s << endl;
  cout << "p=" << p << endl;
  return 0;
}

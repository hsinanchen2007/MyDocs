/*    檔名:ch14_01.cpp    功能:cout物件的練習    */

#include <iostream>

using namespace std;

int main()
{
  int   a=1;
  float b=2.3;
  char* s="Hello C++";    //同C語言的char *s 
  int* p;                 //同C語言的 int *p;
  
  p=&a;
  cout << "a=" << a << "\n";
  cout << "b=" << b << endl;
  cout << "s=" << s << endl;
  cout << "p=" << p << endl;
  return 0;
}

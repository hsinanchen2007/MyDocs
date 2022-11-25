// Average.cpp
// --------------------------------------
#include <iostream>
using std::cout;
using std::endl;
// ---------------- 主程式 -------------------------
int main()
{
  int Number = 3;
  float a, b;
  float c = 5.6;
  float Average;
  a = 7.8;	b=3.9;
  Average = (a + b + c) / Number;
  cout << "a, b, c 的平均值是: "
              << Average << endl;

  system("PAUSE");
  return 0;
}

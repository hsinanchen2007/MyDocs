//  Power3.cpp
//  x的3次方計算
// --------------------------------------
#include <cmath>
#include <iostream>
using namespace std;
// ---------------- 主程式 -------------------------
int main()
{

  float x ;
  cout << "請輸入一個數值:\n ";
  cin >> x;
  cout << "它的3次方是: "
       << pow(x,3) << endl;
  
  system("PAUSE");
  return 0;
  
}

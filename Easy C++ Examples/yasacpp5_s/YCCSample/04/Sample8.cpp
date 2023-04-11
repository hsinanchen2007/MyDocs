#include<iostream>
using namespace std;

int main()
{
   int inum = 160;
   double dnum;

   cout << "身高是" << inum << "厘米。\n";
   cout << "代入到 double 型的变量中。\n";

   dnum = inum;
   
   cout << "身高是" << dnum << "厘米。\n";

   return 0;
}

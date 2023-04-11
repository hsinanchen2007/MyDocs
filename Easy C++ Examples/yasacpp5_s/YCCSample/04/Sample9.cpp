#include<iostream>
using namespace std;

int main()
{
   double dnum = 160.5;
   int inum;

   cout << "身高是" << dnum << "厘米。\n";
   cout << "代入到 int 类型的变量中。\n";

   inum = dnum;
   
   cout << "身高是" << inum << "厘米。\n";

   return 0;
}

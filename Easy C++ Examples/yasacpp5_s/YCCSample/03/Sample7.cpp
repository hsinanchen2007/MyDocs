#include <iostream>
using namespace std;

int main()
{
   const double pi = 3.1415;

   cout << "圆周率的值是" << pi << "。\n";
   cout << "圆周率的值不会改变。\n";

   //这样的代入不能进行变更
   //pi = 1.44;

   return 0;
}

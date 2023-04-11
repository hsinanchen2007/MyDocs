#include <iostream>
using namespace std;

int main()
{
   int a;
   int* pA;

   a = 5;
   pA = &a;

   cout << "变量 a 的值为" << a << "。\n";

   *pA = 50;

   cout << "将 50 代入 pA 中。\n";
   cout << "变量 a 的值为" << a << "。\n";

   return 0;
}

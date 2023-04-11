#include <iostream>
using namespace std;

int main()
{
   int a = 5;
   int& rA = a;

   cout << "变量 a 的值为" << a << "。\n";
   cout << "引用 rA 的值为" << rA << "。\n";

   rA = 50;

   cout << "将 50 代入 rA 中。\n";
   cout << "引用 rA 的值变为" << rA << "。\n";
   cout << "变量 a 的值也变为" << a << "。\n";
   cout << "变量 a 的地址为" << &a << "。\n";
   cout << "引用 rA 的地址也为" << &rA << "。\n";

   return 0;
}

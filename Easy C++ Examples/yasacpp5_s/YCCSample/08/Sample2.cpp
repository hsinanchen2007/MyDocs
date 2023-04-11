#include <iostream>
using namespace std;

int main()
{
   int a;
   int* pA;

   a = 5;
   pA = &a;

   cout << "变量 a 的值为" << a << "。\n";
   cout << "变量 a 的地址 (&a) 为" << &a << "。\n";
   cout << "指针 pA 的值为" << pA << "。\n";	

   return 0;
}

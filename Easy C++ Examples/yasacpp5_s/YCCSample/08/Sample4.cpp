#include <iostream>
using namespace std;

int main()
{
   int a = 5;
   int b = 10;
   int* pA;

   pA = &a;

   cout << "变量 a 的值为" << a << "。\n";
   cout << "指针 pA 的值" << pA << "。\n";	
   cout << "*pA 的值为" << *pA << "。\n";

   pA = &b;

   cout << "变量 b 的值为" << b << "。\n";
   cout << "指针 pA 的值变更为" << pA << "。\n";
   cout << "*pA 的值为" << *pA << "。\n";

   return 0;
}

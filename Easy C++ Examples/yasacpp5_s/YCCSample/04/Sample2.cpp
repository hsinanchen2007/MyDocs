#include <iostream>
using namespace std;

int main()
{
   int num1 = 2;
   int num2 = 3;
   int sum = num1+num2;

   cout << "变量 num1 为" << num1 << "这个值。\n";
   cout << "变量 num2 为" << num2 << "这个值。\n";
   cout << "num1+num2的结果为" << sum << "这个值。\n";

   num1 = num1+1;

   cout << "变量 num1 的值每增加 1 就会变成" << num1 << "这个值。\n";

   return 0;
}

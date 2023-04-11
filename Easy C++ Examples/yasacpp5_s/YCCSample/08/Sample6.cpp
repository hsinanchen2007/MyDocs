#include <iostream>
using namespace std;

//错误的 swap 函数声明
void swap(int x, int y);

int main()
{
   int num1 = 5;
   int num2 = 10;

   cout << "变量 num1 的值为" << num1 << "。\n";
   cout << "变量 num2 的值为" << num2 << "。\n";
   cout << "交换 num1 与 num2 的值。\n";

   swap(num1, num2);

   cout << "变量 num1 的值为" << num1 << "。\n";
   cout << "变量 num2 的值为" << num2 << "。\n";

   return 0;
}

//错误的 swap 函数定义
void swap(int x, int y)
{
   int tmp;

   tmp = x;
   x = y;
   y = tmp;
}

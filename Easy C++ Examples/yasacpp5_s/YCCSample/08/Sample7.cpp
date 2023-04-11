#include <iostream>
using namespace std;

// swap 函数的声明
void swap(int* pX, int* pY);

int main()
{
   int num1 = 5;
   int num2 = 10;

   cout << "变量 num1 的值为" << num1 << "。\n";
   cout << "变量 num2 的值为" << num2 << "。\n";
   cout << "交换 num1 与 num2 的值。\n";

   swap(&num1, &num2);

   cout << "变量 num1 的值为" << num1 << "。\n";
   cout << "变量 num2 的值为" << num2 << "。\n";

   return 0;
}

//swap 函数的定义
void swap(int* pX, int* pY)
{
   int tmp;

   tmp = *pX;
   *pX = *pY;
   *pY = tmp;
}

#include <iostream>
using namespace std;

// func 函数的声明
void func();

int a = 0; 

//main函数
int main()
{
   int b = 1;

   cout << "main 函数中可以使用变量 a 和 b。\n";
   cout << "变量 a 的值是" << a << "。\n";
   cout << "变量 b 的值是" << b << "。\n";
   //cout << "变量 c 的值是" << c << "。\n";

   func();

   return 0;
}

//func 函数的定义
void func()
{
   int c = 2;

   cout << "func 函数中可以使用变量 a 和 c。\n";
   cout << "变量 a 的值是" << a << "。\n";
   //cout << "变量 b 的值是" << b << "。\n";
   cout << "变量 c 的值是" << c << "。\n";
}

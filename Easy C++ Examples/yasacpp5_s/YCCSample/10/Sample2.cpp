#include <iostream>
using namespace std;

// func 函数的声明
void count();

int a = 0;

//main函数
int main()
{
   for(int i=0; i<5; i++)
      count();

  return 0;
}

//count函数的定义
void count()
{
   int b = 0;
   static int c = 0;

   cout << "变量 a 是" << a << "变量 b 是" << b << "变量 c 是" << c << "。\n";

   a++;
   b++;
   c++;
}

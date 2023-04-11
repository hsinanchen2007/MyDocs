#include <iostream>
using namespace std;

int main()
{
   int a = 1;
   int b = 0;

   cout << "short int型的长度是" << sizeof(short int) << "字节。\n";
   cout << "int型的长度是" << sizeof(int) << "字节。\n";
   cout << "long int型的长度是" << sizeof(long int) << "字节。\n";
   cout << "float型的长度是" << sizeof(float) << "字节。\n";
   cout << "double型的长度是" << sizeof(double) << "字节。\n";
   cout << "long double型的长度是" << sizeof(long double) << "字节。\n";
   cout << "变量 a 的长度是" << sizeof(a) << "字节。\n";
   cout << "表达式 a+b 的长度是" << sizeof(a+b) << "字节。\n";

   return 0;
}

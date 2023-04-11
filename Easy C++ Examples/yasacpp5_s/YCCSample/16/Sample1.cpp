#include <iostream>
using namespace std;

int main()
{
   int i;
   double d;
   char str[100];

   cout << "请输入整数值。\n";
   cin >> i;
   cout << "请输入小数值。\n";
   cin >> d;
   cout << "请输入字符串。\n";
   cin >> str;

   cout << "输入的整数值是" << i << "。\n";
   cout << "输入的小数值是" << d << "。\n";
   cout << "输入的字符串是" << str << "。\n";

   return 0;
}

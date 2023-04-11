#include <iostream>
using namespace std;

int main()
{
   double pi = 3.141592;
   int num;

   cout << "显示圆周率。\n";
   cout << "显示几位有效位数？(1~7)\n";
   cin >> num;

   cout.precision(num);

   cout << "圆周率是" << pi << "。\n";

   return 0;
}


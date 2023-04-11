#include <iostream>
#include "myfunc.h"
using namespace std;

int main()
{
   int num1, num2, ans;

   cout << "请输入第 1 个整数。\n";
   cin >> num1;

   cout << "请输入第 2 个整数。\n";
   cin >> num2;

   ans = max(num1, num2);

   cout << "最大值是" << ans << "。\n";

   return 0;
}

#include <iostream>
using namespace std;

//max 函数的定义
int max(int x, int y)
{
   if (x > y)
      return x;
   else
      return y;
}

int main()
{
   int num1, num2, ans;

   cout << "请输入第一个整数。\n";
   cin >> num1;

   cout << "请输入第二个整数。\n";
   cin >> num2;

   ans = max(num1, num2);

   cout << "最大值为" << ans << "。\n";

   return 0;
}

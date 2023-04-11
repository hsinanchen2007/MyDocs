#include <iostream>
using namespace std;

// sum 函数的定义
int sum(int x, int y)
{
   return x+y;
}

int main()
{
   int num1, num2, ans;

   cout << "请输入第一个整数。\n";
   cin >> num1;

   cout << "请输入第二个整数。\n";
   cin >> num2;

   ans = sum(num1, num2);

   cout << "合计共" << ans << "。\n";

   return 0;
}

#include <iostream>
using namespace std;

//max 函数的声明
int max(int x, int y);
double max(double x, double y);

int main()
{
   int a, b;
   double da, db;

   cout << "请输入两个整数。\n";
   cin >> a >> b;

   cout << "请输入两个小数。\n"; 
   cin >> da >> db;

   int ans1 = max(a, b);
   double ans2 = max(da, db);

   cout << "整数的最大值为" << ans1 << "。\n";
   cout << "小数的最大值为" << ans2 << "。\n";

   return 0;
}

//max(int 型 ) 函数的定义
int max(int x, int y)
{
   if (x > y)
      return x;
   else 
      return y;
}

//max 函数 (double 型 ) 的定义
double max(double x, double y)
{
   if (x > y)
      return x;
   else 
      return y;
}

#include <iostream> 
using namespace std;

//函数模板
template <class T>
T maxt(T x, T y)
{
   if(x > y)
      return x;
   else
      return y;
}

//
int main()
{
   int a, b;
   double da, db;

   cout << "请输入两个整数。\n";
   cin >> a >> b;

   cout << "请输入两个小数。\n"; 
   cin >> da >> db;

   int ans1 = maxt(a, b);
   double ans2 = maxt(da, db);

   cout << "整数中的最大值为" << ans1 << "。\n";
   cout << "小数中的最大值为" << ans2 << "。\n";

   return 0;
}

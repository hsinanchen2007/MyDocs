#include <iostream>
using namespace std;

// buy 函数的定义
int buy(int x, int y)
{
   int z;

   cout << "买了" << x << "万元和" << y << "万元的车。\n";

   z = x+y;

   return z;
}

// buy 函数的调用
int main()
{
   int num1, num2, sum;

   cout << "买了几万元的车？\n";
   cin >> num1;

   cout << "买了几万元的车？\n";
   cin >> num2;

   sum = buy(num1, num2);

   cout << "共" << sum << "万元。\n";

   return 0;
}

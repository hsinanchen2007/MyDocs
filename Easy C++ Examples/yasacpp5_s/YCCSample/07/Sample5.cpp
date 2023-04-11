#include <iostream>
using namespace std;

//buy 函数的定义
void buy(int x, int y)
{
   cout << "买了" << x << "万元和" << y << "万元的车。\n";
}

//buy 函数的调用
int main()
{
   int num1, num2;

   cout << "买了几万元的车？\n";
   cin >> num1;

   cout << "买了几万元的车？\n";
   cin >> num2;

   buy(num1, num2);

   return 0;
}

#include <iostream>
using namespace std;

//buy 函数的定义
void buy(int x)
{
   cout << "买了一辆" << x << "万元的车。\n";
}

//buy 函数的调用
int main()
{
   int num;

   cout << "第一辆买几万元的车？ \n";
   cin >> num;

   buy(num);

   cout << "第二辆买几万元的车？\n";
   cin >> num;

   buy(num);

   return 0;
}

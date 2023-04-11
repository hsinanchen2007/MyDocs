#include <iostream>
using namespace std;

//buy 函数的定义
void buy(int x)
{
   cout <<  "买了一辆" << x << "万元的车。\n";
}

//buy 函数的调用
int main()
{
   buy(20);
   buy(50);

   return 0;
}

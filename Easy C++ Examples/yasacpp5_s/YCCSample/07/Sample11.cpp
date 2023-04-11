#include <iostream>
using namespace std;

//buy 函数的声明
void buy(int x=10);

//buy 函数的调用
int main()
{
   cout <<  "第一次用 100 万元买。\n";
   buy(100);

   cout <<  "第二次用默认金额买。\n";
   buy();

   return 0;
}

//buy 函数的定义
void buy(int x)
{
   cout << " 买了 " << x << "万元的车。\n";
}
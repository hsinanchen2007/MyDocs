#include <iostream>
using namespace std;

int main()
{
   int sum = 0;
   int num = 0;

   cout << "请输入第 1 个整数。\n";
   cin >> num;
   sum += num;
   cout << "请输入第 2 个整数。\n";
   cin >> num;
   sum += num;
   cout << "请输入第 3 个整数。\n";
   cin >> num;
   sum += num;

   cout << "3 个数的总和是" << sum << "这个值。\n";

   return 0;
}

#include <iostream>
using namespace std;

int main()
{
   int num = 1;

   while(num){
      cout << "输入整数。( 数字为 0 时终止 )\n";
      cin >> num;
      cout << num << "被输入。\n";
   }
   cout << "循环终止。\n";

   return 0;
}

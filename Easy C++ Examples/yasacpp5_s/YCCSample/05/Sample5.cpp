#include <iostream>
using namespace std;

int main()
{
   int res; 

   cout << "请输入整数。\n";

   cin >> res;

   switch(res){
      case 1:
         cout << "已输入 1。\n";
         break;
      case 2:
         cout << "已输入 2。\n";
         break;
      default:
         cout << "请输入 1 或 2。\n";
         break;
   }

   return 0;
}

#include <iostream>
using namespace std;

int main()
{
   int res; 

   cout << "请输入整数。\n";

   cin >> res;

   if (res == 1){
      cout << "已输入 1。\n";
   }
   else if(res == 2){
      cout << "已输入 2。\n";
   }
   else{
      cout << "请输入 1 或 2。\n";
   }

   return 0;
}

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
   else{
      cout << "1 以外的数值被输入。\n";
   }

   return 0;
}

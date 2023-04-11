#include <iostream>
using namespace std;

int main()
{
   int res;

   cout << "跳过第几次循环？ (1~10)\n";

   cin >> res;

   for(int i=1; i<=10; i++){
      if(i == res)
         continue;
      cout << "第" << i << "次循环。\n";
   }

   return 0;
}

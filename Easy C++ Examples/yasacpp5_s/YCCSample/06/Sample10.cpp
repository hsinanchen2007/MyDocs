#include <iostream>
using namespace std;

int main()
{
   int res;

   cout << "在第几次终止循环？ (1~10)\n";

   cin >> res;

   for(int i=1; i<=10; i++){
      cout << "第" << i << "次循环。\n";
      if(i == res)
         break;
   }

   return 0;
}


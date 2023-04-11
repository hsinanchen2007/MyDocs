#include <iostream>
using namespace std;

int main()
{
   int i = 1;
 
   do{
      cout << "第" << i << "次循环\n";
      i++;
   }while(i <= 5);

   cout << "循环终止。\n";

   return 0;
}

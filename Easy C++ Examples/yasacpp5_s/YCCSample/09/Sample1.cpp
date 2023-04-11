#include <iostream>
using namespace std;

int main()
{
   int test[5];
  
   test[0] = 80;
   test[1] = 60;
   test[2] = 22;
   test[3] = 50;
   test[4] = 75;

   for(int i=0; i<5; i++){
      cout <<" 第 " << i+1 << "个人的分数是" << test[i] << "。\n";
   }

   return 0;
}
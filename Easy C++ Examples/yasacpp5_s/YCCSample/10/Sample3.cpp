#include <iostream>
using namespace std;

int main()
{
   int* pA;

   pA = new int;

   cout << "动态分配了内存空间。\n";

   *pA = 10;

   cout << "使用动态分配的内存空间" << *pA << "并输出。\n";

   delete pA;

   cout << "释放分配的内存空间。\n";

   return 0;
}

#include <iostream>
using namespace std;

int main()
{
   int a = 0;
   int b = 0;

   b = a++;

   cout << "代入后进行了自增，所以 b 为" << b << "这个值。\n";

   return 0;
}

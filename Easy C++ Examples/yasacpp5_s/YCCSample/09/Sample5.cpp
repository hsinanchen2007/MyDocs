#include <iostream>
using namespace std;

int main()
{
   int test[5] = {80,60,55,22,75};

   cout << "test[0]的值是" << test[0] << "。\n";
   cout << "test[0]的地址是" << &test[0] << "。\n";
   cout << "test的值是" << test << "。\n";
   cout << "所以 *test 的值是" << *test << "。\n";

   return 0;
}

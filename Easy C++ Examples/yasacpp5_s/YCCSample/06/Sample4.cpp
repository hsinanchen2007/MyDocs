#include <iostream>
using namespace std;

int main()
{
   int num;
   int sum = 0;

   cout << "求 1 至几的和？\n";

   cin >> num;

   for(int i=1; i<=num; i++){
      sum += i; 
   }

   cout << "从 1 至" << num << "的求和为" << sum << "。\n";

   return 0;
}

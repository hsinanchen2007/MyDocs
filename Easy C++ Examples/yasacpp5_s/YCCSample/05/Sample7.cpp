#include <iostream>
using namespace std;

int main()
{
   int res;
   char ans;

   cout << "选择第几条路线？\n";
   cout << "请输入整数。\n";

   cin >> res;

   ans = (res==1) ? 'A' : 'B'; 

   cout << ans << "选择了路线" << ans <<"。\n";

   return 0;
}

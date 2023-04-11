#include <iostream>
using namespace std;

int main()
{
   int res; 

   cout << "请输入成绩。(1~5)\n";

   cin >> res;

   switch(res){
      case 1:
      case 2:
         cout << "再努力一点吧。\n";
         break;
      case 3:
      case 4:
         cout << "保持劲头，继续努力。\n";
         break;
      case 5:
         cout << "太优秀了。\n";
         break;
      default:
         cout << "请输入 1~5 的成绩。\n";
         break;
   }
   
   return 0;
}

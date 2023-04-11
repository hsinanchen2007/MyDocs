#include <iostream>
using namespace std;

int main()
{
   char res; 

   cout << "你是男性吗 ?\n";
   cout << "请输入 Y 或 N。\n";

   cin >> res;

   if (res == 'Y' || res == 'y'){
      cout << "你是男性。\n";
     }
   else if(res == 'N' || res == 'n'){
      cout << "你是女性。\n";
   }
   else{
      cout << "请输入 Y 或 N。\n";
   }

   return 0;
}

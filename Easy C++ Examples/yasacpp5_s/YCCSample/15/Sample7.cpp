#include <iostream>
using namespace std;

int main()
{
   int num;
   cout << "请输入 1~9 的数字。\n";
   cin >> num;

   try{
      if(num <= 0)
         throw "输入了 0 以下。";
      if(num >= 10)
         throw "输入了 10 以上。";
      cout << num << "。\n";
   }

   catch(const char* err){
      cout << "错误信息:" << err << '\n';
      return 1;
   }

   return 0;
}

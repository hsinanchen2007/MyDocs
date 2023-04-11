#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   ofstream fout("test0.txt");
   if(!fout){
      cout << "打不开文件。\n";
      return 1;
   }
   else
      cout  << "打开了文件。\n";

   fout.close();
   cout  << "关闭了文件。\n";

   return 0;
}

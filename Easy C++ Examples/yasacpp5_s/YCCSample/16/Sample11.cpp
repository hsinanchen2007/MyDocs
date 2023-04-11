#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   ofstream fout("test1.txt");
   if(!fout){
      cout << "打不开文件。\n";
      return 1;
   }
   else
      cout  << "打开了文件。\n";

   fout << "Hello!\n";
   fout << "Goodbye!\n";
   cout << "写入了文件。\n";

   fout.close();

   return 0;
}

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   ifstream fin("test1.txt");
   if(!fin){
      cout << "打不开文件。\n";
      return 1;
   }

   char str1[16];
   char str2[16];
   fin >> str1 >> str2;
   cout << "写入文件的两个字符串 :\n";
   cout << str1 << "！\n";
   cout << str2 << "！\n";

   fin.close();

   return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   char str0[20];
   char str1[10];
   char str2[10];

   strcpy_s(str1, 10, "Hello");
   strcpy_s(str2, 10, "Goodbye");
   strcpy_s(str0, 20, str1);
   strcat_s(str0, 20, str2);

   cout << "数组 str1 是" << str1 << "。\n"; 
   cout << "数组 str2 是" << str2 << "。\n"; 

   cout << "连接的话则是" << str0 << "。\n"; 

   return 0;
}

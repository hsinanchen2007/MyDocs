#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   char str[100];

    cout << "请输入字符串（字母）。\n";

    cin >> str;

    cout << "字符串的长度是" << strlen(str) << "。\n";

   return 0;
}

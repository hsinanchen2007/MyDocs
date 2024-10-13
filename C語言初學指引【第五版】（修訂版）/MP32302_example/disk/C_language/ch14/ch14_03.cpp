/*    檔名:ch14_03.cpp    功能:兩種字串的轉換  */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
 string str1="Wel";
 char* str2="co";
 string str3="me";
 string str4;
 const char* str5="";
  
 str4=str1+str2+str3;
 str5=str4.c_str();
 
 cout << "str4=" << str4 << endl;
 cout << "str5=" << str5 << endl;
 system("pause");
 return 0;
}

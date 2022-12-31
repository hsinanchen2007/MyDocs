// StringProc.cpp
// --------------------------------------
#include <iostream>
#include <cstring> 
using namespace std;

// ---主程式------------------------
int main()
{
  const int SLength = 30;
  char S1[SLength] = "Hello, 您好!";
  char S2[SLength] = "Good boy.";
  char *pS1, *pS2;
  pS1=S1;
  pS2=S2;

  cout << "\n"
       << "pS1 的值為  :  " << pS1 << "\n"
       << "pS1 的長度為:  "
       <<  strlen(pS1) << " 字元." << endl;
  cout << "\n"
       << "S1 的值為  :  " << S1 << "\n"
       << "S1 的長度為:  "
       <<  strlen(S1)  << " 字元." << endl;
  cout << "\n"
       << "pS2 的值為  :  " << pS2 << "\n"
       << "pS2 的長度為:  "
       << strlen(pS2) << " 字元." << endl;
  strcat(S1, S2);
  cout << "執行 strcat(S1, S2); 後,"
       << "S1 的值為:  \n" 
       << S1 <<  endl;
  cout << "執行 strcmp(S1, S2); 的值為: "
       << strcmp(S1, S2) <<  endl;
  char *p= strchr(S1, 'l');
  cout << "第1個 'l' 位於 S1 的第 "
       << (p - pS1)+1 << " 個字元的位置" << endl;
  cout << "執行 strchr(S1, 'l'); 的值為: "
       << strchr(S1, 'l') <<  endl;
  strcpy(S1, S2);
  cout << "執行 strcpy(S1, S2); 後,"
       << "S1 的值為:  \n" 
       << S1 <<  endl;

  system ("pause");
  return 0;
}

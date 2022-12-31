// CharTest.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ 主程式 --------------------
int main()
{
  char C;
  cout << "\n"
       << "請輸入一個字母  :  " << endl;
  cin  >> C;
  if (C < 65 || C >122)
      cout <<  "您輸入的不是字母!";    
  else
    {
      cout << "您輸入的字母是";
      switch (C)
      {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          cout << "母音字母"<< endl;
          break;
        default:
          cout << "子音字母" << endl;
      }
    }
  system("pause");
}

/*
請輸入一個字母  :
e  
您輸入的字母是母音字母


請輸入一個字母  : 
3 
您輸入的不是字母!
*/
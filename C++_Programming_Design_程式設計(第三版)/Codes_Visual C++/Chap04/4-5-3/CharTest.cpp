// CharTest.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ------ �D�{�� --------------------
int main()
{
  char C;
  cout << "\n"
       << "�п�J�@�Ӧr��  :  " << endl;
  cin  >> C;
  if (C < 65 || C >122)
      cout <<  "�z��J�����O�r��!";    
  else
    {
      cout << "�z��J���r���O";
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
          cout << "�����r��"<< endl;
          break;
        default:
          cout << "�l���r��" << endl;
      }
    }
  system("pause");
}

/*
�п�J�@�Ӧr��  :
e  
�z��J���r���O�����r��


�п�J�@�Ӧr��  : 
3 
�z��J�����O�r��!
*/
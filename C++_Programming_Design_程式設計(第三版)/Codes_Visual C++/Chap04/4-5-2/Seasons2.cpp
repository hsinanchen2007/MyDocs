// Seasons.cpp
// --------------------------------------
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// ------ �D�{�� --------------------
int main()
{
  int Month;
  cout << "\n"
       << "�п�J�@�Ӥ��  :  " << endl;
  cin  >> Month;
  if (Month < 1 || Month >12)
      cout <<  "�z��J������S���N�q!";    
  else
    {
      cout << "\n" << Month << "��O";
      switch ((Month%12)/3)
      {
        case 0:
          cout << "�V�u"<< endl;
        case 1:
          cout << "�K�u"<< endl;
        case 2:
          cout << "�L�u"<< endl;
        case 3:
          cout << "��u"<< endl;
        default:
          cout << "�{�������D!" << endl;
      }
    }
   system("pause");
}

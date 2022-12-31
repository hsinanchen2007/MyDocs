// Seasons.cpp
// --------------------------------------
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// ------ 主程式 --------------------
int main()
{
  int Month;
  cout << "\n"
       << "請輸入一個月份  :  " << endl;
  cin  >> Month;
  if (Month < 1 || Month >12)
      cout <<  "您輸入的月份沒有意義!";    
  else
    {
      cout << "\n" << Month << "月是";
      switch ((Month%12)/3)
      {
        case 0:
          cout << "冬季"<< endl;
        case 1:
          cout << "春季"<< endl;
        case 2:
          cout << "夏季"<< endl;
        case 3:
          cout << "秋季"<< endl;
        default:
          cout << "程式有問題!" << endl;
      }
    }
   system("pause");
}

#include <iostream>
using namespace std;

//声明 Week 枚举类型
enum Week{SUN, MON, TUE, WED, THU, FRI, SAT};

int main()
{
   Week w;
   w = SUN;

   switch(w){
      case SUN: cout << "周日。\n"; break;
      case MON: cout << "周一。\n"; break;
      case TUE: cout << "周二。\n"; break;
      case WED: cout << "周三。\n"; break;
      case THU: cout << "周四。\n"; break;
      case FRI: cout << "周五。\n"; break;
      case SAT: cout << "周六。\n"; break;
      default: cout << "不知道是周几。\n"; break;
   }

   return 0;
}

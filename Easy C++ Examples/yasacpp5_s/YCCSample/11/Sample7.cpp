#include <iostream>
using namespace std;

// 声明共用体类型 Year
union Year{
   int ad;
   int gengo; 
};

int main()
{
   Year myyear;

   cout << "请输入公历。\n";
   cin >> myyear.ad;

   cout << "公历是" << myyear.ad << "。\n";
   cout << "年号也是" << myyear.gengo << "。\n";

   cout << "请输入年号。\n";
   cin >> myyear.gengo;

   cout << "年号是" << myyear.gengo << "。\n";
   cout << "公历是" << myyear.ad << "。\n";

   return 0;
}

#include <iostream>
using namespace std;

int main()
{
   int res; 

   cout << "������������\n";

   cin >> res;

   switch(res){
      case 1:
         cout << "������ 1��\n";
         break;
      case 2:
         cout << "������ 2��\n";
         break;
      default:
         cout << "������ 1 �� 2��\n";
         break;
   }

   return 0;
}

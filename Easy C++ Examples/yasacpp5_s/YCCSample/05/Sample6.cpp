#include <iostream>
using namespace std;

int main()
{
   char res; 

   cout << "���������� ?\n";
   cout << "������ Y �� N��\n";

   cin >> res;

   if (res == 'Y' || res == 'y'){
      cout << "�������ԡ�\n";
     }
   else if(res == 'N' || res == 'n'){
      cout << "����Ů�ԡ�\n";
   }
   else{
      cout << "������ Y �� N��\n";
   }

   return 0;
}

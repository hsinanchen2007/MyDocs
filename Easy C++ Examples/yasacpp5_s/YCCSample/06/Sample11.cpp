#include <iostream>
using namespace std;

int main()
{
   int res; 

   cout << "������ɼ���(1~5)\n";

   cin >> res;

   switch(res){
      case 1:
      case 2:
         cout << "��Ŭ��һ��ɡ�\n";
         break;
      case 3:
      case 4:
         cout << "���־�ͷ������Ŭ����\n";
         break;
      case 5:
         cout << "̫�����ˡ�\n";
         break;
      default:
         cout << "������ 1~5 �ĳɼ���\n";
         break;
   }
   
   return 0;
}

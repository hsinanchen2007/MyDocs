#include <iostream>
using namespace std;

int main()
{
   int res;

   cout << "�����ڼ���ѭ���� (1~10)\n";

   cin >> res;

   for(int i=1; i<=10; i++){
      if(i == res)
         continue;
      cout << "��" << i << "��ѭ����\n";
   }

   return 0;
}

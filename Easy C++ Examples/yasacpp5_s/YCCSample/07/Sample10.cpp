#include <iostream>
using namespace std;

//max ����������
int max(int x, int y);


//max �����ĵ���
int main()
{
   int num1, num2, ans;

   cout << "�������һ��������\n";
   cin >> num1;

   cout << "������ڶ���������\n";
   cin >> num2;

   ans = max(num1, num2);

   cout << "���ֵΪ" << ans << "��\n";

   return 0;
}

//max �����Ķ���
int max(int x, int y)
{
   if (x > y)
      return x;
   else
      return y;
}

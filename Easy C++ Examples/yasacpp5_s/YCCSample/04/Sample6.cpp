#include <iostream>
using namespace std;

int main()
{
   int sum = 0;
   int num = 0;

   cout << "������� 1 ��������\n";
   cin >> num;
   sum += num;
   cout << "������� 2 ��������\n";
   cin >> num;
   sum += num;
   cout << "������� 3 ��������\n";
   cin >> num;
   sum += num;

   cout << "3 �������ܺ���" << sum << "���ֵ��\n";

   return 0;
}

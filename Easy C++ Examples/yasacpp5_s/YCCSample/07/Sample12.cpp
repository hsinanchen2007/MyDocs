#include <iostream>
using namespace std;

//max ����������
int max(int x, int y);
double max(double x, double y);

int main()
{
   int a, b;
   double da, db;

   cout << "����������������\n";
   cin >> a >> b;

   cout << "����������С����\n"; 
   cin >> da >> db;

   int ans1 = max(a, b);
   double ans2 = max(da, db);

   cout << "���������ֵΪ" << ans1 << "��\n";
   cout << "С�������ֵΪ" << ans2 << "��\n";

   return 0;
}

//max(int �� ) �����Ķ���
int max(int x, int y)
{
   if (x > y)
      return x;
   else 
      return y;
}

//max ���� (double �� ) �Ķ���
double max(double x, double y)
{
   if (x > y)
      return x;
   else 
      return y;
}

#include <iostream>
using namespace std;

// buy �����Ķ���
int buy(int x, int y)
{
   int z;

   cout << "����" << x << "��Ԫ��" << y << "��Ԫ�ĳ���\n";

   z = x+y;

   return z;
}

// buy �����ĵ���
int main()
{
   int num1, num2, sum;

   cout << "���˼���Ԫ�ĳ���\n";
   cin >> num1;

   cout << "���˼���Ԫ�ĳ���\n";
   cin >> num2;

   sum = buy(num1, num2);

   cout << "��" << sum << "��Ԫ��\n";

   return 0;
}

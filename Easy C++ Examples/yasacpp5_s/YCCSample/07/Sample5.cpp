#include <iostream>
using namespace std;

//buy �����Ķ���
void buy(int x, int y)
{
   cout << "����" << x << "��Ԫ��" << y << "��Ԫ�ĳ���\n";
}

//buy �����ĵ���
int main()
{
   int num1, num2;

   cout << "���˼���Ԫ�ĳ���\n";
   cin >> num1;

   cout << "���˼���Ԫ�ĳ���\n";
   cin >> num2;

   buy(num1, num2);

   return 0;
}

#include <iostream>
using namespace std;

//buy �����Ķ���
void buy(int x)
{
   cout << "����һ��" << x << "��Ԫ�ĳ���\n";
}

//buy �����ĵ���
int main()
{
   int num;

   cout << "��һ������Ԫ�ĳ��� \n";
   cin >> num;

   buy(num);

   cout << "�ڶ�������Ԫ�ĳ���\n";
   cin >> num;

   buy(num);

   return 0;
}

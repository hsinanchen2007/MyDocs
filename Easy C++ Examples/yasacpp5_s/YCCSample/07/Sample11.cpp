#include <iostream>
using namespace std;

//buy ����������
void buy(int x=10);

//buy �����ĵ���
int main()
{
   cout <<  "��һ���� 100 ��Ԫ��\n";
   buy(100);

   cout <<  "�ڶ�����Ĭ�Ͻ����\n";
   buy();

   return 0;
}

//buy �����Ķ���
void buy(int x)
{
   cout << " ���� " << x << "��Ԫ�ĳ���\n";
}
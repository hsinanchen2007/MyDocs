#include <iostream>
using namespace std;

int main()
{
   int a;
   int* pA;

   a = 5;
   pA = &a;

   cout << "���� a ��ֵΪ" << a << "��\n";
   cout << "���� a �ĵ�ַ (&a) Ϊ" << &a << "��\n";
   cout << "ָ�� pA ��ֵΪ" << pA << "��\n";	

   return 0;
}

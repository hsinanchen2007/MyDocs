#include <iostream>
using namespace std;

int main()
{
   int a = 1;
   int b = 0;

   cout << "short int�͵ĳ�����" << sizeof(short int) << "�ֽڡ�\n";
   cout << "int�͵ĳ�����" << sizeof(int) << "�ֽڡ�\n";
   cout << "long int�͵ĳ�����" << sizeof(long int) << "�ֽڡ�\n";
   cout << "float�͵ĳ�����" << sizeof(float) << "�ֽڡ�\n";
   cout << "double�͵ĳ�����" << sizeof(double) << "�ֽڡ�\n";
   cout << "long double�͵ĳ�����" << sizeof(long double) << "�ֽڡ�\n";
   cout << "���� a �ĳ�����" << sizeof(a) << "�ֽڡ�\n";
   cout << "���ʽ a+b �ĳ�����" << sizeof(a+b) << "�ֽڡ�\n";

   return 0;
}

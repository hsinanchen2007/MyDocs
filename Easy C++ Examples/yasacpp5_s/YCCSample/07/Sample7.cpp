#include <iostream>
using namespace std;

// sum �����Ķ���
int sum(int x, int y)
{
   return x+y;
}

int main()
{
   int num1, num2, ans;

   cout << "�������һ��������\n";
   cin >> num1;

   cout << "������ڶ���������\n";
   cin >> num2;

   ans = sum(num1, num2);

   cout << "�ϼƹ�" << ans << "��\n";

   return 0;
}

#include <iostream> 
using namespace std;

//����ģ��
template <class T>
T maxt(T x, T y)
{
   if(x > y)
      return x;
   else
      return y;
}

//
int main()
{
   int a, b;
   double da, db;

   cout << "����������������\n";
   cin >> a >> b;

   cout << "����������С����\n"; 
   cin >> da >> db;

   int ans1 = maxt(a, b);
   double ans2 = maxt(da, db);

   cout << "�����е����ֵΪ" << ans1 << "��\n";
   cout << "С���е����ֵΪ" << ans2 << "��\n";

   return 0;
}

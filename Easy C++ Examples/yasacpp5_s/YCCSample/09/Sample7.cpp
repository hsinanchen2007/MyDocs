#include <iostream>
using namespace std;

//avg 函数声明
double avg(int t[]);

//avg函数调用
int main()
{

   int test[5];

   cout << "请输入 5 个人的考试分数。\n"; 

   for(int i=0; i<5; i++){
      cin >> test[i];
   }

   double ans = avg(test);

   cout << "5 个人的平均分是" << ans << "分。\n";

   return 0;
}

//avg函数定义
double avg(int t[])
{
   double sum = 0;

   for(int i=0; i<5; i++){
      sum += t[i];
   }

   return sum/5;
}

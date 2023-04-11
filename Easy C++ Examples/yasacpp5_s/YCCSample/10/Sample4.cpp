#include<iostream>
using namespace std;

int main()
{
   int num;
   int* pT;

   cout << "要输入几个人的成绩分数？\n";

   cin >> num;

   pT = new int[num];

   cout << "请输入这几个人的分数。B\n";

   for(int i=0; i<num; i++){
      cin >> pT[i];
   }

   for(int j=0; j<num; j++){
      cout <<" 第 " << j+1 << "个人的分数是 " << pT[j] << "。\n";
   }

   delete[] pT;

   return 0;
}

#include <iostream>
using namespace std;

int main()
{
   const int num = 5;
   int test[num];

   cout << " 请输入 " << num <<"个人的分数。\n";
   for(int i=0; i<num; i++){
      cin >> test[i];
   }

   for(int s=0; s<num-1; s++){
      for(int t=s+1; t<num; t++){
         if(test[t] > test[s]){
            int tmp = test[t];
            test[t] = test[s];
            test[s] = tmp;
            
         }
      }
   }

   for(int j=0; j<num; j++){
      cout <<" 第 " << j+1 << "个人的分数是" << test[j] << "。\n";
   }

   return 0;
}

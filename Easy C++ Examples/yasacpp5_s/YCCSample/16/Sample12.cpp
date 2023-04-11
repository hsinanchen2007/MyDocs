#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   ofstream fout("test2.txt");
   if(!fout){
      cout << "打不开文件。\n";
      return 1;
   }

   const int num = 5;
   int test[num];
   cout << " 请输入 " << num <<"名人员的分数。\n";
   for(int i=0; i<num; i++){
      cin >> test[i];
   }

   for(int j=0; j<num; j++){
      fout << "No." << j+1 << setw(5) << test[j] << '\n';
   }

   fout.close();

   return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int num;
   vector<int> vt;

   cout << "一共输入几个整数数据？\n";
   cin >> num;

   for(int i=0; i<num;i++){
      int data;
      cout << "请输入整数。\n";
      cin >> data;
      vt.push_back(data);
   }

   cout << "显示已输入的数据。\n";
   vector<int>::iterator it = vt.begin();
   while(it != vt.end()){
      cout << *it;
      cout << "-";
      it++;
   }
   cout << "\n";
}

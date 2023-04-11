#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   private:
      int num;
      double gas;
   public:
      void show();
      void setNumGas(int n, double g);
};

//Car 类成员函数的定义
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
}
void Car::setNumGas(int n, double g)
{
   if(g > 0 && g < 1000){
      num = n;
      gas = g;
      cout << "将车牌号定为" << num << ", 汽油量定为" << gas << "。\n";
   }
   else{
      cout << g << "不是正确的汽油量。\n";
      cout << "不能更改汽油量。\n";
   }
}

int main()
{
   Car car1;

   //无法进行访问。
   //car1.num = 1234;
   //car1.gas = 20.5;

   car1.setNumGas(1234, 20.5);
   car1.show();

   cout << "试着指定不正确的汽油量（-10.0）…。\n";
   car1.setNumGas(1234, -10.0);
   car1.show();

   return 0;
}

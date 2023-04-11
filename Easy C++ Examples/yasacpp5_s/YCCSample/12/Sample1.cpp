#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   public:
      int num;
      double gas;
      void show();
};

//Car 类成员函数的定义
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
}

int main()
{
   Car car1;

   car1.num = 1234;
   car1.gas = 20.5;

   car1.show();

   return 0;
}

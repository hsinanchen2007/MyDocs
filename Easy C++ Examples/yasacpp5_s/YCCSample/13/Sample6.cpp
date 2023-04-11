#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   private:
      int num;
      double gas;
   public:
      static int sum;
      Car();
      void setCar(int n, double g);
      void show();
      static void showSum();
};

//Car 类成员函数的定义
Car::Car()
{
   num = 0;
   gas = 0.0;
   sum++;
   cout << "创建了汽车。\n";
}
void Car::setCar(int n, double g)
{
   num = n;
   gas = g;
   cout << "车牌号为" << num << "，汽油量为" << gas << "。\n";
}
void Car::showSum()
{
   cout << "一共有" << sum << "辆车。\n";
}
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
}

int Car::sum = 0;

//利用 Car 类
int main()
{
   Car::showSum();

   Car car1;
   car1.setCar(1234, 20.5);

   Car::showSum();

   Car car2;
   car2.setCar(4567, 30.5);

   Car::showSum();

   return 0;
}

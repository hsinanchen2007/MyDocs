#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   private:
      int num;
      double gas;
   public:
      Car();
      void setCar(int n, double g);
      void show();
};

//RacingCar 类的声明
class RacingCar : public Car{
   private:
      int course;
   public:
      RacingCar();
      void setCourse(int c);
};

//Car 类成员函数的定义
Car::Car()
{
   num = 0;
   gas = 0.0;
   cout << "创建了汽车。\n";
}
void Car::setCar(int n, double g)
{
   num = n;
   gas = g;
   cout << "把车牌号定为" << num << "，汽油量定为" << gas << "。\n";
}
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
}

//RacingCar 类成员函数的定义
RacingCar::RacingCar()
{
   course = 0;
   cout << "创建了赛车。\n";
}
void RacingCar::setCourse(int c)
{
   course = c;
   cout << "把路线号设为" << course << "。\n";
}

int main()
{
   RacingCar rccar1;
   rccar1.setCar(1234, 20.5);
   rccar1.setCourse(5);

   return 0;
}

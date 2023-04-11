#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   protected:
      int num;
      double gas;
   public:
      Car();
      void setCar(int n, double g);
      void show();
};

//Racingcar 类的声明
class RacingCar : public Car{
   private:
      int course;
   public:
      RacingCar();
      void setCourse(int c);
      void show();
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
   cout << "车牌号为" << num << "，汽油量为" << gas << "。\n";
}
void Car::show()
{
   cout << "车牌号为" << num << "。\n";
   cout << "汽油量为" << gas << "。\n";
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
   cout << "将赛道编号定为" << course << "。\n";
}
void RacingCar::show()
{
   cout << "赛车的车牌号为" << num << "。\n";
   cout << "汽油量为" << gas << "。\n";
   cout << "赛道编号为" << course << "。\n";
}

int main()
{
   Car* pCars[2];

   Car car1;
   RacingCar rccar1;

   pCars[0] = &car1;
   pCars[0]->setCar(1234, 20.5);

   pCars[1] = &rccar1;
   pCars[1]->setCar(4567, 30.5);

   for(int i=0; i<2 ;i++){
      pCars[i]->show();
   }
   return 0;
}

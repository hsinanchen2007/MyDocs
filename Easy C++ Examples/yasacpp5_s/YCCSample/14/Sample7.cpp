#include <iostream>
#include <typeinfo>
using namespace std;

//Vehicle 类的声明
class Vehicle{
   protected:
      int speed;
   public:
      void setSpeed(int s);
      virtual void show() = 0;
};

//Car 类的声明
class Car : public Vehicle{
   private:
      int num;
      double gas;
   public:
      Car(int n, double g);
      void show();
};

//Plane 类的声明
class Plane : public Vehicle{
   private:
      int flight;
   public:
      Plane(int f);
      void show();
};

//vehicle 类成员函数的定义
void Vehicle::setSpeed(int s)
{
   speed = s;
   cout << "把速度定为" << speed << "。\n";
}

//Car 类成员函数的定义
Car::Car(int n, double g)
{
   num = n;
   gas = g;
   cout << "创建了车牌号为" << num << "，汽油量为" << gas << "的汽车。\n";
}
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
   cout << "速度是" << speed << "。\n";
}

//Plane 类成员函数的定义
Plane::Plane(int f)
{
   flight = f;
   cout << "创建了名为" << flight << "航班的飞机。\n";
}
void Plane::show()
{
   cout << "飞机的班次是" << flight << "。\n";
   cout << "速度是" << speed << "。\n";
}

int main()
{
   Vehicle* pVc[2];
   Car car1(1234,20.5);
   Plane pln1(232);

   pVc[0] = &car1;
   pVc[1] = &pln1;

   for(int i=0; i<2; i++){
       if(typeid(*pVc[i]) == typeid(Car))
         cout<< (i+1) << "第一个是"<< typeid(Car).name() << "。\n";
       else
         cout<< (i+1) << "第一个不是"<< typeid(Car).name() << "。是"
<<  typeid(*pVc[i]).name() << "。\n";
   }
}

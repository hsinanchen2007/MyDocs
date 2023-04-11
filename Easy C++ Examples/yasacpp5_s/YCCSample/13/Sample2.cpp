#include <iostream>
using namespace std;

//Car 类的声明
class Car{
   private:
      int num;
      double gas;
   public:
      Car();
      Car(int n, double g);
      void show();
};

//Car 类成员函数的定义
Car::Car()
{
   num = 0;
   gas = 0.0;
   cout << "创建了汽车。\n";
}
Car::Car(int n, double g)
{
   num = n;
   gas = g;
   cout << "创建了车牌号是" << num << "，汽油量是" << gas <<"的汽车。\n";
}
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
}

int main()
{
   Car car1;
   Car car2(1234, 20.5);

   return 0;
}

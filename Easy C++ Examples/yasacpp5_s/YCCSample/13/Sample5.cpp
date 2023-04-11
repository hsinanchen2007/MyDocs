#include <iostream>
using namespace std;

// Car 类的声明
class Car{
   private:
      int num;
      double gas;
   public:
      Car(int n=0, double g=0);
      void show();
};

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
}

int main()
{
   Car car1;
   Car car2(1234, 20.5);

   return 0;
}

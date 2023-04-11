#include <iostream>
using namespace std;

//Car 类声明
class Car{
   private:
      int num;
      double gas;
   public:
      int getNum(){return num;}
      double getGas(){return gas;}
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
      cout << "没有更改汽油量。\n";
   }
}

//buy 函数的声明
void buy(Car c);

int main()
{
   Car car1;

   car1.setNumGas(1234, 20.5);

   buy(car1);

   return 0;
}

// buy 函数声明
void buy(Car c)
{
    int n = c.getNum();
    double g = c.getGas();
    cout << "买了车牌号为" << n << "，汽油量为" << g << "的车。\n";
}

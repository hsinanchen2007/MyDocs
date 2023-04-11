#include <iostream>
#include <string>
using namespace std;

//Car 类的声明
class Car{
   private:
      int num;
      double gas;
      char* pName;
   public:
      Car(const char* pN ,int n, double g);
      ~Car();
      void show();
};

//Car 类成员函数的定义
Car::Car(const char* pN ,int n, double g)
{
   pName = new char[strlen(pN)+1];
   strcpy_s(pName, strlen(pN)+1, pN);
   num = n;
   gas = g;
   cout << " 创建了 " << pName << "。\n";
}
Car::~Car()
{
   cout  << " 销毁了 " << pName << "。\n";
   delete[] pName;
}
void Car::show()
{
   cout << "车牌号是" << num << "。\n";
   cout << "汽油量是" << gas << "。\n";
   cout << "名称是" << pName << "。\n";
}

//使用 Car 类
int main()
{
   Car car1("mycar", 1234, 25.5);
   car1.show();

   return 0;
}

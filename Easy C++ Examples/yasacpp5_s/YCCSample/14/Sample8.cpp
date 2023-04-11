#include <iostream>
using namespace std;

//Base1 类的声明
class Base1{
   protected:
      int bs1;
   public:
      Base1(int b1=0){bs1 = b1;}
      void showBs1(); 
};

//Base2 类的声明
class Base2{
   protected:
      int bs2;
   public:
      Base2(int b2=0){bs2 = b2;}
      void showBs2(); 
};

//Derived 类的声明
class Derived : public Base1, public Base2{
   protected:
      int dr;
   public:
      Derived(int d=0){dr = d;}
      void showDr();
};

//Base1 类成员函数的定义
void Base1::showBs1()
{
   cout << "bs1是" << bs1 << "。\n";
}

//Base2 类成员函数的定义
void Base2::showBs2()
{
   cout << "bs2是" << bs2 << "。\n";
}

//Derived 类成员函数的定义
void Derived::showDr()
{
   cout << "dr是" << dr << "。\n";
}

int main()
{
   Derived drv;

   drv.showBs1();
   drv.showBs2();
   drv.showDr();

   return 0;
}

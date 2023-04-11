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
      Car(char* pN ,int n, double g);
      ~Car();
      Car(const Car& c);
      Car& operator=(const Car& c);
};

//Car 成员函数的定义
Car::Car(const char* pN ,int n, double g)
{
   pName = new char[strlen(pN)+1];
   strcpy(pName, pN);
   num = n;
   gas = g;
   cout  << " 创建了 " << pName << "。\n";
}
Car::~Car()
{
   cout  << " 销毁了 " << pName << "。\n";
   delete[] pName;
}
Car::Car(const Car& c)
{
   cout  <<" 用 " << c.pName << "初始化。\n";
   pName = new char[strlen(c.pName) + strlen("的副本 1")+1];
   strcpy(pName, c.pName);
   strcat(pName, "副本 1");
   num = c.num;
   gas = c.gas;
}
Car& Car::operator=(const Car& c)
{
   cout <<" 把 " << pName << "代入" << c.pName << "。\n";
   if(this != &c){
      delete [] pName;
      pName = new char[strlen(c.pName)+strlen("的副本2")+1];
      strcpy(pName, c.pName);
      strcat(pName, "副本 2");
      num = c.num;
      gas = c.gas;
   } 
   return *this;
}

int main()
{
   Car mycar("mycar", 1234, 25.5);

   Car car1 = mycar;

   Car car2("car2", 0, 0);
   car2 = mycar;

   return 0;
}

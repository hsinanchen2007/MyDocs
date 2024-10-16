//程序Li3_14.cpp
//统计点类的对象数
#include <iostream>
using namespace std;
//定义点类
class Point  
{
	public:
		static int countP;     //静态数据成员说明
		Point(int=0,int=0);
		~Point();
	private:
		int X,Y; 

};
Point::Point (int x,int y)
{
	X=x;
	Y=y;
    cout<<"Constructor is called!"<<endl;
    countP++;//每创建一个对象，点数加1
}
Point::~Point()
{
	cout<<"Destructor is called!"<<endl;
	countP--;//每析构一个对象，点数减1
	cout<<"现在对象数是："<<countP<<endl;
}
//静态数据成员定义和初始化；
int Point::countP=0;
//主函数：
int main()
{
  Point A(4,5);			//第一个对象
  cout<<"现在对象数是："<<A.countP<<endl;
  Point B(7,8);			//第二个对象
  cout<<"现在对象数是："<<Point::countP<<endl;
  return 0;
}

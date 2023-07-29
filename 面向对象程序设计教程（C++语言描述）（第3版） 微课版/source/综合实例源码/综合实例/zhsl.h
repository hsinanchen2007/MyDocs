#ifndef zhsl_H
#define zhsl_H 
#include<math.h>
#include<iostream.h>
#include <stdlib.h>
class  Fraction
{
	public:
		Fraction(int x=0,int y=1);  //声明带默认值的构造函数
		//重载流运算符
		friend istream& operator>>(istream&,Fraction&) ;
		friend ostream& operator<<(ostream&,Fraction&);// 重载"<<"
		//重载双目运算符
		friend Fraction operator+(Fraction&num1,Fraction&num2);//重载"+"
		friend Fraction operator-(Fraction&num1,Fraction&num2);//重载"-"
		friend Fraction operator*(Fraction&num1,Fraction&num2);//重载"*"
		friend Fraction operator/(Fraction&num1,Fraction&num2);//重载"/"
       	//重载关系运算符
		friend bool operator>(Fraction&num1,Fraction&num2);//重载"=="
		friend bool operator<(Fraction&num1,Fraction&num2);//重载"=="
		friend bool operator==(Fraction&num1,Fraction&num2);//重载"=="
	private:	
		int numerator,denominator;
		void optimization();//保证分数正确且规范
};
class ZeroExcep//分母为0异常类
{
	public:
		ZeroExcep():message("A zero denominator is invalid!"){}
	    const char* what() const{return message;}
    private:
        const char*message;
};
class FractionFormatMistake//分数格式异常类
{
	public:
		FractionFormatMistake():message("Enter another Fraction:"){}
	    const char* what() const{return message;}
    private:
        const char*message;
};
void handlemenu();
int selectmenu();
void add();
void sub();
void mul();
void dive();
void compare();
#endif
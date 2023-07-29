#ifndef zhsl_H
#define zhsl_H 
#include<math.h>
#include<iostream.h>
#include <stdlib.h>
class  Fraction
{
	public:
		Fraction(int x=0,int y=1);  //������Ĭ��ֵ�Ĺ��캯��
		//�����������
		friend istream& operator>>(istream&,Fraction&) ;
		friend ostream& operator<<(ostream&,Fraction&);// ����"<<"
		//����˫Ŀ�����
		friend Fraction operator+(Fraction&num1,Fraction&num2);//����"+"
		friend Fraction operator-(Fraction&num1,Fraction&num2);//����"-"
		friend Fraction operator*(Fraction&num1,Fraction&num2);//����"*"
		friend Fraction operator/(Fraction&num1,Fraction&num2);//����"/"
       	//���ع�ϵ�����
		friend bool operator>(Fraction&num1,Fraction&num2);//����"=="
		friend bool operator<(Fraction&num1,Fraction&num2);//����"=="
		friend bool operator==(Fraction&num1,Fraction&num2);//����"=="
	private:	
		int numerator,denominator;
		void optimization();//��֤������ȷ�ҹ淶
};
class ZeroExcep//��ĸΪ0�쳣��
{
	public:
		ZeroExcep():message("A zero denominator is invalid!"){}
	    const char* what() const{return message;}
    private:
        const char*message;
};
class FractionFormatMistake//������ʽ�쳣��
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
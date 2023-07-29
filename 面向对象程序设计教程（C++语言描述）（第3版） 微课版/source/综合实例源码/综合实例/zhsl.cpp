#include "zhsl.h"
//Fraction类的实现部分
void Fraction::optimization()
{
	int gcd,min,max;
	try
	{
	if(denominator!=0)//分母不为0
	{
		gcd=(abs(numerator)>abs(denominator)?abs(denominator):abs(numerator));
		if(gcd==0) return;
		//以下用辗转相除法求最大公约数
		if(abs(numerator)>abs(denominator))
		{
		max=numerator;
		min=denominator;
		}
		else
		{
			min=numerator;
			max=denominator;
		}
		do
		{
			gcd=max%min;
			max=min;
			min=gcd;
		}while(gcd!=0);
		numerator/=max;
		denominator/=max;
		if(denominator<0)
			{
			numerator=-numerator;
			denominator=-denominator;
			}
		}
		else//分母为0
		throw ZeroExcep();//抛出异常
	}
	catch(ZeroExcep e)//捕获分母为0的异常
		{
			cout<<e.what()<<endl;
			exit(1);
		}
}
Fraction::Fraction(int x,int y)
{
	numerator=x;
    denominator=y;
    optimization();
}
istream& operator>>(istream& istr,Fraction& fr) 
{
	int repeat=1;
	do
	try
    {
	repeat=0;
	istr>>fr.numerator;
	int c=istr.get();
	if(c=='/')
		istr>>fr.denominator;
	else if(c=='-'||c=='+')
	{
		istr.putback(c);
		istr>>fr.denominator;
	}
	else if(c==' '||c=='\n')
		fr.denominator=1;
	else
	{
		repeat=1;
		istr.ignore(80,'\n');
		throw FractionFormatMistake();
	}
	}
	catch(FractionFormatMistake e)
		{
			cout<<e.what()<<endl;
		}
	while (repeat==1);
	fr.optimization();
	return istr;
}
ostream& operator<<(ostream& ostr,Fraction& fr)
{
    if(fr.denominator==1)//整数形式
		ostr<<fr.numerator;
	else if(fr.numerator==0)//数值为零 
		ostr<<fr.numerator;
	else
		ostr<<fr.numerator<<"/"<<fr.denominator;
    return ostr;
}
Fraction operator+(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //分母为两个给出的分数的分母乘积
    //分子为第一个数的分子乘以第二个数的分母加上第一个数的分母乘以第二个数的分子
    temp.denominator=num1.denominator*num2.denominator; 
    temp.numerator=num1.numerator*num2.denominator+num1.denominator*num2.numerator; 
	temp.optimization();  
    return temp;
}
Fraction operator-(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //分母为两个给出的分数的分母乘积
	//分子为第一个数的分子乘以第二个数的分母减去第一个分的分母乘以第二个数的分子
	temp.denominator=num1.denominator*num2.denominator;                            
    temp.numerator=num1.numerator*num2.denominator-num1.denominator*num2.numerator; 
    temp.optimization(); 
	return temp;
}
Fraction operator*(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //分母为两个给出的分数的分母乘积
    //分子为两个给出的分数的分子乘积
    temp.denominator=num1.denominator*num2.denominator; 
    temp.numerator=num1.numerator*num2.numerator;  
    temp.optimization();
    return temp;
}
Fraction operator/(Fraction&num1,Fraction&num2)
{
	Fraction temp;
	try
	{
	if(num2.numerator!=0)
	//分母为第一个分数的分母乘以第二个分数的分子
	//分子为第一个分数的分子乘以第二个分数的分母
	{
		temp.denominator=num1.denominator*num2.numerator; 
		temp.numerator=num1.numerator*num2.denominator; 
		temp.optimization();
		return temp;
    }
	else
		throw ZeroExcep();
	}
	catch(ZeroExcep e)
		{
			cout<<e.what()<<endl;
			exit(1);
		}
}
bool operator>(Fraction&num1,Fraction&num2)
{
	int x=num1.numerator*num2.denominator;
	int y=num1.denominator*num2.numerator;
	return(x>y);
}
bool operator<(Fraction&num1,Fraction&num2)
{
	int x=num1.numerator*num2.denominator;
	int y=num1.denominator*num2.numerator;
	return(x<y);
}
bool operator==(Fraction&num1,Fraction&num2)
{
	int x=num1.numerator*num2.denominator;
	int y=num1.denominator*num2.numerator;
	return(x==y);
}
Fraction fr,fr1,fr2;
void add()
{
	fr=fr1+fr2;
	cout<<"它们的和是 ";
	cout<<fr<<endl;
}
void sub()
{
	fr=fr1-fr2;
	cout<<"它们的差是 ";
	cout<<fr<<endl;
}
void mul()
{
	fr=fr1*fr2;
	cout<<"它们的积是 ";
	cout<<fr<<endl;
}
void dive()
{
	fr=fr1/fr2;
	cout<<"它们的商是 ";
	cout<<fr<<endl;
}
void compare()
{
	if(fr1==fr2)
		cout<<"这2个分数相等 "<<endl;
	else if(fr1<fr2)
		cout<<"第1个分数小于第2个分数 "<<endl;
	else
		cout<<"第1个分数大于第2个分数 "<<endl;
}
//主函数
int main()
{
	cout<<"请输入2个分数(整数或分子/分母)： ";
	cin>>fr1>>fr2;
	handlemenu();
	return 0;
}	
//处理菜单函数
void handlemenu() 
{
	for(; ;)
	{
		switch (selectmenu())
		{
			case 1:
				add();
				break;
			case 2:
                sub();
				break;
			case 3:
				mul();
				break;
			case 4:
				dive();
				break;
			case 5:
				compare();
				break;
            case 6:
				cout<<"\t再见! \n";
				return;
		}
	}
}
//选择菜单函数
int selectmenu()
{
	int choose;
    cout<<"\t*******选择分数运算*******\n";
	cout<<"\tl. 分数加法\n";
    cout<<"\t2. 分数减法\n";
    cout<<"\t3. 分数乘法\n";
    cout<<"\t4. 分数除法\n";
    cout<<"\t5. 分数比较\n";
    cout<<"\t6. 退出程序\n";
	cout<<"\t选择1-6: ";
	for(; ;)
    {
		cin>>choose;
		if(choose<1||choose>6)
			cout<<"\n输入错误,重选1-6:";
		else
			break;
    }
	return choose;
}




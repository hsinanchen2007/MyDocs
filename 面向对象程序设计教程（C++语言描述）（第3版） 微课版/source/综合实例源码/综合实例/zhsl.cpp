#include "zhsl.h"
//Fraction���ʵ�ֲ���
void Fraction::optimization()
{
	int gcd,min,max;
	try
	{
	if(denominator!=0)//��ĸ��Ϊ0
	{
		gcd=(abs(numerator)>abs(denominator)?abs(denominator):abs(numerator));
		if(gcd==0) return;
		//������շת����������Լ��
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
		else//��ĸΪ0
		throw ZeroExcep();//�׳��쳣
	}
	catch(ZeroExcep e)//�����ĸΪ0���쳣
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
    if(fr.denominator==1)//������ʽ
		ostr<<fr.numerator;
	else if(fr.numerator==0)//��ֵΪ�� 
		ostr<<fr.numerator;
	else
		ostr<<fr.numerator<<"/"<<fr.denominator;
    return ostr;
}
Fraction operator+(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
    //����Ϊ��һ�����ķ��ӳ��Եڶ������ķ�ĸ���ϵ�һ�����ķ�ĸ���Եڶ������ķ���
    temp.denominator=num1.denominator*num2.denominator; 
    temp.numerator=num1.numerator*num2.denominator+num1.denominator*num2.numerator; 
	temp.optimization();  
    return temp;
}
Fraction operator-(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
	//����Ϊ��һ�����ķ��ӳ��Եڶ������ķ�ĸ��ȥ��һ���ֵķ�ĸ���Եڶ������ķ���
	temp.denominator=num1.denominator*num2.denominator;                            
    temp.numerator=num1.numerator*num2.denominator-num1.denominator*num2.numerator; 
    temp.optimization(); 
	return temp;
}
Fraction operator*(Fraction&num1,Fraction&num2)
{
	Fraction temp;
    //��ĸΪ���������ķ����ķ�ĸ�˻�
    //����Ϊ���������ķ����ķ��ӳ˻�
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
	//��ĸΪ��һ�������ķ�ĸ���Եڶ��������ķ���
	//����Ϊ��һ�������ķ��ӳ��Եڶ��������ķ�ĸ
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
	cout<<"���ǵĺ��� ";
	cout<<fr<<endl;
}
void sub()
{
	fr=fr1-fr2;
	cout<<"���ǵĲ��� ";
	cout<<fr<<endl;
}
void mul()
{
	fr=fr1*fr2;
	cout<<"���ǵĻ��� ";
	cout<<fr<<endl;
}
void dive()
{
	fr=fr1/fr2;
	cout<<"���ǵ����� ";
	cout<<fr<<endl;
}
void compare()
{
	if(fr1==fr2)
		cout<<"��2��������� "<<endl;
	else if(fr1<fr2)
		cout<<"��1������С�ڵ�2������ "<<endl;
	else
		cout<<"��1���������ڵ�2������ "<<endl;
}
//������
int main()
{
	cout<<"������2������(���������/��ĸ)�� ";
	cin>>fr1>>fr2;
	handlemenu();
	return 0;
}	
//����˵�����
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
				cout<<"\t�ټ�! \n";
				return;
		}
	}
}
//ѡ��˵�����
int selectmenu()
{
	int choose;
    cout<<"\t*******ѡ���������*******\n";
	cout<<"\tl. �����ӷ�\n";
    cout<<"\t2. ��������\n";
    cout<<"\t3. �����˷�\n";
    cout<<"\t4. ��������\n";
    cout<<"\t5. �����Ƚ�\n";
    cout<<"\t6. �˳�����\n";
	cout<<"\tѡ��1-6: ";
	for(; ;)
    {
		cin>>choose;
		if(choose<1||choose>6)
			cout<<"\n�������,��ѡ1-6:";
		else
			break;
    }
	return choose;
}




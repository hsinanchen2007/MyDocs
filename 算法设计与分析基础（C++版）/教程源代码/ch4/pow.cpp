#include<iostream>
using namespace std;
double pow1(double x,int n)
{
	if(n==1)
		return x;
	else if(n%2==0)			//nΪż��
	{
		double f=pow1(x,n/2);
		return f*f;
	}
	else					//nΪ����
	{
		double f=pow1(x,n/2);
		return f*f*x;
	}
}
double pow2(double x,int n)		//�����ݷ��� 
{	double ans=1.0,base=x;
	while (n!=0)
	{	if ((n&1)==1)					//����������λ1
			ans*=base;					//��ans
		base*=base;						//Ȩ����
		n >>= 1;							//n����1λ
	}
	return ans;
}

int main()
{
	double x=2.0;
	for(int n=1;n<=10;n++)
	{ 
		printf("pow1=%g,  \t",pow1(x,n));
		printf("pow2=%g\n",pow2(x,n));
	}
	return 0;
}

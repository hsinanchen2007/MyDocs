#include<iostream>
using namespace std;
double pow1(double x,int n)
{
	if(n==1)
		return x;
	else if(n%2==0)			//n为偶数
	{
		double f=pow1(x,n/2);
		return f*f;
	}
	else					//n为奇数
	{
		double f=pow1(x,n/2);
		return f*f*x;
	}
}
double pow2(double x,int n)		//快速幂方法 
{	double ans=1.0,base=x;
	while (n!=0)
	{	if ((n&1)==1)					//遇到二进制位1
			ans*=base;					//求ans
		base*=base;						//权递增
		n >>= 1;							//n右移1位
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

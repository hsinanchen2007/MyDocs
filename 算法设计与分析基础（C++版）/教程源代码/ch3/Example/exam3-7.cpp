#include<iostream>
using namespace std;
double solve1(double a[],int n,double x)	//解法1
{
	double p=0.0, p1;
	for (int i=n;i>=0;i--)
	{	p1=1.0;
		for (int j=1;j<=i;j++)
			p1*=x;
		p+=p1*a[i];
	}
	return p;
}
double Horner(double a[],int n,double x,int i)  //求多项式值的递归算法
{	if (i==0)
		return a[n];
	else
		return x*Horner(a,n,x,i-1)+a[n-i];
}
double solve2(double a[],int n,double x)  		//解法2
{
	return Horner(a,n,x,n); 
} 

int main()
{
	double a[]={5,-2,3};
	int n=sizeof(a)/sizeof(a[0])-1;
	double x=0.5;
	printf("x=%g的结果:\n",x);
	printf("  P=%g\n",solve1(a,n,x));
	printf("  P=%g\n",solve2(a,n,x));
	x=-0.2;
	printf("x=%g的结果:\n",x);
	printf("  P=%g\n",solve1(a,n,x));
	printf("  P=%g\n",solve2(a,n,x));
	return 0;
}

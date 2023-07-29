#include<iostream>
using namespace std;

int main ()
{	int n;
	long long a[55]={0,1,2};
	for (int i=3;i<=51;i++)
		a[i]=a[i-1]+a[i-2];
	while (~scanf("%d", &n))
		printf ("%lld\n",a[n]);
	return 0;
}

/*解法 
long long Count(int n)						//求铺放方案的总数
{	long long a=1,b=2,c;						//a,b,c分别对应f(n-2),f(n-1),f(n)
	if(n==1)
		return a;
	else if(n==2)
		return b;
	else
	{	for(int i=3;i<=n;i++)
		{	c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}
int main ()
{	int n;
	while (~scanf("%d", &n))
		printf ("%lld\n",Count(n));
	return 0;
}
*/ 


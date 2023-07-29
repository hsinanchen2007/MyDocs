#include<iostream>
#include<vector>
using namespace std;
int Count(int n)
{
	int a=1,b=2,c;
	if(n==1)
		return a;
	else if(n==2)
		return b;
	else
	{
		for(int i=3;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}
int main()
{
	for(int n=1;n<=10;n++)
		printf(" n=%dʱ: %d\n",n,Count(n));
	return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 105
int f1(int n)			//算法1 
{
	if(n==1) return 1;
	else if(n==2) return 2;
	else return f1(n-2)+f1(n-1);
}
int dp[MAXN];
int f21(int n)			//被f2函数调用
{
	if(dp[n]!=0) return dp[n];
	if(n==1) dp[n]=1;
	else if(n==2) dp[n]=2;
	else
	{	
		for (int i=3;i<=n;i++)
			dp[i]=f21(i-2)+f21(i-1);
	}
	return dp[n];
}
int f2(int n)			//算法2
{
	memset(dp,0,sizeof(dp));
	return f21(n);
}
int f3(int n)			//算法3
{
	int dp[MAXN];
	dp[1]=1;
	dp[2]=2;
	for (int i=3;i<=n;i++)
		dp[i]=dp[i-2]+dp[i-1];
	return dp[n];
}
int f4(int n)			//算法4
{
	int dp[3];
	dp[0]=1;
	dp[1]=2;
	for (int i=2;i<n;i++)
		dp[i%3]=dp[(i-1)%3]+dp[(i-2)%3];
	return dp[(n-1)%3];
}

int f5(int n)			//算法5
{
	if(n==1) return 1;
	else if(n==2) return 2;
	else
	{	int a=1,b=2,c;
		for (int i=3;i<=n;i++)
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
	int n=12;
	printf("解法1: %d\n",f1(n)); 
	printf("解法2: %d\n",f2(n));
	printf("解法3: %d\n",f3(n));	
	printf("解法4: %d\n",f4(n));	
	printf("解法5: %d\n",f5(n));	
	return 0;
}

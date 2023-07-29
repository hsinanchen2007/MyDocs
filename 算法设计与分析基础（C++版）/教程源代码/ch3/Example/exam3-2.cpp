#include<iostream>
#include<math.h>
using namespace std;
const int MAXD=20005;						//最大的整数取值
bool isPrime(int x)							//判断x是否是素数
{	for (int i=2;i<=(int)sqrt(x);i++)
		if (x%i==0)							//x能够被i整除
			return false;
	return true;
}
int Count1(int a,int b)			//求a到b的素数个数 
{
	if (a>b) return 0;
	int cnt=0;
	for(int x=a;x<=b;x++)
		if(isPrime(x))
			cnt++;
	return cnt;
}
void solve1(int a[],int b[],int n)
{
	for(int i=0;i<n;i++)
		printf("  %d-%d之间的素数个数=%d\n",a[i],b[i],Count1(a[i],b[i]));
}

int prime[MAXD];								//prime[i]=1表示i是素数 
void Init()										//求出prime 
{	for(int i=0;i<=MAXD;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i<=MAXD;i++)
	{	if(prime[i])
		{							//若i是素数
			for(int j=2*i;j<=MAXD;j+=i)			//则i的倍数都不是素数
				prime[j]=0;
		}
	}
}
void solve2(int a[],int b[],int n)				//求解算法
{
	Init();
	for(int i=2;i<=MAXD;i++)					//prime[i]累计小于等于i的素数个数 
		prime[i]+=prime[i-1];
	for(int i=0;i<n;i++)
		printf("  %d-%d之间的素数个数=%d\n",a[i],b[i],prime[b[i]]-prime[a[i]-1]);
}
int main()
{
	int a[]={2,5,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	int b[]={3,10,100,5000};
	printf("解法1\n"); 
	solve1(a,b,n);
	printf("解法2\n"); 
	solve2(a,b,n);
	return 0;
}

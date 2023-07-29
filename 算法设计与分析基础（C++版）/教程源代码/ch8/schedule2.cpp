#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f				//最大整数∞
#define MAXN 51						//最多的作业数
#define MAXA MAXN*20
#define MAXB MAXN*20
//问题表示
int n=6;								//作业数
int a[]={2,5,7,10,5,2};
int b[]={3,8,4,11,3,4};
int schedule()							//求解算法
{
	int maxA=0;
	for (int i=0;i<n;i++)				//求maxA和maxB 
		maxA+=a[i];
	int dp[MAXA];						//一维动态规划数组 
	memset(dp,0,sizeof(dp));			//初始化为false
	for (int k=1; k<=n; k++) 
	{	for(int A=maxA;A>=0;A--)
		{	if(A<a[k-1])					//这个时间只能在MB上运行
				dp[A]=dp[A]+b[k-1];
			else							//否则取MA或者MB上处理的最少时间
				dp[A]=min(dp[A-a[k-1]],dp[A]+b[k-1]);
		}
	}
	int ans=INF;						//存放最少时间
	for(int A=0;A<=maxA;A++)
		ans=min(ans,max(A,dp[A]));		
	return ans;
} 
int main()
{
	printf("ans=%d\n",schedule());
	return 0;
}


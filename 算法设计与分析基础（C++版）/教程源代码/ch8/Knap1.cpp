#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20					//最多物品数
#define MAXW 100				//最大限制重量

int n=5,W=10;					//5种物品,限制重量不超过10
int w[MAXN]={2,2,6,5,4};
int v[MAXN]={6,3,5,4,6};
/*
int n=2,W=3;					//5种物品,限制重量不超过10
int w[MAXN]={2,1};
int v[MAXN]={3,6};
*/
int Knap1()						//改进算法
{
	int dp[MAXN];				//一维动态规划数组 
	memset(dp,0,sizeof(dp));		//置边界情况
	for (int i=1;i<=n;i++)
	{
		//for (int r=0;r<=W;r++)
		for (int r=W;r>=1;r--)		//r按1到W的逆序 
		{
			if (r<w[i-1])
				dp[r]=dp[r];
			else
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
		}
	}
	return dp[W];
}
/*
//*用于调试 
int Knap1()						//改进算法
{
	int dp[MAXN];				//一维动态规划数组 
	memset(dp,0,sizeof(dp));		//置边界情况
	for (int i=1;i<=n;i++)
	{
		printf("考虑物品i-1=%d\n",i-1); 
		for (int r=0;r<=W;r++)
		//for (int r=W;r>=1;r--)
		{
			printf("  r=%d  ",r);
			if (r<w[i-1])
			{
				dp[r]=dp[r];
				printf("放不下dp[%d]=%d\n",r,dp[r]);		
			}
			else
			{
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
				if(dp[r]==dp[r-w[i-1]]+v[i-1])
					printf("放入 dp[%d]=%d\n",r,dp[r]); 
				else
					printf("不放dp[%d]=%d\n",r,dp[r]);		
			}
		}
	}
	printf("dp[W]=%d\n",dp[W]); 
	return dp[W];
}
*/
int Knap2()						//改进算法
{
	int dp[MAXN];				//一维动态规划数组 
	memset(dp,0,sizeof(dp));		//置边界情况
	for (int i=1;i<=n;i++)
	{	for (int r=W;r>=w[i-1];r--)
			dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
	}
	return dp[W];
}
int main()
{
	//freopen("xyz.txt","w",stdout);
	int maxv=Knap1();
	printf("求解结果(最优方案)\n");		//输出结果
	printf("    总价值=%d\n",maxv);
}

//求解多重背包问题的算法
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20				//最多物品数
#define MAXW 100			//最大限制重量
//问题表示
int n=3,W=7;
int w[MAXN]={3,4,2};
int v[MAXN]={4,5,3};
int s[MAXN]={2,2,1};

//求解结果表示
int multiKnap()							//求解多重背包问题
{
	int dp[MAXN][MAXW];					//二维动态规划数组 
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{
		for (int r=0;r<=W;r++)
		{
			for (int k=0;k<=s[i-1];k++)
			{
				if(k*w[i-1]<=r)
					dp[i][r]=max(dp[i][r],dp[i-1][r-k*w[i-1]]+k*v[i-1]);
			}
		}
	}
	return dp[n][W];
}

int dp[MAXN][MAXW],fk[MAXN][MAXW];			//二维动态规划数组 
int multiKnap1()							//求解多重背包问题(含求最优方案)
{
	memset(dp,0,sizeof(dp));
	memset(fk,0,sizeof(fk));
	for (int i=1;i<=n;i++)
	{
		for (int r=0;r<=W;r++)
		{
			for (int k=0;k<=s[i-1];k++)
			{
				if(k*w[i-1]<=r)
				{
					if (dp[i][r]<dp[i-1][r-k*w[i-1]]+k*v[i-1])
					{
						dp[i][r]=dp[i-1][r-k*w[i-1]]+k*v[i-1];
						fk[i][r]=k;		//物品i-1取k件
					}
				}
			}
		}
	}
	return dp[n][W];
}
void getx()				//推导一个最优方案
{
	int i=n,j=W;
	while (i>=1)
	{
		printf("物品%d共%d件 ",i-1,fk[i][j]);
		j-=fk[i][j]*w[i-1];					//剩余重量
		i--;
	}
	printf("\n");
}
int main()
{
	printf("最优解:\n");
	printf("  总价值=%d\n",multiKnap());
	return 0;
}

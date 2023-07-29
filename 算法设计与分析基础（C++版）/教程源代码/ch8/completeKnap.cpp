//求解完全背包问题的算法
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
int dp[MAXN][MAXW],fk[MAXN][MAXW];			//二维动态规划数组
int completeKnap()													//求解完全背包问题
{	memset(dp,0,sizeof(dp));
	memset(fk,0,sizeof(fk));
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{	for (int k=0;k*w[i-1]<=r;k++)
			{	if (dp[i][r]<dp[i-1][r-k*w[i-1]]+k*v[i-1])
				{	dp[i][r]=dp[i-1][r-k*w[i-1]]+k*v[i-1];
					fk[i][r]=k;											//物品i-1取k件
				}
			}
		}
	}
	return dp[n][W];
}
void getx()																//推导一个最优方案
{	int i=n,r=W;
	while (i>=1)
	{	printf("物品%d共%d件 ",i-1,fk[i][r]);
		r-=fk[i][r]*w[i-1];											//剩余重量
		i--;
	}
	printf("\n");
}

int completeKnap1()											//改进算法
{	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{	if (r<w[i-1])											//物品i-1放不下
				dp[i][r]=dp[i-1][r];
			else														//在不选择和选择物品i-1（多次）中求最大值
				dp[i][r]=max(dp[i-1][r],dp[i][r-w[i-1]]+v[i-1]);
		}
	}
	return dp[n][W];												//返回总价值
}
int completeKnap2()						//改进算法
{
	int dp[MAXN];						//一维动态规划数组 
	memset(dp,0,sizeof(dp));			//置边界情况
	for (int i=1;i<=n;i++)
	{
		for (int r=1;r<=W;r++)		//r按1到W的顺序 
		{
			if (r>=w[i-1])
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
		}
	}
	return dp[W];
}

int main()
{
	printf("最优解:\n");
	printf("  总价值=%d\n",completeKnap());
	printf("  方案: ");getx();
	printf("解法2\n");
	printf("  总价值=%d\n",completeKnap1());
	printf("解法3\n");
	printf("  总价值=%d\n",completeKnap2());
	return 0;
}

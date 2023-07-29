#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20					//最多物品数
#define MAXW 100				//最大限制重量
int n=5,W=10;					//5种物品,限制重量不超过10
int w[MAXN]={2,2,6,5,4};
int v[MAXN]={6,3,5,4,6};
int dp[MAXN][MAXW];				//二维动态规划数组 
int x[MAXN];
int Knap()						//动态规划法求0/1背包问题
{
	for (int i=0;i<=n;i++)			//置边界条件dp[i][0]=0
		dp[i][0]=0;
	for (int r=0;r<=W;r++)			//置边界条件dp[0][r]=0
		dp[0][r]=0;
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{
			if (r<w[i-1])			
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-w[i-1]]+v[i-1]);
				
		}
	}
	return dp[n][W];
}
void getx()						//回推求一个最优方案 
{
	int i=n,r=W;
	while (i>=1)
	{
		printf("i=%d,r=%d\n",i,r);
		if (dp[i][r]!=dp[i-1][r]) 
		{
			x[i-1]=1;				//选取物品i-1
			r=r-w[i-1];
			printf("  选取物品%d,r=r-%d=%d\n",i-1, w[i-1],r);
		}
		else
		{
			x[i-1]=0;				//不选取物品i-1
			printf("  不选取物品%d,r=%d\n",i-1,r);
		}			
		i--;
	}
}
int main()
{
	int maxv=Knap();
	printf("dp:\n");
	for(int i=0;i<=n;i++)
	{
		for(int r=0;r<=W;r++)
			printf("%3d",dp[i][r]);
		printf("\n");
	}
	getx();
	printf("求解结果(最优方案)\n");		//输出结果
	printf("    选取的物品: ");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d ",i);
	printf("\n");
	printf("    总价值=%d\n",maxv);
}

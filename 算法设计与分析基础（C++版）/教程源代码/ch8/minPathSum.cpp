#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 20
//问题表示
//求解结果表示
int dp[MAXN][MAXN];
int minPathSum(vector<vector<int>>& a)		//自顶向下求最小路径和
{
	int n=a.size();
	dp[0][0]=a[0][0];
	for(int i=1;i<n;i++)					//考虑第0列的边界
		dp[i][0]=dp[i-1][0]+a[i][0];
	for (int i=1;i<n;i++)					//考虑对角线的边界
		dp[i][i]=a[i][i]+dp[i-1][i-1];
	for(int i=2;i<n;i++)					//考虑其他有两条达到路径的结点
	{	for(int j=1;j<i;j++)
			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+a[i][j];
	}
	int ans=dp[n-1][0];
	for (int j=1;j<n;j++)						//求出最小ans
		ans=min(ans,dp[n-1][j]);
	return ans;
}
void minPathSum1(vector<vector<int>>& a)		//求最小路径和以及一条最小和路径
{
	int pre[MAXN][MAXN];						//路径数组 
	int n=a.size();
	dp[0][0]=a[0][0];
	for(int i=1;i<n;i++)							//考虑第0列的边界
	{	dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;
	}
	for (int i=1;i<n;i++)							//考虑对角线的边界
	{	dp[i][i]=a[i][i]+dp[i-1][i-1];
		pre[i][i]=i-1;
	}
	for(int i=2;i<n;i++)							//考虑其他有两条达到路径的结点
	{	for(int j=1;j<i;j++)
		{	if(dp[i-1][j-1]<dp[i-1][j])
			{	pre[i][j]=j-1;
				dp[i][j]=a[i][j]+dp[i-1][j-1];
			}
			else
			{	pre[i][j]=j;
				dp[i][j]=a[i][j]+dp[i-1][j];
			}
		}
	}
	int ans=dp[n-1][0];
	int minj=0;
	for (int j=1;j<n;j++)					//求出最小ans和对应的列号minj
	{	if (ans>dp[n-1][j])
		{	ans=dp[n-1][j];
			minj=j;
		}
	}
	printf("最小路径和ans=%d\n",ans);
	int i=n-1;
	vector<int> path;						//存放一条路径
	while (i>=0)							//从(n-1,minj)位置反推求出反向路径
	{	path.push_back(a[i][minj]);
		minj=pre[i][minj];					//最小路径在前一行中的列号
		i--;								//在前一行查找
	}
	printf("最小路径: ");
	for(int i=path.size()-1;i>=0;i--)		//反向输出path 
		printf("  %d",path[i]);
	printf("\n");
}
int minPathSum2(vector<vector<int>>& a)		//自底向上求最小路径和
{	int n=a.size();
	int dp[MAXN][MAXN];
    for(int j=0;j<n;j++)
        dp[n-1][j]=a[n-1][j];						//第n-1行 
	for(int i=n-2;i>=0;i--)										//考虑第0列的边界
		dp[i][0]=dp[i+1][0]+a[i][0];
	for (int i=n-2;i>=0;i--)										//考虑对角线的边界
		dp[i][i]=a[i][i]+dp[i+1][i+1];
	for(int i=n-2;i>=0;i--)										//考虑其他有两条达到的路径
	{	for(int j=0;j<a[i].size();j++)
			dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+a[i][j];
	}
	return dp[0][0];
}

int minPathSum3(vector<vector<int>>& a)		//自底向上的优化算法 
{
	int n=a.size();
    int dp[MAXN];							//一维动态规划数组 
    memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<a[i].size();j++)
			dp[j]=min(dp[j],dp[j+1])+a[i][j];
    }
	return dp[0];
}
int main()
{
	vector<vector<int>> a={{2},{3,4},{6,5,7},{8,3,9,2}};
	//int ans=minPathSum(a);
	//printf("ans=%d\n",ans);				//输出最小路径和
	//minPathSum1(a);
	int ans=minPathSum3(a);
	printf("ans=%d\n",ans);				//输出最小路径和
	return 0;
}

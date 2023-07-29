#include<iostream>
#include<string>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define MAX 201
#define min(x,y) ((x)<(y)?(x):(y))
//问题表示
string a="sfdqxbw";
string b="gfdgw";
//求解结果表示
int editdist()					//求解算法 
{
	int m=a.size();
	int n=b.size();
	int dp[MAX][MAX];			//二维动态规划数组 
	for (int i=1;i<=m;i++) 
		dp[i][0]=i;			//把a的i个字符全部删除转换为b
	for (int j=1; j<=n;j++)
		dp[0][j]=j;			//在a中插入b的全部字符转换为b
	for (int i=1;i<=m;i++)
	{
       	for (int j=1;j<=n;j++)
		{
			if (a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		}
	}
	return dp[m][n];
}
int main()
{
	printf("求解结果\n");
	printf("    最少的字符操作次数: %d\n",editdist());
	return 0;
}

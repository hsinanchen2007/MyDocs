#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 51							//序列中最多的字符个数
string a,b;
int m,n;
int dp[MAXN][MAXN];						//二维动态规划数组
int LCSlength()							//求dp
{
	dp[0][0]=0;
	for (int i=0;i<=m;i++)				//将dp[i][0]置为0,边界条件
		dp[i][0]=0;
	for (int j=0;j<=n;j++)				//将dp[0][j]置为0,边界条件
		dp[0][j]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)			//两重for循环处理a、b的所有字符
		{	if (a[i-1]==b[j-1])			//情况(1)
				dp[i][j]=dp[i-1][j-1]+1;
			else						//情况(2)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

		}
	}
	return dp[m][n];
}
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "求解结果" << endl;
	m=a.length();					//m为a的长度
	n=b.length();					//n为b的长度
	cout << "    最长公共子序列长度: " << LCSlength() << endl;
}

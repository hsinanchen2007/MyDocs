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
	int m=a.length();					//m为a的长度
	int n=b.length();					//n为b的长度
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
string getsubs()					//由dp构造subs
{
	string subs="";					//存放一个LCS
	int k=dp[m][n];					//k为a和b的最长公共子序列长度
	int i=m,j=n;
	while (k>0)						//在subs中放入最长公共子序列(反向)
	{
		printf("i=%d,j=%d  ",i,j);
		if (dp[i][j]==dp[i-1][j])
		{
			i--;
			printf("i--, i=%d\n",i);
		}
		else if (dp[i][j]==dp[i][j-1])
		{
			j--;
			printf("j--, j=%d\n",i);
		}
		else
		{
			subs+=a[i-1];			//subs中添加a[i-1]
			i--; j--; k--;
			printf("添加%c i--,j--, i=%d,j=%d\n",a[i],i,j); 
		}
	}
	reverse(subs.begin(),subs.end());	//逆置subs
	return subs; 
}
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "求解结果" << endl;
	cout << "    最长公共子序列长度: " << LCSlength() << endl;
	m=a.length();					//m为a的长度
	n=b.length();					//n为b的长度
	
	printf("dp:\n");
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%3d",dp[i][j]);
		printf("\n");
	}
	
	string subs=getsubs();
	cout << "    一个最长公共子序列: " << subs << endl;
	return 0;
}


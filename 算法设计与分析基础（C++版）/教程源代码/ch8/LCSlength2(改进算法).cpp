#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 51							//序列中最多的字符个数
string a,b;
int LCSlength1()							//改进算法
{
	int m=a.length();					//m为a的长度
	int n=b.length();					//n为b的长度
	vector<int> dp(n+1,0);				//一维动态规划数组 
	for (int i=1;i<=m;i++)
	{
		int upleft=dp[0];       //阶段i初始化upleft
		for (int j=1;j<=n;j++)
		{
            int tmp=dp[j];      //临时保存dp[j]
        	if (a[i-1]==b[j-1])
            	dp[j]=upleft+1;
        	else
            	dp[j] = max(dp[j-1],dp[j]);
            upleft=tmp;     //修改upleft
        }
    }
	return dp[n];
} 
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "求解结果" << endl;
	cout << "    最长公共子序列长度: " << LCSlength1() << endl;
	return 0;
}


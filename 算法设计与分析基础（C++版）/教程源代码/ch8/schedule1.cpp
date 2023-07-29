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
bool dp[2][MAXA][MAXB];
int schedule()							//求解算法
{
	int maxA=0,maxB=0;
	for (int i=0;i<n;i++)				//求maxA和maxB 
	{	maxA+=a[i];
		maxB+=b[i];
	}
	memset(dp,0,sizeof(dp));			//初始化为false
	for (int A=0;A<=maxA;A++)
	{
		for (int B=0;B<=maxB;B++)
		{
			dp[1][A][B]=false;			//k=1时初始化为false
			dp[0][A][B]=true;			//k=0时一定有解
		}
	}
	int c=0;
	for(int k=1;k<=n;k++)
	{	c=1-c;
		memset(dp[c],false,sizeof(dp[c]));	//初始化dp[c]为false
		for(int A=0;A<=maxA;A++)
		{	for(int B=0;B<=maxB;B++)
			{	if (A-a[k-1]>=0)		//在MA上处理
					dp[c][A][B]=dp[1-c][A-a[k-1]][B];
				if (B-b[k-1]>=0)		//在MB上处理
					dp[c][A][B]=(dp[c][A][B]
						|| dp[1-c][A][B-b[k-1]]);
			}
		}
	}
	int ans=INF;						//存放最少时间
	for(int A=0;A<=maxA;A++)				//求ans
		for(int B=0;B<=maxB;B++)
			if (dp[c][A][B])
				ans=min(ans,max(A,B));
	return ans;
} 
int main()
{
	printf("ans=%d\n",schedule());
	return 0;
}


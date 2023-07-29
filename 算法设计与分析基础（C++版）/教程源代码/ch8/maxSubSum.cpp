//求解最大连续子序列和问题的算法
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 20
int dp[MAXN];
int maxSubSum(vector<int>& a)		//求最大连续子序列和
{
	int n=a.size();
    memset(dp,0,sizeof(dp));
    dp[0]=a[0];
    for(int i=1;i<n;i++)
        dp[i]=max(dp[i-1]+a[i],a[i]);
    int ans=dp[0];
    for(int i=1;i<n;i++)
        ans=max(ans,dp[i]);
    return max(ans,0);
}
vector<int> maxSub(vector<int>& a)	//求一个最大连续子序列 
{
	int n=a.size();
	vector<int> x;
	int maxi=0;
	for(int i=1;i<n;i++)
		if(dp[i]>dp[maxi])
			maxi=i;
	int rsum=dp[maxi];
	int i=maxi;
	while(i>=0 && rsum!=0)
	{
		rsum-=a[i];
		x.push_back(a[i]);
		i--;
	}
	reverse(x.begin(),x.end());
	return x;
}
void solve(vector<int>& a)		//输出结果
{
	int ans=maxSubSum(a);
	printf("求解结果\n");
	printf("    最大连续子序列和: %d\n",ans);
	if(ans==0)
		printf("    所选子序列为空\n");
	else
	{	
		printf("dp:\n");
		for(int i=0;i<a.size();i++)
			printf("dp[%d]=%d\n",i,dp[i]);
		vector<int> x=maxSub(a);
		printf("    所选子序列: ");
		for (int j=0;j<x.size();j++)
			printf("  %d",x[j]);
		printf("\n");
	}
}

int maxSubSum1(vector<int>& nums)		//求最大连续子序列和	
{
	int n=nums.size();
	if(n==1) return nums[0];
	int dp;
	dp=nums[0];
	int ans=dp;
	for(int j=1;j<n;j++)
	{
		dp=max(dp+nums[j],nums[j]);
		ans=max(ans,dp);
    }
	return max(ans,0);
}

void solve1(vector<int>& a)		//输出结果 
{
	int ans=maxSubSum1(a);
	printf("求解结果\n");
	printf("    最大连续子序列和: %d\n",ans);
}
int main()
{
	freopen("xyz.txt","w",stdout);
	//vector<int> a{-2,11,-4,13,-5,-2};
	vector<int> a={-1,3,-2,4};
	solve(a);
	return 0;
}

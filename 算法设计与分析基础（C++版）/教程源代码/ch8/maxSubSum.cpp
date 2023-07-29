//���������������к�������㷨
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 20
int dp[MAXN];
int maxSubSum(vector<int>& a)		//��������������к�
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
vector<int> maxSub(vector<int>& a)	//��һ��������������� 
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
void solve(vector<int>& a)		//������
{
	int ans=maxSubSum(a);
	printf("�����\n");
	printf("    ������������к�: %d\n",ans);
	if(ans==0)
		printf("    ��ѡ������Ϊ��\n");
	else
	{	
		printf("dp:\n");
		for(int i=0;i<a.size();i++)
			printf("dp[%d]=%d\n",i,dp[i]);
		vector<int> x=maxSub(a);
		printf("    ��ѡ������: ");
		for (int j=0;j<x.size();j++)
			printf("  %d",x[j]);
		printf("\n");
	}
}

int maxSubSum1(vector<int>& nums)		//��������������к�	
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

void solve1(vector<int>& a)		//������ 
{
	int ans=maxSubSum1(a);
	printf("�����\n");
	printf("    ������������к�: %d\n",ans);
}
int main()
{
	freopen("xyz.txt","w",stdout);
	//vector<int> a{-2,11,-4,13,-5,-2};
	vector<int> a={-1,3,-2,4};
	solve(a);
	return 0;
}

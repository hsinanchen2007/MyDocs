#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 20
//�����ʾ
//�������ʾ
int dp[MAXN][MAXN];
int minPathSum(vector<vector<int>>& a)		//�Զ���������С·����
{
	int n=a.size();
	dp[0][0]=a[0][0];
	for(int i=1;i<n;i++)					//���ǵ�0�еı߽�
		dp[i][0]=dp[i-1][0]+a[i][0];
	for (int i=1;i<n;i++)					//���ǶԽ��ߵı߽�
		dp[i][i]=a[i][i]+dp[i-1][i-1];
	for(int i=2;i<n;i++)					//���������������ﵽ·���Ľ��
	{	for(int j=1;j<i;j++)
			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+a[i][j];
	}
	int ans=dp[n-1][0];
	for (int j=1;j<n;j++)						//�����Сans
		ans=min(ans,dp[n-1][j]);
	return ans;
}
void minPathSum1(vector<vector<int>>& a)		//����С·�����Լ�һ����С��·��
{
	int pre[MAXN][MAXN];						//·������ 
	int n=a.size();
	dp[0][0]=a[0][0];
	for(int i=1;i<n;i++)							//���ǵ�0�еı߽�
	{	dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;
	}
	for (int i=1;i<n;i++)							//���ǶԽ��ߵı߽�
	{	dp[i][i]=a[i][i]+dp[i-1][i-1];
		pre[i][i]=i-1;
	}
	for(int i=2;i<n;i++)							//���������������ﵽ·���Ľ��
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
	for (int j=1;j<n;j++)					//�����Сans�Ͷ�Ӧ���к�minj
	{	if (ans>dp[n-1][j])
		{	ans=dp[n-1][j];
			minj=j;
		}
	}
	printf("��С·����ans=%d\n",ans);
	int i=n-1;
	vector<int> path;						//���һ��·��
	while (i>=0)							//��(n-1,minj)λ�÷����������·��
	{	path.push_back(a[i][minj]);
		minj=pre[i][minj];					//��С·����ǰһ���е��к�
		i--;								//��ǰһ�в���
	}
	printf("��С·��: ");
	for(int i=path.size()-1;i>=0;i--)		//�������path 
		printf("  %d",path[i]);
	printf("\n");
}
int minPathSum2(vector<vector<int>>& a)		//�Ե���������С·����
{	int n=a.size();
	int dp[MAXN][MAXN];
    for(int j=0;j<n;j++)
        dp[n-1][j]=a[n-1][j];						//��n-1�� 
	for(int i=n-2;i>=0;i--)										//���ǵ�0�еı߽�
		dp[i][0]=dp[i+1][0]+a[i][0];
	for (int i=n-2;i>=0;i--)										//���ǶԽ��ߵı߽�
		dp[i][i]=a[i][i]+dp[i+1][i+1];
	for(int i=n-2;i>=0;i--)										//���������������ﵽ��·��
	{	for(int j=0;j<a[i].size();j++)
			dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+a[i][j];
	}
	return dp[0][0];
}

int minPathSum3(vector<vector<int>>& a)		//�Ե����ϵ��Ż��㷨 
{
	int n=a.size();
    int dp[MAXN];							//һά��̬�滮���� 
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
	//printf("ans=%d\n",ans);				//�����С·����
	//minPathSum1(a);
	int ans=minPathSum3(a);
	printf("ans=%d\n",ans);				//�����С·����
	return 0;
}

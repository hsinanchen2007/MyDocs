#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 20
#define INF 0x3f3f3f3f
int dp[MAXN][MAXN];
void Floyd(vector<vector<int>>& A)
{
	int n=A.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=A[i][j];
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);	//�����·������
	}
}
void dispA(vector<vector<int>>& A)			//���ͼ���ڽӾ���
{	for (int i=0;i<A.size();i++)
	{	for (int j=0;j<A.size();j++)
			if (A[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",A[i][j]);
		printf("\n");
	}
}
void dispdp(int n)			//���dp
{	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
			if (dp[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",dp[i][j]);
		printf("\n");
	}
}

int main()
{
	vector<vector<int>> A={{0,5,INF,7},{INF,0,4,2},{3,3,0,2},{INF,INF,1,0}};
	printf("ͼ���ڽӾ���:\n");
	dispA(A);
	Floyd(A);
	printf("����������·������:\n");
	dispdp(A.size());
	return 0;
}

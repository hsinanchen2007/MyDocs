#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10
#define K 10
#define INF 0x3f3f3f3f
int n=10;
/*
vector<vector<Edge>> E={
	{{1,2},{2,4},{3,3}},
	{{4,7},{5,4}},
	{{4,3},{5,2},{6,4}},
	{{4,6},{5,2},{6,5}},
	{{7,3},{8,4}},
	{{7,6},{8,3}},
	{{7,3},{8,3}},
	{{9,3}},
	{{9,4}},
	{} };
*/
int A[MAXN][MAXN]={{0,2,4,3,INF,INF,INF,INF,INF,INF},{INF,0,INF,INF,7,4,INF,INF,INF,INF},
				   {INF,INF,0,INF,3,2,4,INF,INF,INF},{INF,INF,INF,0,6,2,5,INF,INF,INF},
				   {INF,INF,INF,INF,0,INF,INF,3,4,INF},{INF,INF,INF,INF,INF,0,INF,6,3,INF},
				   {INF,INF,INF,INF,INF,INF,0,3,3,INF},{INF,INF,INF,INF,INF,INF,INF,0,INF,3},
				   {INF,INF,INF,INF,INF,INF,INF,INF,0,4},{INF,INF,INF,INF,INF,INF,INF,INF,INF,0}};
vector<vector<int>> S={{0},{1,2,3},{4,5,6},{7,8},{9}};	//表示5个阶段的状态集合 
int mindist1(int start,int end)						//动态规划问题的逆序解法
{
	//int next[MAXN];					//存放最短路径上当前顶点的后继顶点
	int dp[K][MAXN];
	memset(dp,0x3f,sizeof(dp));
	dp[4][end]=0;						//初始条件
	for(int k=3;k>=0;k--)				//从阶段3到阶段0循环 
	{
		for(int i=0;i<S[k].size();i++)	//遍历阶段k中的每个状态 
		{
			int xk=S[k][i];				//阶段k中的状态xk
			for(int j=0;j<n;j++)
			{
				if(A[xk][j]!=0 && A[xk][j]!=INF)	//存在<xk,j>边
					dp[k][xk]=min(dp[k][xk],A[xk][j]+dp[k+1][j]);
			}
		}
	}
	return dp[0][start];
}
int main()
{
	int start=0;					//起始点 
	int end=9;						//终点 
	printf("最短路径长度=%d\n",mindist1(start,end));
	return 0;
}




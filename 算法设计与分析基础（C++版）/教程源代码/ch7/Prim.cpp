//普里姆算法求最小生成树
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int>> Prim(vector<vector<int>>& A,int v)
{
	vector<vector<int>> T;				//存放最小生成树
	int n=A.size();
	vector<int> lowcost(n,INF);
	vector<int> U(n,0);
	vector<int> closest(n);
	int mincost;
	for (int j=0;j<n;j++)				//给初始化lowcost和closest数组
	{	lowcost[j]=A[v][j];
		closest[j]=v;
	}
	U[v]=1;								//源点加入U 
	for (int i=1;i<n;i++)				//找出(n-1)个顶点
	{	mincost=INF;
		int k=-1; 
		for (int j=0;j<n;j++)			//在(V-U)中找出离U最近的顶点k
		{
			if (U[j]==0 && lowcost[j]<mincost)
			{	mincost=lowcost[j];
				k=j;					//k记录最近顶点的编号
			}
		}
		T.push_back({closest[k],k,mincost});	//产生最小生成树的一条边 
		U[k]=1;									//顶点k加入U 
		for (int j=0;j<n;j++)					//修改数组lowcost和closest
		{
			if (U[j]==0 && A[k][j]<lowcost[j])
			{
				lowcost[j]=A[k][j];
				closest[j]=k;
			}
		}
	}
	return T;
}

void dispA(vector<vector<int>>& A)			//输出图的邻接矩阵
{	for (int i=0;i<A.size();i++)
	{	for (int j=0;j<A.size();j++)
			if (A[i][j]==INF)
				printf("%4s","∞");
			else
				printf("%4d",A[i][j]);
		printf("\n");
	}
}

int main()
{
	vector<vector<int>> A={			//一个带权无向图
		{0,  6,  INF,INF,INF,1,  INF},
		{6,  0,  4,  INF,INF,INF,3},
		{INF,4,  0,  2,  INF,INF,INF},
		{INF,INF,2,  0,  6,  INF,5},
		{INF,INF,INF,6,  0,  8,  7},
		{1,  INF,INF,INF,8,  0,  INF},
		{INF,3,  INF,5,  7,  INF,0}};
	printf("图的邻接矩阵:\n");
	dispA(A);						//输出邻接矩阵A
	printf("Prim算法构造的最小生成树:\n");
	vector<vector<int>> T=Prim(A,0);
	for(int i=0;i<T.size();i++)
		printf("  [%d,%d]:%d",T[i][0],T[i][1],T[i][2]);
	return 0;
}

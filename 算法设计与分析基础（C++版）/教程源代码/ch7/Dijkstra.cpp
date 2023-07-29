//狄克斯特拉算法－求单源最短路径
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> Dijkstra(vector<vector<int>>& A,int v)	//Dijkstra算法
{
	int n=A.size();
	vector<int> dist(n);
	vector<bool> S(n,false);
	for (int i=0;i<n;i++)
		dist[i]=A[v][i];			//距离初始化
	S[v]=true;							//源点v放入S中
	for (int i=0;i<n-1;i++)			//循环n-1次
	{	int u=-1;
		int mindis=INF;					//mindis求最小路径长度
		for (int j=0;j<n;j++)			//选取不在s中且具有最小距离的顶点u
		{ 
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		}
		if(u==-1) break; 
		S[u]=true;							//顶点u加入S中
		for (int j=0;j<n;j++)				//修改不在S中的顶点的距离
		{
			if (!S[j] && A[u][j]!=0 && A[u][j]<INF)
				dist[j]=min(dist[j],dist[u]+A[u][j]);
		}
	}
	return dist;
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
	vector<vector<int>> A={			//一个带权有向图
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	printf("图的邻接矩阵:\n");
	dispA(A);						//输出邻接矩阵A
	int v=0;
	printf("Dijkstra算法求源点%d的最短路径长度:\n",v);
	vector<int> ans=Dijkstra(A,v);
	for(int i=0;i<ans.size();i++)
		printf("  源点%d到%d的最短路径长度=%d\n",v,i,ans[i]);
	return 0;
}

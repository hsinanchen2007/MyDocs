//克鲁斯卡尔算法求最小生成树
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 100
//----并查集基本运算--------
int parent[MAXN];							//并查集存储结构
int rnk[MAXN];								//存储结点的秩(近似于高度)
void Init(int n)								//并查集初始化
{	for (int i=0;i<n;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)								//递归算法：并查集中查找x结点的根结点
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//路径压缩
	return parent[x];
}
void Union(int x,int y)							//并查集中x和y的两个集合的合并
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)											//x和y属于同一棵树的情况
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;									//rx结点作为ry的孩子
	else
	{	if (rnk[rx]==rnk[ry])						//秩相同，合并后rx的秩增1
			rnk[rx]++;
		parent[ry]=rx;									//ry结点作为rx的孩子
	}
}
struct Edge
{
	int u;		//边的起始顶点
	int v;		//边的终止顶点
	int w;		//边的权值
	Edge(int u,int v,int w):u(u),v(v),w(w) { }
	bool operator<(const Edge &b) const
	{
		return w<b.w;			//用于按w递增排序
	}
};

vector<vector<int>> Kruskal(vector<vector<int>>& A)		//Kruskal算法
{
	vector<vector<int>> T;								//T存放最小生成树，每条边为{起点,终点,边权值}
	int n=A.size();
	vector<Edge> E;
	for (int i=0;i<n;i++)			//由A下三角部分产生的边集E
	{
		for (int j=0;j<i;j++)
		{
			if (A[i][j]!=0 && A[i][j]!=INF)
				E.push_back(Edge(i,j,A[i][j]));
		}
	}
	sort(E.begin(),E.end());		//按w递增排序
	Init(n);						//初始化并查集
	int k=0;						//k表示当前构造生成树的边数 
	int j=0;							//E中边的下标,初值为0
	while (k<n-1)					//生成的边数小于n-1时循环
	{	int u1=E[j].u;
		int v1=E[j].v;				//取一条边的头尾顶点编号u1和v2
		int sn1=Find(u1);
		int sn2=Find(v1);			//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)			//添加该边不会构成回路
		{
			T.push_back({u1,v1,E[j].w});	//产生最小生成树的一条边 
			k++;				//生成边数增1
			Union(u1,v1);		//将u1和v1两个顶点合并
		}
		j++;					//扫描下一条边
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
	printf("Kruskal算法构造的最小生成树:\n");
	vector<vector<int>> T=Kruskal(A);
	for(int i=0;i<T.size();i++)
		printf("  [%d,%d]:%d",T[i][0],T[i][1],T[i][2]);
	return 0;
}


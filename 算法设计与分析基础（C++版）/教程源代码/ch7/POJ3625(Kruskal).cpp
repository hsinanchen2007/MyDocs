//8176K 94MS 
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 1000000000.0
#define MAXN 1010
double A[MAXN][MAXN];
double lowcost[MAXN];
bool U[MAXN];
int X[MAXN],Y[MAXN];
int N;
int parent[MAXN];											//并查集存储结构
int rnk[MAXN];												//存储结点的秩(近似于高度)
void Init()												//并查集初始化
{	for (int i=0;i<N;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)													//递归算法：并查集中查找x结点的根结点
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);						//路径压缩
	return parent[x];
}
void Union(int x,int y)										//并查集中x和y的两个集合的合并
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)													//x和y属于同一棵树的情况
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;											//rx结点作为ry的孩子
	else
	{	if (rnk[rx]==rnk[ry])								//秩相同，合并后rx的秩增1
			rnk[rx]++;
		parent[ry]=rx;											//ry结点作为rx的孩子
	}
}
struct Edge														//边类型
{	int u;															//边的起点
	int v;															//边的顶点
	double w;															//边的权值
	Edge(int u,int v,double w):u(u),v(v),w(w) { }
	bool operator<(const Edge &b) const
	{
		return w<b.w;											//用于按w递增排序
	}
};
double Kruskal()							//Kruskal算法
{
	double ans=0.0;
	vector<Edge> E;
	for (int i=0;i<N;i++)										//由A下三角部分产生的边集E
	{	for (int j=i+1;j<N;j++)
			E.push_back(Edge(i,j,A[i][j]));
	}
	sort(E.begin(),E.end());								//按w递增排序
	Init();														//初始化并查集
	int k=0;														//k表示生成树的边数
	int j=0;														//E中边的下标,初值为0
	while (k<N-1)												//生成的边数小于n-1时循环
	{	int u1=E[j].u;
		int v1=E[j].v;											//取一条边的头尾顶点编号u1和v2
		int sn1=Find(u1);
		int sn2=Find(v1);									//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)											//添加该边不会构成回路
		{	ans+=E[j].w;								//产生最小生成树的一条边 
			k++;													//生成边数增1
			Union(u1,v1);										//将u1和v1两棵子树合并
		}
		j++;														//遍历下一条边
	}
	return ans;
}
double distance(int i,int j)			//求顶点i到j的距离 
{
	return sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main()
{
    freopen("abc.txt","r",stdin);
    int M;
    cin >> N >> M;
    for(int i=0;i<N;i++)				//输入N个农场的位置 
    	scanf("%d%d",&X[i],&Y[i]);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
            A[i][j]=A[j][i]=distance(i,j);
    }
    for(int i=0;i<N;i++)				//自己到自己置为INF 
		A[i][i]=INF;
    int i,j;
    while(M--)
    {
    	scanf("%d%d",&i,&j);
        A[i-1][j-1]=A[j-1][i-1]=0;		//已有的道路长度置为0 
    }
    printf("%.2f\n",Kruskal());
    return 0;
}

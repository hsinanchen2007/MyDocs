#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f			//表示∞
#define MAXN 51
//问题表示
int n;							//图顶点个数
//求解结果表示
struct Edge
{
    int vno;					//顶点编号 
	int wt;						//边权 
    Edge(int v,int w):vno(v),wt(w) {}		//构造函数 
};
vector<Edge> E[MAXN];			//图的边数组 
int dist[MAXN];					//dist[i]源点到顶点i的最短路径长度
int pre[MAXN];					//pre[i]表示源点到i的最短路径中顶点i的前驱顶点
struct QNode					//队列结点类型
{
	int i;						//结点的层次
    int vno;					//顶点编号
	int length;					//路径长度
    bool operator<(const QNode& b) const
    {
        return length>b.length;		//length越小越优先出队
    }
};
int cnt=0;
void bfs(int s)						//求解算法
{
	QNode e,e1;
    priority_queue<QNode> qu;
	e.vno=s; e.i=0;						//建立源点结点e
	e.length=0;
	qu.push(e);					//源点结点e进队
    dist[s]=0;
    while(!qu.empty())				//队列不空循环
    {
		e=qu.top(); qu.pop();		//出队列结点e
		int u=e.vno;					//对应顶点为u 
		printf("(%d)出队%d i=%d\n",++cnt,u,e.i); 
        for (int j=0;j<E[e.vno].size();j++)
		{
			int v=E[e.vno][j].vno;		//相邻顶点为v
			printf("  考虑相邻点%d  ", v);
            if(dist[u]+E[u][j].wt<dist[v])		//剪支：u到v有边且路径长度更短
			{
                dist[v]=e.length+E[u][j].wt;
				pre[v]=e.vno;
				e1.vno=v; e1.i=e.i+1;			//建立相邻点的结点e1
				e1.length=dist[v];
                printf("[%d,%d]:%d 修改dist[%d]=%d i=%d\n",u,v,E[u][j].wt,v,dist[v],e1.i); 
				printf(" 扩展%d,e1.length=%d\n",e1.vno,e1.length); 				
				qu.push(e1);				//结点e1进队
            }
            else printf("没有修改\n"); 
		}
    }
}
void addEdge(int i,int j,int w)		//图中添加一条边
{
	E[i].push_back(Edge(j,w));
}
void dispapath(int s,int i)			//输出s到i的最短路径
{
	vector<int> path;
	if (s==i) return;
	if (dist[i]==INF)
		printf("    源点%d到顶点%d没有路径\n",s,i);
	else
	{
		int k=pre[i];
		path.push_back(i);		//添加目标顶点
		while (k!=s)			//添加中间顶点
		{
			path.push_back(k);
			k=pre[k];
		}
		path.push_back(s);		//添加源点
		printf("    源点%d到顶点%d的最短路径长度: %d, 路径: ",s,i,dist[i]);
		for (int j=path.size()-1;j>=0;j--)	//反向输出构成正向路径
			printf("%d ",path[j]);
		printf("\n");
	}
}
void dispallpath(int v)			//输出源点v出发的所有最短路径
{
	for (int i=0;i<n;i++)
		dispapath(v,i);
}
int main()
{
	freopen("xyz.txt","w",stdout);
	memset(dist,INF,sizeof(dist));	//初始化为∞
/* 
	n=6;							//有向图的顶点个数
	addEdge(0,2,10);				//添加8条边
	addEdge(0,4,30);
	addEdge(0,5,100);
	addEdge(1,2,4);
	addEdge(2,3,50);
	addEdge(3,5,10);
	addEdge(4,3,20);
	addEdge(4,5,60);
*/
	n=4;							//有向图的顶点个数
	addEdge(0,1,1);				//添加8条边
	addEdge(1,2,1);
	addEdge(2,3,1);
	addEdge(3,0,1);
	addEdge(0,2,5);

	printf("边数组\n"); 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<E[i].size();j++)
			printf("[%d,%d]:%d   ",i,E[i][j].vno,E[i][j].wt);
		printf("\n");
	}
	int s=0;						//源点
	bfs(s);
	printf("求解结果\n");
	dispallpath(s);
	return 0;
}

//分支限界法求解TSP问题
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
vector<vector<int>> A={{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
int n=4;
int bestd[MAXN];					//保存s经过所有其他顶点的最短路径长度
struct QNode
{
	int i;							//解空间的层次 
	int vno;						//当前顶点
	int used;
	int length;
	bool operator<(const QNode&b) const
	{
		return length<b.length;			//按length越小越优先出队 
	}
};
bool inset(int used,int j)			//判断顶点j是否在used中
{
	return (used&(1<<j))!=0;
} 
void addj(int& used,int j)			//在used中添加顶点j
{
	used=used | (1<<j);
}
void bfs(int s)						//分支限界法算法
{
	QNode e,e1;
	priority_queue<QNode> qu;
	e.i=0;
	e.vno=s;							//起始顶点为s
	e.length=0;
	e.used=0;
	addj(e.used,s);					//表示顶点s已经访问 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.top(); qu.pop(); 			//出队一个结点e
		e1.i=e.i+1;						//扩展下一层 
		for(int j=0;j<n;j++)
		{
			if(inset(e.used,j))
				continue;
			e1.vno=j;							//e1.i层选择顶点j
			e1.used=e.used;
			addj(e1.used,j);					//顶点j已经访问	
			e1.length=e.length+A[e.vno][e1.vno];	//累计路径长度
			if(e1.i==n-1)						//e1为叶子结点
			{
				bestd[e1.vno]=min(bestd[e1.vno],e1.length);			
			}
			if(e1.i<n-1)							//e1为非叶子结点
			{
				if(e1.length<bestd[e1.vno]) 		//剪支
					qu.push(e1);				//e1进队
			}
		}
	}
}
int TSP2(int s)								//求解TSP(起始点为s)
{
	memset(bestd,0x3f,sizeof(bestd));
	bfs(s);
	for(int i=0;i<n;i++)
		printf("bestd[%d]=%d\n",i,bestd[i]);
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		if(i!=s)
		{
			if(bestd[i]+A[i][s]<ans)
				ans=bestd[i]+A[i][s];
		}
	}
	return ans;
}
int main()
{
	int s=2;
	printf("以%d为起点的最短路径长度=%d\n",s,TSP2(s));
	return 0;
}
/*


using namespace std;
//问题表示
int s;										//指定起点
MGraph g;									//图的邻接矩阵
//求解过程表示
int Count=1;								//路径条数累计
vector<int> minpath;						//保存最短路径
int minpathlen=INF;							//保存最短路径长度
struct NodeType								//队列结点类型
{
	int v;									//当前顶点
	int num;								//路径中的结点个数
	vector<int> path;						//当前路径
	int pathlen;							//当前路径长度
	int visited[MAXV];						//顶点访问标记
	bool operator<(const NodeType &s) const
	{
		return pathlen>s.pathlen;			//pathlen越小越优先出队
	}
};
void TSP()		//分枝限界法求起点为s的TSP问题
{
	NodeType e,e1;
	priority_queue<NodeType> qu;	//定义优先队列qu
	e.v=0;							//建立起点s对应的结点e
	e.pathlen=0;
	e.path.push_back(0);
	e.num=1;
	memset(e.visited,0,sizeof(e.visited));
	e.visited[0]=1;
	qu.push(e);						//根结点e进队
	while (!qu.empty())				//队不空循环
	{
		e=qu.top(); qu.pop();		//出队结点e
		if (e.num==g.n)				//到达叶子结点
		{
			if (g.edges[e.v][s]!=0 && g.edges[e.v][s]!=INF)	//e.v到起点s有边
			{
				e.path.push_back(s);				//路径中加入起点s
				e.pathlen+=g.edges[e.v][s];			//计入从e.v到起点s的路径长度
				disp(e.path,e.pathlen);
				if (e.pathlen<minpathlen)			//比较求最短路径
				{
					minpathlen=e.pathlen;
					minpath=e.path;
				}
			}
		}
		else										//非叶子结点
		{
			for (int j=1;j<g.n;j++)					//j从顶点1到n-1循环
			{
				if (g.edges[e.v][j]!=0 && g.edges[e.v][j]!=INF)	//当前顶点到顶点j有边
				{
					if (e.visited[j]==1) 			//跳过路径中重复的顶点j
						continue;
					e1.v=j;						//建立e.v的相邻顶点j对应的结点e1
					e1.num=e.num+1;
					e1.path=e.path;
					e1.path.push_back(j);		//path添加顶点j
					e1.pathlen=e.pathlen+g.edges[e.v][j];
					for (int i=0;i<g.n;i++)		//复制visited
						e1.visited[i]=e.visited[i];
					if (e1.pathlen<minpathlen)	//剪枝
					{
						e1.visited[j]=1;
						qu.push(e1);
					}
				}
			}
		}
	}
}
void main()
{
	int A[][MAXV]={						//一个带权有向图
		{0,8,5,36},	{6,0,8,5}, {8,9,0,5}, {7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//创建图的邻接矩阵g
	s=0;
	printf("求解结果\n");
	TSP();
	printf("  最短路径:    ");
	for (int i=0;i<minpath.size();i++)
		printf("%2d",minpath[i]);
	printf(", 路径长度: %d\n",minpathlen);
}
*/

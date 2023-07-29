//Time Limit Exceeded
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd;									//保存最小时间
struct QNode
{
	int i;							//解空间的层次 
	int v;							//当前顶点	
	int used;
	int cost;
};
bool inset(int used,int j)		//判断顶点j是否在used中
{
	return (used&(1<<j))!=0;
} 
void addj(int& used,int j)			//在used中添加顶点j
{
	used=used^(1<<j);
}
void bfs(int s)					//分支限界法算法
{
	QNode e,e1;
	queue<QNode> qu;
	e.i=0;
	e.v=s;							//起始顶点为s
	e.cost=0;
	e.used=0;
	addj(e.used,s);						//表示e.v顶点已经访问 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.front(); qu.pop(); 		//出队一个结点e
		e1.i=e.i+1;						//扩展下一层 
		for(int j=0;j<=n;j++)
		{
			if(inset(e.used,j))
				continue;
			e1.v=j;
			e1.used=e.used;
			addj(e1.used,j);			//顶点j已经访问	
			e1.cost=e.cost+A[e.v][e1.v];	//累计路径长度
			if(e1.i==n)						//e1为一个叶子结点
			{
				if(e1.cost+A[e1.v][0]<bestd)	//比较求更优解 
					bestd=e1.cost+A[e1.v][0];
			}
			else							//e1为非叶子结点
			{
				if(e1.cost+A[e1.v][0]<bestd) 			//剪支
					qu.push(e1);				//e1进队 
			}
		}
	}
} 
void TSP2(int s)								//求解TSP(起始点为s)
{
	bestd=INF;
	bfs(s);
}
void Floyd()						//计算最短路径距离
{
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];
}
int main()
{
	//freopen("abc.txt","r",stdin);
    while(scanf("%d",&n)==1 &&n)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//计算最短路径距离
        TSP2(0);
        printf("%d\n",bestd);
    }
    return 0;
} 



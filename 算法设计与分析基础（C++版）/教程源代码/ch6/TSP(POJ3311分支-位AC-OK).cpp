//AC:144K 1188MS 
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd[MAXN];					//保存最小时间
struct QNode
{
	int i;							//解空间的层次 
	int vno;						//当前顶点
	int used;
	int cost;
	bool operator<(const QNode&b) const
	{
		return cost<b.cost;			//按cost越小越优先出队 
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
	e.cost=0;
	e.used=0;
	addj(e.used,s);					//表示顶点s已经访问 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.top(); qu.pop(); 		//出队一个结点e
		e1.i=e.i+1;						//扩展下一层 
		for(int j=0;j<=n;j++)
		{
			if(inset(e.used,j))
				continue;
			e1.vno=j;							//e1.i层选择顶点j
			e1.used=e.used;
			addj(e1.used,j);				//顶点j已经访问	
			e1.cost=e.cost+A[e.vno][e1.vno];	//累计路径长度
			if(e1.i==n)						//e1为叶子结点
			{
				bestd[e1.vno]=min(bestd[e1.vno],e1.cost);			
			}
			if(e1.i<n)							//e1为非叶子结点
			{
				if(e1.cost<bestd[e1.vno]) 		//剪支
					qu.push(e1);				//e1进队
			}
		}
	}
}
int TSP2(int s)								//求解TSP(起始点为s)
{
	memset(bestd,0x3f,sizeof(bestd));
	bfs(s);
	int ans=INF;
	for(int i=0;i<=n;i++)
	{
		if(i!=s)
		{
			if(bestd[i]+A[i][s]<ans)
				ans=bestd[i]+A[i][s];
		}
	}
	return ans;
}
void Floyd()								//Floyd算法求任意两个顶点之间的最短路径长度
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
    while(scanf("%d",&n))
    {
    	if(n==0) break;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//计算最短路径距离
        printf("%d\n",TSP2(0));
    }
    return 0;
}

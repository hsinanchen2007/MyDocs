#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f			//表示∞
#define MAXN 51
//问题表示
int n=6;							//图顶点个数
int A[MAXN][MAXN]={					//图的邻接矩阵
{0,2,3,4,INF,INF},
{INF,0,INF,INF,8,INF},
{INF,INF,0,6,INF,INF},
{INF,INF,INF,0,INF,1},
{INF,INF,INF,INF,0,2},
{INF,INF,INF,INF,1,0}};
//求解结果表示
struct QNode					//队列结点类型
{
    int vno;					//顶点编号
	int length;					//路径长度
    bool operator<(const QNode&b) const
    {
        return length>b.length;	//length越小越优先出队
    }
};
int sum=0;
int bfs(int s,int t)					//求s到t的最短路径长度
{
	QNode e,e1;
    priority_queue<QNode> pqu;	//定义优先队列
	e.vno=s;						//建立源点结点e
	e.length=0;
	pqu.push(e);					//源点结点e进队
    while(!pqu.empty())				//队列不空循环
    {
		e=pqu.top(); pqu.pop();		//出队列结点e
		int u=e.vno;
		//printf("出队%d\n",u); 
		//printf("     首次%d:e.length=%d\n",u,e.length);
		if(u==t)
		{
			//printf("   返回%d的长度=%d\n",u,e.length); 
			return e.length;
		}
        for (int v=0;v<n;v++)
		{
            if(A[u][v]!=0 && A[u][v]<INF)	//u到v有边 
            {
				//printf("  考虑相邻点%d  ", v);
				e1.vno=v;					//建立相邻顶点v的结点e1
				e1.length=e.length+A[u][v];
                //printf(" 修改e1.length=%d\n",e1.length); 
				pqu.push(e1);				//结点e1进队
            }
		}
		//sum++;
		//if(sum>12) break;
    }
    return -1;
}
int main()
{
	//for(int s=0;s<n;s++)
	int s=0;
	int t=4;
		//for(int t=0;t<n;t++)
			printf("%d到%d的最短路径长度=%d\n",s,t,bfs(s,t));
	return 0;
}

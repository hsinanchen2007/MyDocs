#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
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
int bfs(int s,int t)				//求s到t的最短路径长度
{
	int dist[MAXN];
	memset(dist,0x3f,sizeof(dist));
    queue<int> qu;						//定义队列
	qu.push(s);							//源点s进队
	dist[s]=0;
    while(!qu.empty())					//队列不空循环
    {
		int u=qu.front(); qu.pop();				//出队顶点u
		if(u==t) return dist[t];
        for (int v=0;v<n;v++)
		{
            if(A[u][v]!=0 && A[u][v]<INF)		//u到v有边 
            {
				if(dist[u]+A[u][v]<dist[v])		//剪支(边松驰)
				{
					dist[v]=dist[u]+A[u][v];
					qu.push(v);					//顶点v进队
				}
            }
		}
    }
    return dist[t];
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

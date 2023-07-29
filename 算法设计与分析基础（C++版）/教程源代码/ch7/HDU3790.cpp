//218MS 9656K 
#include<iostream>
#include<cstring>
using namespace std;
#define MAXV 1010
#define INF 0x3f3f3f3f					//定义∞
int n,m;
int A[MAXV][MAXV],C[MAXV][MAXV];
int s,t;
void Dijkstra(int s)					//Dijkstra算法
{	int dist[MAXV];
    	int cost[MAXV];
    	int S[MAXV];
    	int mindist,mincost,u;
    	for(int i=1;i<=n;i++)					//dist、cost、S初始化,注意顶点编号从1开始
    	{	dist[i]=A[s][i];
        	cost[i]=C[s][i];
        	S[i]=0;
    	}
    	dist[s]=cost[s]=0;
    	S[s]=1;
    	for(int i=0;i<n-1;i++)
    	{	mindist=INF;
      		for(int j=1;j<=n;j++)				//求V-S中的最小距离mindist
        		if (S[j]==0 && mindist>dist[j])
            		mindist=dist[j];
        	if (mindist==INF) break;		//找不到连通的顶点
      		mincost=INF; u=-1;
      		for(int j=1;j<=n;j++)				//求尚未考虑的、距离最小的顶点u
        	{	if (S[j]==0 && mindist==dist[j] && mincost>cost[j])
            	{	mincost=cost[j];		//在dist为最小的顶点中找最小cost的顶点u
                	u=j;
            	}
        	}
        	S[u]=1;						//将顶点u加入S集合
        	for (int j=1;j<=n;j++)				//考虑顶点u,求s到顶点j的最短路径长度和花费
        	{	int d=mindist+A[u][j];	//d记录经过顶点u的路径长度
            	int c=cost[u]+C[u][j];	//c记录经过顶点u的花费
            	if(S[j]==0 && d<dist[j])
            	{	dist[j]=d;
                	cost[j]=c;
            	}
            	else if(S[j]==0 && d==dist[j] && c<cost[j])
                	cost[j]=c;			//有多条长度相同的最短路径
        	}
        	if(S[t]==1)					//已经求出s到t的最短路径
        	{	printf("%d %d\n",dist[t],cost[t]);
            	return;
        	}
    	} 
}
int main()
{	int a,b,d,p;
   	while(scanf("%d%d",&n,&m)!=EOF)
    	{	if(m==0 && n==0)
            	break;
            memset(A,0x3f,sizeof(A));
        	for(int i=0;i<m;i++)
        	{	scanf("%d%d%d%d\n",&a,&b,&d,&p);
            	if(A[a][b]>d)
            	{	A[a][b]=A[b][a]=d; //无向图的边是对称的
                	C[a][b]=C[b][a]=p;
            	}
        	}
        	scanf("%d%d",&s,&t);
        	Dijkstra(s);
    	}
    	return 0;
}


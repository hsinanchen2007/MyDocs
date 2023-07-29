#include<iostream>
#include<cstring>
using namespace std;
#define max(a,b) (a>b?a:b)
#define MAXN 6005											//图中最多的顶点数
int head[MAXN];												//头结点数组
struct Edge															//边结点类型
{	int adjvex;														//邻接点
	int next;															//下一个边结点在edges数组中的下标
} edges[MAXN];												//边结点数组
int n;																	//顶点数
int cnt;																//edges数组元素个数
int dp[MAXN][2];												//动态规划数组
int parent[MAXN];												//parent[i]表示员工i的双亲
int value[MAXN];												//value[i]表示员工i的开心指数
void addedge(int u,int v)										//添加一条有向边<u,v>
{	edges[cnt].adjvex=v;										//该边插入到edges数组末尾
	edges[cnt].next=head[u];									//将edges[cnt]边结点插入到head[u]的表头
	head[u]=cnt;
	cnt++;															//edges数组元素个数增1
}
void init()															//初始化算法
{	cnt=0;															//cnt从0开始
	memset(head,0xff,sizeof(head));						//所有元素初始化为-1
	memset(parent,0xff,sizeof(parent));					//所有的双亲初始化为-1
	memset(dp,0,sizeof(dp));
}
void dfs(int root)
{	if(head[root]==-1)											//员工root没有下级
  {	dp[root][1]=value[root];
     	dp[root][0]=0;
     	return;
	}
  	dp[root][0]=0;
  	dp[root][1]=value[root];
  	int now=head[root];
	while(now!=-1)
 	{	int son=edges[now].adjvex;							//找到root的下级员工son
		dfs(son);
    	dp[root][1]+=dp[son][0];  							//员工root参加的情况
  		dp[root][0]+=max(dp[son][1],dp[son][0]); 		//员工root不参加的情况
    	now=edges[now].next;									//继续找root的下级员工
 	}
}
int main()
{	while(scanf("%d",&n)!=EOF)
 	{	init();
    	for(int i=1;i<=n;i++)									//获取每个员工的开心指数
      	scanf("%d",&value[i]);
    	int a,b;
    	while(scanf("%d%d",&a,&b),a+b)
     {	addedge(b,a);    									//添加边<b,a>
     	parent[a]=b;   										//表示a的双亲为b（即b是a的直接上级）
   	}
		int root=n;
    	while(parent[root]!=-1)								//从员工n向上找到根结点root
			root=parent[root];
		dfs(root);													//DFS求dp数组
    	printf("%d\n",max(dp[root][0],dp[root][1]));	//输出结果
	}
  	return 0;
}


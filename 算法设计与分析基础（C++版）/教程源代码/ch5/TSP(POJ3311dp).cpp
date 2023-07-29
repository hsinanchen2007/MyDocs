//AC:704K 0MS 
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 15
int n;
int dist[MAXN][MAXN];//输入的距离矩阵
int min_dist[MAXN][MAXN];//求出的最短路径距离矩阵
int d[MAXN][1<<MAXN];//用于表示DP状态
bool vis[MAXN][1<<MAXN];
int dp(int i,int s)//记忆话搜索，这个dp函数不会计算dp（0,0）的切记
{
    if(vis[i][s]) return d[i][s];
    vis[i][s]=true;
    d[i][s]=INF;
    for(int j=0;j<=n;j++)if(s&(1<<j)&&j!=i)//集合s中的一个节点号j,且只要S不是全1，j就娶不到0
    {                                      //需要单独初始化d[i][1<<i]的值
        if(d[i][s]>dp(j,s^(1<<i))+min_dist[j][i])//当前距离小于子集生成的距离
        {
            d[i][s]=dp(j,s^(1<<i))+min_dist[j][i];
        }
    }
    return d[i][s];
}
void floyd()//计算最短路径距离
{
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(min_dist[i][j]>min_dist[i][k]+min_dist[k][j])
                    min_dist[i][j] = min_dist[i][k]+min_dist[k][j];
}
int main()
{
    while( scanf("%d",&n)==1&&n )
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            {
                scanf("%d",&min_dist[i][j]);
                //min_dist[i][j]=dist[i][j];
            }
        floyd();//计算最短路径距离
        memset(vis,0,sizeof(vis));
        d[0][0]=0;
        vis[0][0]=true;
        for(int i=1;i<=n;i++)//注意这里一定要单独初始化，否则dp函数计算出来的结果错误
        {
            vis[i][1<<i]=true;
            d[i][1<<i]=min_dist[0][i];
        }
        printf("%d\n",dp(0,(1<<(n+1))-1 ));
    }
    return 0;
} 



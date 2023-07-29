//AC:704K 0MS 
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 15
int n;
int dist[MAXN][MAXN];//����ľ������
int min_dist[MAXN][MAXN];//��������·���������
int d[MAXN][1<<MAXN];//���ڱ�ʾDP״̬
bool vis[MAXN][1<<MAXN];
int dp(int i,int s)//���仰���������dp�����������dp��0,0�����м�
{
    if(vis[i][s]) return d[i][s];
    vis[i][s]=true;
    d[i][s]=INF;
    for(int j=0;j<=n;j++)if(s&(1<<j)&&j!=i)//����s�е�һ���ڵ��j,��ֻҪS����ȫ1��j��Ȣ����0
    {                                      //��Ҫ������ʼ��d[i][1<<i]��ֵ
        if(d[i][s]>dp(j,s^(1<<i))+min_dist[j][i])//��ǰ����С���Ӽ����ɵľ���
        {
            d[i][s]=dp(j,s^(1<<i))+min_dist[j][i];
        }
    }
    return d[i][s];
}
void floyd()//�������·������
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
        floyd();//�������·������
        memset(vis,0,sizeof(vis));
        d[0][0]=0;
        vis[0][0]=true;
        for(int i=1;i<=n;i++)//ע������һ��Ҫ������ʼ��������dp������������Ľ������
        {
            vis[i][1<<i]=true;
            d[i][1<<i]=min_dist[0][i];
        }
        printf("%d\n",dp(0,(1<<(n+1))-1 ));
    }
    return 0;
} 



//218MS 9656K 
#include<iostream>
#include<cstring>
using namespace std;
#define MAXV 1010
#define INF 0x3f3f3f3f					//�����
int n,m;
int A[MAXV][MAXV],C[MAXV][MAXV];
int s,t;
void Dijkstra(int s)					//Dijkstra�㷨
{	int dist[MAXV];
    	int cost[MAXV];
    	int S[MAXV];
    	int mindist,mincost,u;
    	for(int i=1;i<=n;i++)					//dist��cost��S��ʼ��,ע�ⶥ���Ŵ�1��ʼ
    	{	dist[i]=A[s][i];
        	cost[i]=C[s][i];
        	S[i]=0;
    	}
    	dist[s]=cost[s]=0;
    	S[s]=1;
    	for(int i=0;i<n-1;i++)
    	{	mindist=INF;
      		for(int j=1;j<=n;j++)				//��V-S�е���С����mindist
        		if (S[j]==0 && mindist>dist[j])
            		mindist=dist[j];
        	if (mindist==INF) break;		//�Ҳ�����ͨ�Ķ���
      		mincost=INF; u=-1;
      		for(int j=1;j<=n;j++)				//����δ���ǵġ�������С�Ķ���u
        	{	if (S[j]==0 && mindist==dist[j] && mincost>cost[j])
            	{	mincost=cost[j];		//��distΪ��С�Ķ���������Сcost�Ķ���u
                	u=j;
            	}
        	}
        	S[u]=1;						//������u����S����
        	for (int j=1;j<=n;j++)				//���Ƕ���u,��s������j�����·�����Ⱥͻ���
        	{	int d=mindist+A[u][j];	//d��¼��������u��·������
            	int c=cost[u]+C[u][j];	//c��¼��������u�Ļ���
            	if(S[j]==0 && d<dist[j])
            	{	dist[j]=d;
                	cost[j]=c;
            	}
            	else if(S[j]==0 && d==dist[j] && c<cost[j])
                	cost[j]=c;			//�ж���������ͬ�����·��
        	}
        	if(S[t]==1)					//�Ѿ����s��t�����·��
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
            	{	A[a][b]=A[b][a]=d; //����ͼ�ı��ǶԳƵ�
                	C[a][b]=C[b][a]=p;
            	}
        	}
        	scanf("%d%d",&s,&t);
        	Dijkstra(s);
    	}
    	return 0;
}


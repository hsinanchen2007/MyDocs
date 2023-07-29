#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f			//��ʾ��
#define MAXN 51
//�����ʾ
int n=6;							//ͼ�������
int A[MAXN][MAXN]={					//ͼ���ڽӾ���
{0,2,3,4,INF,INF},
{INF,0,INF,INF,8,INF},
{INF,INF,0,6,INF,INF},
{INF,INF,INF,0,INF,1},
{INF,INF,INF,INF,0,2},
{INF,INF,INF,INF,1,0}};
//�������ʾ
int bfs(int s,int t)				//��s��t�����·������
{
	int dist[MAXN];
	memset(dist,0x3f,sizeof(dist));
    queue<int> qu;						//�������
	qu.push(s);							//Դ��s����
	dist[s]=0;
    while(!qu.empty())					//���в���ѭ��
    {
		int u=qu.front(); qu.pop();				//���Ӷ���u
		if(u==t) return dist[t];
        for (int v=0;v<n;v++)
		{
            if(A[u][v]!=0 && A[u][v]<INF)		//u��v�б� 
            {
				if(dist[u]+A[u][v]<dist[v])		//��֧(���ɳ�)
				{
					dist[v]=dist[u]+A[u][v];
					qu.push(v);					//����v����
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
			printf("%d��%d�����·������=%d\n",s,t,bfs(s,t));
	return 0;
}

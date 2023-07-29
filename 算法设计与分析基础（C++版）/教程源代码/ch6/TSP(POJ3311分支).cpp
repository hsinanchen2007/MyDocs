//Memory Limit Exceeded
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd;									//������Сʱ��
struct QNode
{
	int i;							//��ռ�Ĳ�� 
	int v;							//��ǰ����	
	bool used[1<<MAXN];
	int cost;
};
void bfs(int s)					//��֧�޽編�㷨
{
	QNode e,e1;
	queue<QNode> qu;
	e.i=0;
	e.v=s;							//��ʼ����Ϊs
	e.cost=0;
	memset(e.used,0,sizeof(e.used));
	e.used[e.v]=1;					//��ʾe.v�����Ѿ����� 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.front(); qu.pop(); 		//����һ�����e
		e1.i=e.i+1;						//��չ��һ�� 
		for(int j=0;j<=n;j++)
		{
			if(e.used[j]==1)
				continue;
			e1.v=j;						//e1.i��ѡ�񶥵�j
			for(int k=0;k<=n;k++)		//����˫�׽���used 
				e1.used[k]=e.used[k]; 
			e1.used[j]=1;				//����j�Ѿ�����
			e1.cost=e.cost+A[e.v][e1.v];	//�ۼ�·������
			if(e1.i==n)						//e1Ϊһ��Ҷ�ӽ��
			{
				if(e1.cost+A[e1.v][0]<bestd)	//�Ƚ�����Ž� 
					bestd=e1.cost+A[e1.v][0];
			}
			else							//e1Ϊ��Ҷ�ӽ��
			{
				if(e1.cost<bestd) 			//��֧
					qu.push(e1);				//e1���� 
			}
		}
	}
} 
void TSP2(int s)								//���TSP(��ʼ��Ϊs)
{
	bestd=INF;
	bfs(s);
}
void Floyd()						//�������·������
{
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];
}
int main()
{
	freopen("abc.txt","r",stdin);
    while(scanf("%d",&n)==1 &&n)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//�������·������
        TSP2(0);
        printf("%d\n",bestd);
    }
    return 0;
} 



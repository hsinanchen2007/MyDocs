//Memory Limit Exceeded
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd;							//������Сʱ��
struct QNode
{
	int i;							//��ռ�Ĳ�� 
	int v;							//��ǰ����
	bool used[MAXN];
	int cost;
	double lb;						//�޽纯��ֵ(�½�)
	bool operator<(const QNode&b) const
	{
		return lb>b.lb;
	}
};
void bound(QNode&e)					//�޽纯��(�½�)
{
	int mind=INF;
	for(int i=0;i<=n;i++)			//�󲿷ֽ�x�������еĲ���·���ϵ���СԪ�� 
	{
		if(e.used[i]==1)
		{
			for(int j=0;j<=n;j++)
				if(e.used[j]==0 && A[e.v][j]<mind)
					mind=A[i][j];
		}
	}
	int mind1=INF,mind2=INF;
	for(int i=0;i<=n;i++)			//���ڲ��ֽ�x�������е�������СԪ�� 
	{
		if(e.used[i]==0)
		{
			for(int j=0;j<=n;j++)
			{
				if(A[i][j]<mind1)
				{	mind2=mind1;
					mind1=A[i][j];
				}
				else if(A[i][j]<mind2)
					mind2=A[e.v][j];
			}
		}
	}
	e.lb=(2*e.cost+mind+mind1+mind2)/2;
}
void bfs(int s)					//��֧�޽編�㷨
{
	QNode e,e1;
	priority_queue<QNode> qu;
	e.i=0;
	e.v=s;							//��ʼ����Ϊs
	e.cost=0;
	memset(e.used,0,sizeof(e.used));
	e.used[e.v]=1;					//��ʾe.v�����Ѿ�����
	bound(e);
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.top(); qu.pop(); 		//����һ�����e
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
				bound(e1);
				if(e1.lb+A[e1.v][0]<bestd) 			//��֧
				{
					qu.push(e1);				//e1����
				}
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
	//freopen("abc.txt","r",stdin);
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

//AC:144K 1188MS 
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd[MAXN];					//������Сʱ��
struct QNode
{
	int i;							//��ռ�Ĳ�� 
	int vno;						//��ǰ����
	int used;
	int cost;
	bool operator<(const QNode&b) const
	{
		return cost<b.cost;			//��costԽСԽ���ȳ��� 
	}
};
bool inset(int used,int j)			//�ж϶���j�Ƿ���used��
{
	return (used&(1<<j))!=0;
} 
void addj(int& used,int j)			//��used����Ӷ���j
{
	used=used | (1<<j);
}
void bfs(int s)						//��֧�޽編�㷨
{
	QNode e,e1;
	priority_queue<QNode> qu;
	e.i=0;
	e.vno=s;							//��ʼ����Ϊs
	e.cost=0;
	e.used=0;
	addj(e.used,s);					//��ʾ����s�Ѿ����� 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.top(); qu.pop(); 		//����һ�����e
		e1.i=e.i+1;						//��չ��һ�� 
		for(int j=0;j<=n;j++)
		{
			if(inset(e.used,j))
				continue;
			e1.vno=j;							//e1.i��ѡ�񶥵�j
			e1.used=e.used;
			addj(e1.used,j);				//����j�Ѿ�����	
			e1.cost=e.cost+A[e.vno][e1.vno];	//�ۼ�·������
			if(e1.i==n)						//e1ΪҶ�ӽ��
			{
				bestd[e1.vno]=min(bestd[e1.vno],e1.cost);			
			}
			if(e1.i<n)							//e1Ϊ��Ҷ�ӽ��
			{
				if(e1.cost<bestd[e1.vno]) 		//��֧
					qu.push(e1);				//e1����
			}
		}
	}
}
int TSP2(int s)								//���TSP(��ʼ��Ϊs)
{
	memset(bestd,0x3f,sizeof(bestd));
	bfs(s);
	int ans=INF;
	for(int i=0;i<=n;i++)
	{
		if(i!=s)
		{
			if(bestd[i]+A[i][s]<ans)
				ans=bestd[i]+A[i][s];
		}
	}
	return ans;
}
void Floyd()								//Floyd�㷨��������������֮������·������
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
    while(scanf("%d",&n))
    {
    	if(n==0) break;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//�������·������
        printf("%d\n",TSP2(0));
    }
    return 0;
}

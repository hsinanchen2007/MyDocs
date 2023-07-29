#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f			//�����
#define MAXN 21
//�����ʾ
int n=4;
int c[MAXN][MAXN]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
vector<int> bestx;				//���ŷ��䷽��
int bestc=INF;				//��С�ɱ�
struct QNode					//���н������
{
	int i;						//��Ա���
	vector<int> x;					//��ǰ������
	vector<int> used;			//used[i]=true��ʾ����i�Ѿ�����
	int cost;					//�Ѿ�������������Ҫ�ĳɱ�
	int lb;						//�½�
	bool operator<(const QNode& b) const	//����<��ϵ����
	{
		return lb>b.lb;			//lbԽСԽ���ȳ��� 
	}
};
void bound(QNode& e)				//����e���½�ֵ	
{
	int minsum=0;
	for (int i1=e.i;i1<n;i1++)	//��c[e.i..n-1]������СԪ�غ�
	{
		int minc=INF;
		for (int j1=0;j1<n;j1++)
			if (e.used[j1]==false && c[i1][j1]<minc)
				minc=c[i1][j1];
		minsum+=minc;
	}
	e.lb=e.cost+minsum;
}
void disptmp(QNode e)
{
	printf("��i=%d,cost=%d,",e.i,e.cost);
	printf("x=[");
	for(int j=0;j<e.x.size()-1;j++)
		printf("%d,",e.x[j]);
	printf("%d],used=[",e.x[e.x.size()-1]);
	for(int j=0;j<e.used.size()-1;j++)
		printf("%d,",e.used[j]);
	printf("%d],lb=%d��",e.used[e.used.size()-1],e.lb);	
}
void EnQueue(QNode e,priority_queue<QNode>& pqu)		//���e���Ӳ���
{
	if (e.i==n)							//����Ҷ�ӽ��
	{	printf("  һ���� "); disptmp(e); 
		if (e.cost<bestc)						//�Ƚϸ������Ž�
		{	bestc=e.cost;
			bestx=e.x;
			printf("  ���Ž�bestc=%d\n",bestc); 
		}
	}
	else
		pqu.push(e);						//��Ҷ�ӽ�����
}
int sum=0;
void bfs()									//����������
{
	QNode e,e1;
	priority_queue<QNode> pqu;
	e.i=0;									//����㣬ָ����ԱΪ0
	e.cost=0;
	e.x.resize(n);
	e.used.resize(n);
	bound(e);								//�������lb
	pqu.push(e);							//����������
	while (!pqu.empty())
	{
		e=pqu.top(); pqu.pop();				//���ӽ��e������Ϊ��Աe.i�������� 
		printf(" (%d)���ӽ�� ",++sum); disptmp(e); printf("\n");
		for (int j=0;j<n;j++)				//��n������
		{
			if (e.used[j]) continue;		//����j�ѷ���ʱ����
			e1.i=e.i+1;						//�ӽ��Ĳ�μ�1
			e1.x=e.x;
			e1.x[e.i]=j;					//Ϊ��Աe.i��������j
			e1.used=e.used;
			e1.used[j]=true;				//��־����j�Ѿ�����
			e1.cost=e.cost+c[e.i][j];
			bound(e1);						//��e1��lb
			printf("    ѡ������j=%d ���",j); disptmp(e1); 
			if (e1.lb<bestc)				//��֧ 
			{
				printf(" ->����\n"); 
				EnQueue(e1,pqu);
			}
			else
				printf(" ->cut\n");
		}
	}
}
int main()
{
	freopen("xyz.txt","w",stdout);
	bfs();
	printf("���ŷ���:\n");
	for (int k=0;k<n;k++)
		printf("   ��%d����Ա�����%d������\n",k,bestx[k]);
	printf("   �ܳɱ�=%d\n",bestc);
	return 0;
}







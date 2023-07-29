//��֧�޽編���TSP����
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
vector<vector<int>> A={{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
int n=4;
int bestd[MAXN];					//����s��������������������·������
struct QNode
{
	int i;							//��ռ�Ĳ�� 
	int vno;						//��ǰ����
	int used;
	int length;
	bool operator<(const QNode&b) const
	{
		return length<b.length;			//��lengthԽСԽ���ȳ��� 
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
	e.length=0;
	e.used=0;
	addj(e.used,s);					//��ʾ����s�Ѿ����� 
	qu.push(e);
	while(!qu.empty())
	{
		e=qu.top(); qu.pop(); 			//����һ�����e
		e1.i=e.i+1;						//��չ��һ�� 
		for(int j=0;j<n;j++)
		{
			if(inset(e.used,j))
				continue;
			e1.vno=j;							//e1.i��ѡ�񶥵�j
			e1.used=e.used;
			addj(e1.used,j);					//����j�Ѿ�����	
			e1.length=e.length+A[e.vno][e1.vno];	//�ۼ�·������
			if(e1.i==n-1)						//e1ΪҶ�ӽ��
			{
				bestd[e1.vno]=min(bestd[e1.vno],e1.length);			
			}
			if(e1.i<n-1)							//e1Ϊ��Ҷ�ӽ��
			{
				if(e1.length<bestd[e1.vno]) 		//��֧
					qu.push(e1);				//e1����
			}
		}
	}
}
int TSP2(int s)								//���TSP(��ʼ��Ϊs)
{
	memset(bestd,0x3f,sizeof(bestd));
	bfs(s);
	for(int i=0;i<n;i++)
		printf("bestd[%d]=%d\n",i,bestd[i]);
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		if(i!=s)
		{
			if(bestd[i]+A[i][s]<ans)
				ans=bestd[i]+A[i][s];
		}
	}
	return ans;
}
int main()
{
	int s=2;
	printf("��%dΪ�������·������=%d\n",s,TSP2(s));
	return 0;
}
/*


using namespace std;
//�����ʾ
int s;										//ָ�����
MGraph g;									//ͼ���ڽӾ���
//�����̱�ʾ
int Count=1;								//·�������ۼ�
vector<int> minpath;						//�������·��
int minpathlen=INF;							//�������·������
struct NodeType								//���н������
{
	int v;									//��ǰ����
	int num;								//·���еĽ�����
	vector<int> path;						//��ǰ·��
	int pathlen;							//��ǰ·������
	int visited[MAXV];						//������ʱ��
	bool operator<(const NodeType &s) const
	{
		return pathlen>s.pathlen;			//pathlenԽСԽ���ȳ���
	}
};
void TSP()		//��֦�޽編�����Ϊs��TSP����
{
	NodeType e,e1;
	priority_queue<NodeType> qu;	//�������ȶ���qu
	e.v=0;							//�������s��Ӧ�Ľ��e
	e.pathlen=0;
	e.path.push_back(0);
	e.num=1;
	memset(e.visited,0,sizeof(e.visited));
	e.visited[0]=1;
	qu.push(e);						//�����e����
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e=qu.top(); qu.pop();		//���ӽ��e
		if (e.num==g.n)				//����Ҷ�ӽ��
		{
			if (g.edges[e.v][s]!=0 && g.edges[e.v][s]!=INF)	//e.v�����s�б�
			{
				e.path.push_back(s);				//·���м������s
				e.pathlen+=g.edges[e.v][s];			//�����e.v�����s��·������
				disp(e.path,e.pathlen);
				if (e.pathlen<minpathlen)			//�Ƚ������·��
				{
					minpathlen=e.pathlen;
					minpath=e.path;
				}
			}
		}
		else										//��Ҷ�ӽ��
		{
			for (int j=1;j<g.n;j++)					//j�Ӷ���1��n-1ѭ��
			{
				if (g.edges[e.v][j]!=0 && g.edges[e.v][j]!=INF)	//��ǰ���㵽����j�б�
				{
					if (e.visited[j]==1) 			//����·�����ظ��Ķ���j
						continue;
					e1.v=j;						//����e.v�����ڶ���j��Ӧ�Ľ��e1
					e1.num=e.num+1;
					e1.path=e.path;
					e1.path.push_back(j);		//path��Ӷ���j
					e1.pathlen=e.pathlen+g.edges[e.v][j];
					for (int i=0;i<g.n;i++)		//����visited
						e1.visited[i]=e.visited[i];
					if (e1.pathlen<minpathlen)	//��֦
					{
						e1.visited[j]=1;
						qu.push(e1);
					}
				}
			}
		}
	}
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},	{6,0,8,5}, {8,9,0,5}, {7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���g
	s=0;
	printf("�����\n");
	TSP();
	printf("  ���·��:    ");
	for (int i=0;i<minpath.size();i++)
		printf("%2d",minpath[i]);
	printf(", ·������: %d\n",minpathlen);
}
*/

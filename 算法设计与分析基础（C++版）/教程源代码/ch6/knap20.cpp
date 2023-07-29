#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Goods								//��Ʒ�ṹ������ 
{
	int no;									//��Ʒ�ı��
	int w;									//��Ʒ������
	int v;									//��Ʒ�ļ�ֵ
	Goods(int no1,int w1,int v1)			//���캯�� 
	{
		no=no1;
		w=w1;
		v=v1;
	}
};
//int n=4;							//4����Ʒ
//int W=6;							//��������Ϊ6
//vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};

int n=3;							//3����Ʒ
int W=4;							//��������Ϊ4
vector<Goods> g={Goods(0,1,3),Goods(1,2,3),Goods(2,2,4)};


//int W=8; 
//vector<Goods> g={Goods(0,2,6),Goods(1,4,8),Goods(2,3,3),Goods(3,2,2)};
vector<int> bestx;					//������Ž����� 
int bestv=0; 						//�������ֵ,��ʼΪ0 
int bestw;							//���������� 

struct QNode						//�����н������
{
	int i;							//��ǰ���(��Ʒ���) 
	int cw;							//��ǰ������
	int cv;							//��ǰ�ܼ�ֵ
	vector<int> x;					//��ǰ������
};

void EnQueue(QNode e,queue<QNode>& qu)		//���e���Ӳ���
{
	if (e.i==n)							//����Ҷ�ӽ��
	{	printf("  һ����[%d,%d]\n",e.cw,e.cv); 
		if (e.cv>bestv)						//�Ƚϸ������Ž�
		{	bestv=e.cv;
			bestx=e.x;
			bestw=e.cw;
			printf("  ���Ž�bestv=%d\n",bestv); 
		}
	}
	else
	{
		printf("����\n"); 
		qu.push(e);						//��Ҷ�ӽ�����
	} 
}
int sum=0;
void bfs()							//��0/1���������Ž�
{	QNode e,e1,e2;					//����3�����
	queue<QNode> qu;				//����һ������
	e.i=0;
	e.cw=0; e.cv=0;
	e.x.resize(n);
	//bound(e);							//��������Ͻ�
	qu.push(e);							//��������
	//printf("�����[%d,%d,%g]����\n",e.w,e.v,e.ub); 
	while (!qu.empty())					//�Ӳ���ѭ��
	{
		e=qu.front(); qu.pop();			//���ӽ��e
		printf("(%d)���ӽ��[%d,%d,%d]\n",++sum,e.i,e.cw,e.cv); 
		if (e.cw+g[e.i].w<=W)			//����(ѡ����Ʒe.i��֧
		{	e1.cw=e.cw+g[e.i].w;			//ѡ����Ʒe.i
			e1.cv=e.cv+g[e.i].v;
			e1.x=e.x;
			e1.x[e.i]=1;				//ѡ����Ʒe.i
			e1.i=e.i+1;					//���ӽ��Ĳ�μ�1
			printf("   ����[%d,%d,%d],  ",e1.i,e1.cw,e1.cv); 
			EnQueue(e1,qu);
		} 
		else
			printf("   ����[%d,%d,%d],e1.i=%d ->cut\n",e1.i,e1.cw,e1.cv); 
		e2.cw=e.cw;					//��ѡ����Ʒe.i
		e2.cv=e.cv;
		e2.x=e.x;
		e2.x[e.i]=0;					//��ѡ����Ʒi
		e2.i=e.i+1;						//���ӽ��Ĳ�μ�1
			printf("   �ҽ��[%d,%d,%d],e2.i=%d,  ",e2.i,e2.cw,e2.cv); 
			EnQueue(e2,qu);
	}
}
void dispg()					//���g 
{
	for(int i=0;i<g.size();i++)
		printf("%d\t%d\t%d\t%g\n",g[i].no,g[i].w,g[i].v,(double)g[i].v/g[i].w);
}
void disp()							//������Ž�
{
	printf("���װ���\n");
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",g[i].no);
	printf("  ������=%d,�ܼ�ֵ=%d\n",bestw,bestv);
}

void knap()									//��0/1�������� 
{
	bestx.resize(n);
	vector<int> x(n);
	//sort(g.begin(),g.end());
	printf("sort\n"); dispg();
	bfs();							//i��0��ʼ
}
int main()
{
	freopen("xyz.txt","w",stdout); 
	printf("��֧�޽編���0/1��������:\n"); 
	knap();							//���ö���ʽ��֧�޽編��0/1��������
	disp();
}


#include<iostream>
#include<vector>
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
	bool operator<(const Goods&s) const		//���ڰ�v/w�ݼ����� 
	{
		return (double)v/w>(double)s.v/s.w;
	}	
};
int n=4;							//4����Ʒ
int W=6;							//��������Ϊ6
//vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};
vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};
vector<int> bestx;					//������Ž����� 
int bestv=0; 						//�������ֵ,��ʼΪ0 
void disp()							//������Ž�
{
	printf("���װ���\n");
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",g[i].no);
	printf("  ������=%d,�ܼ�ֵ=%d\n",W,bestv);
}

double bound(int cw,int cv,int i)		//�����i������Ͻ纯��ֵ
{
	int rw=W-cw;						//������ʣ������
	double b=cv;						//��ʾ��Ʒ��ֵ���Ͻ�ֵ 
	int j=i;
	while (j<n && g[j].w<=rw)
	{	
		rw-=g[j].w;						//ѡ����Ʒj
		b+=g[j].v;						//�ۼƼ�ֵ
		//printf("ѡ��i=%d,rw=%d,b=%g\n",j,rw,b); 
		j++;
	}
	if (j<n)							//�����Ʒֻ�ܲ���װ�� 
		b+=(double)g[j].v/g[j].w*rw;
	return b;
}
int sum=0;									//�ۼ������Ľ����� 
void dfs(int cw,int cv,vector<int>&x,int i) //�����㷨
{	sum++;
	printf("[%d,%d]\n",cw,cv);
	if (i>=n)								//�ҵ�һ��Ҷ�ӽ��
	{	printf("�ҵ�һ����[%d,%d]\n",cw,cv); 
		if (cw<=W && cv>bestv)				//�ҵ�һ�����������ĸ��Ž�,������
		{	bestv=cv;
			bestx=x;
		}
	}
	else									//û�е���Ҷ�ӽ��Ʒ
	{	if(cw+g[i].w<=W)					//���֧
		{ 
			x[i]=1;								//ѡȡ��Ʒi
			dfs(cw+g[i].w,cv+g[i].v,x,i+1);
		}
		else
			printf("���֧[%d,%d]\n",cw+g[i].w,cv+g[i].v);
		
		double b=bound(cw,cv,i+1);				//���� 
		if(b>bestv)				//�Ҽ�֧
		{
			printf("��չ�Һ��ӽ��b=%g\n",b); 
			x[i]=0;								//��ѡȡ��Ʒi 
			dfs(cw,cv,x,i+1);
		}
		else
			printf("�Ҽ�֧[%d,%d],b=%g\n",cw,cv,b);
	}
}
void dispg()					//���g 
{
	for(int i=0;i<g.size();i++)
		printf("%d\t%d\t%d\t%g\n",g[i].no,g[i].w,g[i].v,(double)g[i].v/g[i].w);
}

void knap()						//��0/1�������� 
{
	bestx.resize(n);
	vector<int> x(n);
	sort(g.begin(),g.end());
	printf("sort\n"); dispg();
	dfs(0,0,x,0);				//i��0��ʼ
	disp();
}

int main()
{
	printf("g:\n"); dispg();
	knap();
	printf("sum=%d\n",sum);
	return 0;
}

//��ⱳ��������㷨
#include<iostream>
#include<vector> 
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 51
//�����ʾ
int n=5;
double W=100;					//����
struct Goods
{
	double w;
	double v;
	bool operator<(const Goods &b) const
	{
		return v/w>b.v/b.w;			//����λ������ֵ������
	}
};
vector<Goods> A={{10,20},{20,30},{30,66},{40,40},{50,60}};
//�������ʾ
double bestv;						//����ֵ
double x[MAXN];
void Knap()							//��ⱳ�����Ⲣ�����ܼ�ֵ
{
	bestv=0;						//bestv��ʼ��Ϊ0
	double rw=W;			//��������װ�����������
	memset(x,0,sizeof(x));		//��ʼ��x����
	int i=0;
	while (i<n && A[i].w<rw)		//��Ʒi�ܹ�ȫ��װ��ʱѭ��
	{	x[i]=1;					//װ����Ʒi
		rw-=A[i].w;			//���ٱ�������װ�����������
		bestv+=A[i].v;				//�ۼ��ܼ�ֵ
		printf("i=%d,bestv=%g\n",i,bestv);
		i++;					//����ѭ��
	}
	if (i<n && rw>0)				//��������������0
	{	x[i]=rw/A[i].w;		//����Ʒi��һ����װ��
		bestv+=x[i]*A[i].v;			//�ۼ��ܼ�ֵ
		printf("i=%d,bestv=%g\n",i,bestv);
	}
}
void dispA()					//���A
{
	printf("\tw\tv\tv/w\n");
	for (int i=0;i<n;i++)
		printf("\t%g\t%g\t%g\n",A[i].w,A[i].v,1.0*A[i].v/A[i].w);
}
int main()
{
	printf("������\n");
	printf("(1)����ǰ\n");dispA();
	sort(A.begin(),A.end());				//����
	printf("(2)�����:\n"); dispA();
	Knap();
	printf("(3)�����\n");		//������
	printf("    x: [");
	for (int j=0;j<n-1;j++)
		printf("%g, ",x[j]);
	printf("%g]\n",x[n]);
	printf("    �ܼ�ֵ=%g\n",bestv);
	return 0;
}

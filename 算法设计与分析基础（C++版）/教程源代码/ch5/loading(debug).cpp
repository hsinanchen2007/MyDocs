#include<iostream>
#include<vector>
using namespace std;
//�����ʾ
int	n=5,t=10;
int w[]={5,2,6,4,3};					//����װ������,�����±�0��Ԫ��
vector<int> bestx;						//������Ž�����
int bestw=0;							//������Ž������������ʼ��Ϊ0 
void dfs(int cw,int rw,vector<int>x,int i) //�ݹ��㷨
{
	if (i>=n)							//�ҵ�һ��Ҷ�ӽ��
	{
		printf("һ����i=%d,[%d,%d]\n",i,cw,rw); 
		if (cw>bestw)					//�ҵ�һ�����������ĸ��Ž�
		{	bestw=cw;					//������Ž�
			bestx=x;		
		}
	}
	else								//��δ�������м�װ��
	{
		rw-=w[i];						//��ʣ�༯װ���������
		if (cw+w[i]<=t)					//���ӽ���֧��ѡ�����������ļ�װ��
		{		
			x[i]=1;						//ѡȡ��װ��i 
			cw+=w[i];					//�ۼƵ�ǰ��ѡ��װ��������� 
			printf("ѡ�����֧i=%d [%d,%d]\n",i+1,cw,rw); 
			dfs(cw,rw,x,i+1);
			cw-=w[i];					//�ָ���ǰ��ѡ��װ���������(����)
		}
		else
			printf("��ѡ�����֧\n"); 
		if (cw+rw>bestw)				//�Һ��ӽ���֧
		{
			x[i]=0;						//��ѡ��װ��i
			printf("ѡ���ҷ�֧i=%d [%d,%d]\n",i+1,cw,rw); 
			dfs(cw,rw,x,i+1);
		}
		else
			printf("��ѡ���ҷ�֧\n"); 
		
		rw+=w[i];						//�ָ�ʣ�༯װ���������(����)
	}
}
void disp()								//������Ž�
{
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  ѡȡ��%d����װ��\n",i);
	printf("������=%d\n",bestw);
}
void loading()		//����װ������
{
	bestx.resize(n);
	vector<int> x(n);
	int rw=0;
	for (int i=0;i<n;i++)
		rw+=w[i];
	dfs(0,rw,x,0);
}
int main()
{
	printf("���ŷ���\n");
	loading();
	disp();
	return 0;
}

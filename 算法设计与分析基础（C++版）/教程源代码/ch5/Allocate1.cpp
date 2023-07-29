#include<iostream>
#include <vector>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f					//�����
#define MAXN 21							//����n 
int n=4;
int c[MAXN][MAXN]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
vector<int> bestx;				//���Ž����� 
int bestc=INF;					//���Ž�ĳɱ�
bool used[MAXN];				//used[j]��ʾ����j�Ƿ��Ѿ�������Ա
int bound(int cost,int i)									//���½��㷨
{	int minsum=0;
	for (int i1=i;i1<n;i1++)						//��c[i..n-1]������СԪ�غ�
	{	int minc=INF;										//��Ϊ��
		for (int j1=0;j1<n;j1++)
			if (used[j1]==false && c[i1][j1]<minc)
				minc=c[i1][j1];
		minsum+=minc;
	}
	return cost+minsum;
}
int sum=0;
void dfs(vector<int>&x,int cost,int i)				//Ϊ��i����Ա��������
{
	sum++;
	if (i>=n)													//����Ҷ�ӽ��
	{	if (cost<bestc)										//�Ƚ������Ž�
		{	bestc=cost;
			bestx=x;
		}
	}
	else														//û�е���Ҷ�ӽ��
	{	for (int j=0;j<n;j++)								//Ϊ��Աi��̽����j
		{	if (used[j]==0)								//������j��û�з���
			{	used[j]=true;
				x[i]=j;										//����j�������Աi
				cost+=c[i][j];
				if(bound(cost,i+1)<bestc)					//��֧
					dfs(x,cost,i+1);						//����Ϊ��Աi+1��������
				used[j]=false;								//����
				x[i]=0;
				cost-=c[i][j];
			}
		}
	}
}
void alloction()
{
	memset(used,false,sizeof(used));
	vector<int> x(n,0);						//��ʱ��
	int cost=0;							//��ʱ��ĳɱ�
	dfs(x,cost,0);							//����Ա0��ʼ
}
int main()
{
	memset(used,0,sizeof(used));	//used��ʼ��Ϊfalse
	alloction();	
	printf("sum=%d\n",sum);						
	printf("���ŷ���:\n");
	for (int k=0;k<n;k++)
		printf("   ��%d���˰�������%d\n",k,bestx[k]);
	printf("   �ܳɱ�=%d\n",bestc);
	return 0;
}







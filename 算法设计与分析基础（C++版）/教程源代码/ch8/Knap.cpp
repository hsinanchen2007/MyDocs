#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20					//�����Ʒ��
#define MAXW 100				//�����������
int n=5,W=10;					//5����Ʒ,��������������10
int w[MAXN]={2,2,6,5,4};
int v[MAXN]={6,3,5,4,6};
int dp[MAXN][MAXW];				//��ά��̬�滮���� 
int x[MAXN];
int Knap()						//��̬�滮����0/1��������
{
	for (int i=0;i<=n;i++)			//�ñ߽�����dp[i][0]=0
		dp[i][0]=0;
	for (int r=0;r<=W;r++)			//�ñ߽�����dp[0][r]=0
		dp[0][r]=0;
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{
			if (r<w[i-1])			
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-w[i-1]]+v[i-1]);
				
		}
	}
	return dp[n][W];
}
void getx()						//������һ�����ŷ��� 
{
	int i=n,r=W;
	while (i>=1)
	{
		printf("i=%d,r=%d\n",i,r);
		if (dp[i][r]!=dp[i-1][r]) 
		{
			x[i-1]=1;				//ѡȡ��Ʒi-1
			r=r-w[i-1];
			printf("  ѡȡ��Ʒ%d,r=r-%d=%d\n",i-1, w[i-1],r);
		}
		else
		{
			x[i-1]=0;				//��ѡȡ��Ʒi-1
			printf("  ��ѡȡ��Ʒ%d,r=%d\n",i-1,r);
		}			
		i--;
	}
}
int main()
{
	int maxv=Knap();
	printf("dp:\n");
	for(int i=0;i<=n;i++)
	{
		for(int r=0;r<=W;r++)
			printf("%3d",dp[i][r]);
		printf("\n");
	}
	getx();
	printf("�����(���ŷ���)\n");		//������
	printf("    ѡȡ����Ʒ: ");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d ",i);
	printf("\n");
	printf("    �ܼ�ֵ=%d\n",maxv);
}

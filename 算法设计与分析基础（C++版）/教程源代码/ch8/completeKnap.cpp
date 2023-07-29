//�����ȫ����������㷨
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20				//�����Ʒ��
#define MAXW 100			//�����������
//�����ʾ
int n=3,W=7;
int w[MAXN]={3,4,2};
int v[MAXN]={4,5,3};
int dp[MAXN][MAXW],fk[MAXN][MAXW];			//��ά��̬�滮����
int completeKnap()													//�����ȫ��������
{	memset(dp,0,sizeof(dp));
	memset(fk,0,sizeof(fk));
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{	for (int k=0;k*w[i-1]<=r;k++)
			{	if (dp[i][r]<dp[i-1][r-k*w[i-1]]+k*v[i-1])
				{	dp[i][r]=dp[i-1][r-k*w[i-1]]+k*v[i-1];
					fk[i][r]=k;											//��Ʒi-1ȡk��
				}
			}
		}
	}
	return dp[n][W];
}
void getx()																//�Ƶ�һ�����ŷ���
{	int i=n,r=W;
	while (i>=1)
	{	printf("��Ʒ%d��%d�� ",i-1,fk[i][r]);
		r-=fk[i][r]*w[i-1];											//ʣ������
		i--;
	}
	printf("\n");
}

int completeKnap1()											//�Ľ��㷨
{	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{	for (int r=0;r<=W;r++)
		{	if (r<w[i-1])											//��Ʒi-1�Ų���
				dp[i][r]=dp[i-1][r];
			else														//�ڲ�ѡ���ѡ����Ʒi-1����Σ��������ֵ
				dp[i][r]=max(dp[i-1][r],dp[i][r-w[i-1]]+v[i-1]);
		}
	}
	return dp[n][W];												//�����ܼ�ֵ
}
int completeKnap2()						//�Ľ��㷨
{
	int dp[MAXN];						//һά��̬�滮���� 
	memset(dp,0,sizeof(dp));			//�ñ߽����
	for (int i=1;i<=n;i++)
	{
		for (int r=1;r<=W;r++)		//r��1��W��˳�� 
		{
			if (r>=w[i-1])
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
		}
	}
	return dp[W];
}

int main()
{
	printf("���Ž�:\n");
	printf("  �ܼ�ֵ=%d\n",completeKnap());
	printf("  ����: ");getx();
	printf("�ⷨ2\n");
	printf("  �ܼ�ֵ=%d\n",completeKnap1());
	printf("�ⷨ3\n");
	printf("  �ܼ�ֵ=%d\n",completeKnap2());
	return 0;
}

//�����ر���������㷨
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
int s[MAXN]={2,2,1};

//�������ʾ
int multiKnap()							//�����ر�������
{
	int dp[MAXN][MAXW];					//��ά��̬�滮���� 
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{
		for (int r=0;r<=W;r++)
		{
			for (int k=0;k<=s[i-1];k++)
			{
				if(k*w[i-1]<=r)
					dp[i][r]=max(dp[i][r],dp[i-1][r-k*w[i-1]]+k*v[i-1]);
			}
		}
	}
	return dp[n][W];
}

int dp[MAXN][MAXW],fk[MAXN][MAXW];			//��ά��̬�滮���� 
int multiKnap1()							//�����ر�������(�������ŷ���)
{
	memset(dp,0,sizeof(dp));
	memset(fk,0,sizeof(fk));
	for (int i=1;i<=n;i++)
	{
		for (int r=0;r<=W;r++)
		{
			for (int k=0;k<=s[i-1];k++)
			{
				if(k*w[i-1]<=r)
				{
					if (dp[i][r]<dp[i-1][r-k*w[i-1]]+k*v[i-1])
					{
						dp[i][r]=dp[i-1][r-k*w[i-1]]+k*v[i-1];
						fk[i][r]=k;		//��Ʒi-1ȡk��
					}
				}
			}
		}
	}
	return dp[n][W];
}
void getx()				//�Ƶ�һ�����ŷ���
{
	int i=n,j=W;
	while (i>=1)
	{
		printf("��Ʒ%d��%d�� ",i-1,fk[i][j]);
		j-=fk[i][j]*w[i-1];					//ʣ������
		i--;
	}
	printf("\n");
}
int main()
{
	printf("���Ž�:\n");
	printf("  �ܼ�ֵ=%d\n",multiKnap());
	return 0;
}

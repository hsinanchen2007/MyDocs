#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 20					//�����Ʒ��
#define MAXW 100				//�����������

int n=5,W=10;					//5����Ʒ,��������������10
int w[MAXN]={2,2,6,5,4};
int v[MAXN]={6,3,5,4,6};
/*
int n=2,W=3;					//5����Ʒ,��������������10
int w[MAXN]={2,1};
int v[MAXN]={3,6};
*/
int Knap1()						//�Ľ��㷨
{
	int dp[MAXN];				//һά��̬�滮���� 
	memset(dp,0,sizeof(dp));		//�ñ߽����
	for (int i=1;i<=n;i++)
	{
		//for (int r=0;r<=W;r++)
		for (int r=W;r>=1;r--)		//r��1��W������ 
		{
			if (r<w[i-1])
				dp[r]=dp[r];
			else
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
		}
	}
	return dp[W];
}
/*
//*���ڵ��� 
int Knap1()						//�Ľ��㷨
{
	int dp[MAXN];				//һά��̬�滮���� 
	memset(dp,0,sizeof(dp));		//�ñ߽����
	for (int i=1;i<=n;i++)
	{
		printf("������Ʒi-1=%d\n",i-1); 
		for (int r=0;r<=W;r++)
		//for (int r=W;r>=1;r--)
		{
			printf("  r=%d  ",r);
			if (r<w[i-1])
			{
				dp[r]=dp[r];
				printf("�Ų���dp[%d]=%d\n",r,dp[r]);		
			}
			else
			{
				dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
				if(dp[r]==dp[r-w[i-1]]+v[i-1])
					printf("���� dp[%d]=%d\n",r,dp[r]); 
				else
					printf("����dp[%d]=%d\n",r,dp[r]);		
			}
		}
	}
	printf("dp[W]=%d\n",dp[W]); 
	return dp[W];
}
*/
int Knap2()						//�Ľ��㷨
{
	int dp[MAXN];				//һά��̬�滮���� 
	memset(dp,0,sizeof(dp));		//�ñ߽����
	for (int i=1;i<=n;i++)
	{	for (int r=W;r>=w[i-1];r--)
			dp[r]=max(dp[r],dp[r-w[i-1]]+v[i-1]);
	}
	return dp[W];
}
int main()
{
	//freopen("xyz.txt","w",stdout);
	int maxv=Knap1();
	printf("�����(���ŷ���)\n");		//������
	printf("    �ܼ�ֵ=%d\n",maxv);
}

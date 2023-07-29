#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f				//���������
#define MAXN 21						//������ҵ��
#define MAXA MAXN*20
#define MAXB MAXN*20
//�����ʾ
int n=6;								//��ҵ��
int a[]={2,5,7,10,5,2};
int b[]={3,8,4,11,3,4};
bool dp[MAXN][MAXA][MAXB];
int schedule()							//����㷨
{
	int maxA=0,maxB=0;
	for (int i=0;i<n;i++)				//��maxA��maxB 
	{	maxA+=a[i];
		maxB+=b[i];
	}
	memset(dp,0,sizeof(dp));			//��ʼ��Ϊfalse
	for (int A=0;A<=maxA;A++)
		for (int B=0;B<=maxB;B++)
			dp[0][A][B]=true;			//k=0ʱһ���н�
	for(int k=1;k<=n;k++)
	{
		for(int A=0;A<=maxA;A++)
		{	for(int B=0;B<=maxB;B++)
			{	if (A-a[k-1]>=0)		//��MA�ϴ���
					dp[k][A][B]=dp[k-1][A-a[k-1]][B];
				if (B-b[k-1]>=0)		//��MB�ϴ���
					dp[k][A][B]=(dp[k][A][B]
						|| dp[k-1][A][B-b[k-1]]);
			}
		}
	}
	int ans=INF;						//�������ʱ��
	for(int A=0;A<=maxA;A++)				//��ans
		for(int B=0;B<=maxB;B++)
			if (dp[n][A][B])
				ans=min(ans,max(A,B));
	return ans;
} 
int main()
{
	printf("ans=%d\n",schedule());
	return 0;
}


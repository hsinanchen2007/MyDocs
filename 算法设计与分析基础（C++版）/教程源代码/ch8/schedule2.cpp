#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f				//���������
#define MAXN 51						//������ҵ��
#define MAXA MAXN*20
#define MAXB MAXN*20
//�����ʾ
int n=6;								//��ҵ��
int a[]={2,5,7,10,5,2};
int b[]={3,8,4,11,3,4};
int schedule()							//����㷨
{
	int maxA=0;
	for (int i=0;i<n;i++)				//��maxA��maxB 
		maxA+=a[i];
	int dp[MAXA];						//һά��̬�滮���� 
	memset(dp,0,sizeof(dp));			//��ʼ��Ϊfalse
	for (int k=1; k<=n; k++) 
	{	for(int A=maxA;A>=0;A--)
		{	if(A<a[k-1])					//���ʱ��ֻ����MB������
				dp[A]=dp[A]+b[k-1];
			else							//����ȡMA����MB�ϴ��������ʱ��
				dp[A]=min(dp[A-a[k-1]],dp[A]+b[k-1]);
		}
	}
	int ans=INF;						//�������ʱ��
	for(int A=0;A<=maxA;A++)
		ans=min(ans,max(A,dp[A]));		
	return ans;
} 
int main()
{
	printf("ans=%d\n",schedule());
	return 0;
}


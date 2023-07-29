#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 101
//�����ʾ
struct Action						//������� 
{
	int b;							//��ʼʱ��
	int e;							//����ʱ��
	int length;						//���ִ��ʱ��
    bool operator < (const Action t) const
    {
		return e<t.e;				//������ʱ���������
    }
};
int n=4;							//�����
//Action A[MAXN]={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};	//��Ż
//Action A[MAXN]={{1,6},{6,8},{1,10},{8,12}};	//��Ż
Action A[MAXN]={{4,6},{6,8},{1,10},{6,12}};	//��Ż
//�������ʾ
int dp[MAXN];					//��̬�滮����
int pre[MAXN];					//pre[i]���ǰ������

int plan()						//��dp
{
	memset(dp,0,sizeof(dp));	//dp�����ʼ��
	sort(A,A+n);				//����
	dp[0]=A[0].length;
	pre[0]=-2;					//A[0]û��ǰ���
	for (int i=1;i<n;i++)
	{
		int j=i-1;
		while(j>=0 && A[j].e>A[i].b)
			j--;				//��A[0..i-1]����A[i]���ݵ�����A[j]
		if(j==-1)				//A[i]ǰ��û�м��ݻ
		{
			dp[i]=A[i].length;
			pre[i]=-2;			//û��ǰ���
		}
		else					//A[i]ǰ����������ݻA[j]
		{
			//dp[i]=max(dp[i-1],dp[j]+A[i].length)
			if(i==3)
				printf("j=%d,dp[i-1]=%d,dp[j]+A[i].length=%d\n",j,dp[i-1],dp[j]+A[i].length);
			if (dp[i-1]>dp[j]+A[i].length)
			{
				dp[i]=dp[i-1];
				pre[i]=-1;		//��ѡ��A[i]
			}
			else
			{
				dp[i]=dp[j]+A[i].length;
				pre[i]=j;					//ѡ�лi,ǰ���ΪA[j] 
			}
		}
	}
	return dp[n-1];
}

void disp()					//��������� 
{
	printf("i:\t");
	for(int i=0;i<n;i++)
		printf("%3d",i);
	printf("\n"); 


	printf("b:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].b);
	printf("\n"); 

	printf("e:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].e);
	printf("\n"); 

	printf("l:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].length);
	printf("\n"); 

		
	printf("\npre[i]:\t");
	for(int i=0;i<n;i++)
		printf("%3d",pre[i]);
	printf("\n"); 

	printf("\ndp[i]:\t");
	for(int i=0;i<n;i++)
		printf("%3d",dp[i]);
	printf("\n"); 
	

}
void getx()						//��һ�����Ű��ŷ���
{	vector<int> x;				//���һ������ 
	int i=n-1;					//��n-1��ʼ
	while(true)
	{
		if (i==-2)				//A[i]û��ǰ���
			break;
		if (pre[i]==-1)			//��ѡ��A[i]
			i--;
		else					//ѡ��A[i]
		{
			x.push_back(i);
			i=pre[i];
		}
	}
	printf("x:");
	for(int i=0;i<x.size();i++)
		printf("%d:[%d,%d] ",x[i],A[x[i]].b,A[x[i]].e);
	printf("\n");

	printf("    ѡ��Ļ: ");
	for (int i=x.size()-1;i>=0;i--)
		printf("%d[%d,%d] ",x[i],A[x[i]].b,A[x[i]].e);
	printf("\n");
	printf("    ���ݻ����ʱ��: %d\n",dp[n-1]);
}
int main()
{
	freopen("xyz.txt","w",stdout);
	for (int i=0;i<n;i++)		//���ĳ���
		A[i].length=A[i].e-A[i].b;
	printf("�����=%d\n",plan());
	getx();
	disp();
    return 0;
}

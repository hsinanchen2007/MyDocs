#include<iostream>
#include<string>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define MAX 201
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
string a="sfdqxbw";
string b="gfdgw";
//�������ʾ
int editdist()					//����㷨 
{
	int m=a.size();
	int n=b.size();
	int dp[MAX][MAX];			//��ά��̬�滮���� 
	for (int i=1;i<=m;i++) 
		dp[i][0]=i;			//��a��i���ַ�ȫ��ɾ��ת��Ϊb
	for (int j=1; j<=n;j++)
		dp[0][j]=j;			//��a�в���b��ȫ���ַ�ת��Ϊb
	for (int i=1;i<=m;i++)
	{
       	for (int j=1;j<=n;j++)
		{
			if (a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		}
	}
	return dp[m][n];
}
int main()
{
	printf("�����\n");
	printf("    ���ٵ��ַ���������: %d\n",editdist());
	return 0;
}

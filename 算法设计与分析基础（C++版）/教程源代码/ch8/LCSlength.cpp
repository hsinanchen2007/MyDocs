#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 51							//�����������ַ�����
string a,b;
int m,n;
int dp[MAXN][MAXN];						//��ά��̬�滮����
int LCSlength()							//��dp
{
	dp[0][0]=0;
	for (int i=0;i<=m;i++)				//��dp[i][0]��Ϊ0,�߽�����
		dp[i][0]=0;
	for (int j=0;j<=n;j++)				//��dp[0][j]��Ϊ0,�߽�����
		dp[0][j]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)			//����forѭ������a��b�������ַ�
		{	if (a[i-1]==b[j-1])			//���(1)
				dp[i][j]=dp[i-1][j-1]+1;
			else						//���(2)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

		}
	}
	return dp[m][n];
}
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "�����" << endl;
	m=a.length();					//mΪa�ĳ���
	n=b.length();					//nΪb�ĳ���
	cout << "    ����������г���: " << LCSlength() << endl;
}

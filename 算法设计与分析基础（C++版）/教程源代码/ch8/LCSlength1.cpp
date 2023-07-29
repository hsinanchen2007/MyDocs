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
	int m=a.length();					//mΪa�ĳ���
	int n=b.length();					//nΪb�ĳ���
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
string getsubs()					//��dp����subs
{
	string subs="";					//���һ��LCS
	int k=dp[m][n];					//kΪa��b������������г���
	int i=m,j=n;
	while (k>0)						//��subs�з��������������(����)
	{
		printf("i=%d,j=%d  ",i,j);
		if (dp[i][j]==dp[i-1][j])
		{
			i--;
			printf("i--, i=%d\n",i);
		}
		else if (dp[i][j]==dp[i][j-1])
		{
			j--;
			printf("j--, j=%d\n",i);
		}
		else
		{
			subs+=a[i-1];			//subs�����a[i-1]
			i--; j--; k--;
			printf("���%c i--,j--, i=%d,j=%d\n",a[i],i,j); 
		}
	}
	reverse(subs.begin(),subs.end());	//����subs
	return subs; 
}
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "�����" << endl;
	cout << "    ����������г���: " << LCSlength() << endl;
	m=a.length();					//mΪa�ĳ���
	n=b.length();					//nΪb�ĳ���
	
	printf("dp:\n");
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%3d",dp[i][j]);
		printf("\n");
	}
	
	string subs=getsubs();
	cout << "    һ�������������: " << subs << endl;
	return 0;
}


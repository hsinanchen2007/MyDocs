#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXM 51
#define MAXN 51
//�����ʾ
string s="abcde";
string t="abgde";
//�������ʾ
int dp[MAXM][MAXN];					//��ά��̬�滮���� 
int Maxlength(string s,string t)	//��s��t������������Ӵ��ĳ���
{	int ans=0;
	int n=s.length();
	int m=t.length();
	memset(dp,0,sizeof(dp));		//��ʼ������dp
	for(int i=0;i<n; i++)				//��ʼ��dp��һ��
		if(s[i]==t[0])
			dp[i][0]=1;
    for(int j=0;j<m; j++)				//��ʼ��dp��һ��
		if(s[0]==t[j])
			dp[0][j]=1;
	for(int i=1;i<n;i++)				//����״̬ת�Ʒ�����dp������Ԫ��
	{
		for(int j=1;j<m; j++)
		{	if (s[i]==t[j])
				dp[i][j]=dp[i-1][j-1]+1;
			ans=max(ans,dp[i][j]);
		}
	}
	return ans;
}
int main()
{
	printf("�����\n");
	printf("   ��Ĺ��������Ӵ�: %d\n",Maxlength(s,t));	//�����2
	return 0;
}

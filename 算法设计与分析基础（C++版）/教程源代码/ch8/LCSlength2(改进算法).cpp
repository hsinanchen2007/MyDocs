#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 51							//�����������ַ�����
string a,b;
int LCSlength1()							//�Ľ��㷨
{
	int m=a.length();					//mΪa�ĳ���
	int n=b.length();					//nΪb�ĳ���
	vector<int> dp(n+1,0);				//һά��̬�滮���� 
	for (int i=1;i<=m;i++)
	{
		int upleft=dp[0];       //�׶�i��ʼ��upleft
		for (int j=1;j<=n;j++)
		{
            int tmp=dp[j];      //��ʱ����dp[j]
        	if (a[i-1]==b[j-1])
            	dp[j]=upleft+1;
        	else
            	dp[j] = max(dp[j-1],dp[j]);
            upleft=tmp;     //�޸�upleft
        }
    }
	return dp[n];
} 
int main()
{
	a="abcbdb";
	b="acbbabdbb";
	cout << "�����" << endl;
	cout << "    ����������г���: " << LCSlength1() << endl;
	return 0;
}


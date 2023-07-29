#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100
int ans=0;
int dp[MAXN];
int maxInclen(vector<int> &a)			//������������г���
{	
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if (a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=dp[0];
	for(int i=1;i<n;i++)
		ans=max(ans,dp[i]);
	return ans;
}
vector<int> maxInc(vector<int>& a)		//��һ�������������
{
	int n=a.size();
	vector<int> x;
	int maxj=0;
	for(int j=1;j<n;j++)
		if(dp[j]>dp[maxj])
			maxj=j;
	x.push_back(a[maxj]);
	int rnum=dp[maxj]-1;					//ʣ���Ԫ�ظ��� 
	int j=maxj;							//jָ��ǰ����������е�һ��Ԫ�� 
	int prej=maxj-1;					//prej��������������е�ǰһ��Ԫ��
	while(prej>=0 && rnum!=0)
	{
		if(a[prej]<a[j])
		{	rnum--;
			x.push_back(a[prej]);
			j=prej;
			prej--;
		}
		else prej--;
	}
	reverse(x.begin(),x.end());
	return x;
}

int main()
{
	//freopen("xyz.txt","w",stdout);
	//vector<int> a={1,3,2,5};
	vector<int> a={2,1,5,3,6,4,8,9,7};
	int ans=maxInclen(a);
	printf("�����\n");
	
	printf("dp:\n");
	for(int i=0;i<a.size();i++)
		printf("dp[%d]=%d\n",i,dp[i]);
	
	printf("   ����������еĳ���: %d\n",ans);
	printf("   �����������: ");
	vector<int> x=maxInc(a);
	for(int i=0;i<x.size();i++)
		printf(" %d",x[i]);
	printf("\n");
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100
int parent[MAXN];								//���鼯�洢�ṹ
int rnk[MAXN];									//�洢������(�����ڸ߶�)
void Init(int n)										//���鼯��ʼ��
{	for (int i=1;i<=n;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)									//�ݹ��㷨�����鼯�в���x���ĸ����
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//·��ѹ��
	return parent[x];
}
void Union(int x,int y)						//���鼯��x��y���������ϵĺϲ�
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)										//x��y����ͬһ����ʱ����
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;								//rx�����Ϊry�ĺ���
	else
	{	if (rnk[rx]==rnk[ry])					//����ͬ���ϲ���rx������1
			rnk[rx]++;
		parent[ry]=rx;								//ry�����Ϊrx�ĺ���
	}
}
int friends(vector<vector<int>>&v,int n)			//����㷨 
{
	Init(n);
	for(int i=0;i<v.size();i++)
	{
		int a=v[i][0];
		int b=v[i][1];
		Union(a,b);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if (parent[i]==i && rnk[i]>0)
			ans++;
	return ans;
}
	
int main()
{
	int n=5;
	vector<vector<int>> v={{1,3},{1,5},{2,4}};
	int ans=friends(v,n);
	printf("����Ȧ����=%d\n",ans); 
	return 0;
}

//284K 16MS 
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10050
struct Wooden
{
	int l,w;
	Wooden(int l,int w):l(l),w(w) {}
	bool operator<(const Wooden& b) const
	{
		if(l==b.l)				//������ͬʱ 
			return w<b.w;		//�������������� 
		return l<b.l;			//�����ȵ������� 
	} 
};
int greedly(vector<Wooden>& a)
{
	bool flag[MAXN];
	memset(flag,false,sizeof(flag));
	sort(a.begin(),a.end());
	int n=a.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			int prew=a[i].w;
			for(int j=i;j<n;j++)
			{
				if(flag[j]==0 && a[j].w>=prew)
				{
					prew=a[j].w;
					flag[j]=true;
				}
			}
			ans++;
		}
	}
	return ans;
}
int main()
{
	int t,n,l,w;
	scanf("%d",&t);
	while(t--)
	{
		vector<Wooden> a;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&l,&w);
			a.push_back(Wooden(l,w));
		}
		printf("%d\n",greedly(a));
	} 
	return 0;
 } 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100
int parent[MAXN];								//并查集存储结构
int rnk[MAXN];									//存储结点的秩(近似于高度)
void Init(int n)										//并查集初始化
{	for (int i=1;i<=n;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)									//递归算法：并查集中查找x结点的根结点
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//路径压缩
	return parent[x];
}
void Union(int x,int y)						//并查集中x和y的两个集合的合并
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)										//x和y属于同一棵树时返回
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;								//rx结点作为ry的孩子
	else
	{	if (rnk[rx]==rnk[ry])					//秩相同，合并后rx的秩增1
			rnk[rx]++;
		parent[ry]=rx;								//ry结点作为rx的孩子
	}
}
int friends(vector<vector<int>>&v,int n)			//求解算法 
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
	printf("朋友圈个数=%d\n",ans); 
	return 0;
}

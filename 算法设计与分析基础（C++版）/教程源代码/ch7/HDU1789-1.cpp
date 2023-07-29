//31MS 1748K 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 1010
vector<int> parent;										//并查集存储结构
vector<int> rnk;											//存储结点的秩(近似于高度)
int Find(vector<int>& parent,int x)						//递归算法：并查集中查找x结点的根结点
{	if (x!=parent[x])
		parent[x]=Find(parent,parent[x]);					//路径压缩
	return parent[x];
}
struct Job
{
    int dtime;						//截止日期
    int punish;						//扣分 
    bool operator<(const Job& b) const
	{
		return punish>b.punish;		//按punish递减排序 
	}
};
int n;
Job a[MAXN];
int greedly(int maxd)
{
	parent.resize(maxd);
	for(int i=0;i<=maxd;i++)				//查集初始化
		parent[i]=i;
	sort(a,a+n);							//排序 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int day=Find(parent,a[i].dtime);	//查找截止日期之前的空时间 
		if(day>0)							//找到空时间
			parent[day]=day-1;				//合并 
		else
			ans+=a[i].punish;				//累计扣分 
		
	}
	return ans;	
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int maxd=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
        	scanf("%d",&a[i].dtime);
			maxd=max(maxd,a[i].dtime);
		}
        for(int i=0;i<n;i++)
            scanf("%d",&a[i].punish);
        printf("%d\n",greedly(maxd));
    }
    return 0;
}


//46MS 1748K 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 1010
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
	vector<bool> days(maxd,false);
	sort(a,a+n);					//排序 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int j=a[i].dtime;
		for(;j>0;j--)				//查找截止日期之前的空时间 
		{
			if(days[j]==false)		//找到空时间 
			{
				days[j]=true;
				break;
            }
		}
		if(j==0)					//没有找到空时间 
			ans+=a[i].punish;		//累计扣分 
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


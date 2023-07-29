//46MS 1748K 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 1010
struct Job
{
    int dtime;						//��ֹ����
    int punish;						//�۷� 
    bool operator<(const Job& b) const
	{
		return punish>b.punish;		//��punish�ݼ����� 
	}
};
int n;
Job a[MAXN];
int greedly(int maxd)
{
	vector<bool> days(maxd,false);
	sort(a,a+n);					//���� 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int j=a[i].dtime;
		for(;j>0;j--)				//���ҽ�ֹ����֮ǰ�Ŀ�ʱ�� 
		{
			if(days[j]==false)		//�ҵ���ʱ�� 
			{
				days[j]=true;
				break;
            }
		}
		if(j==0)					//û���ҵ���ʱ�� 
			ans+=a[i].punish;		//�ۼƿ۷� 
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


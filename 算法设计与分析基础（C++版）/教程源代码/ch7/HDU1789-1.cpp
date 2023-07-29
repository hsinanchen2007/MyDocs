//31MS 1748K 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 1010
vector<int> parent;										//���鼯�洢�ṹ
vector<int> rnk;											//�洢������(�����ڸ߶�)
int Find(vector<int>& parent,int x)						//�ݹ��㷨�����鼯�в���x���ĸ����
{	if (x!=parent[x])
		parent[x]=Find(parent,parent[x]);					//·��ѹ��
	return parent[x];
}
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
	parent.resize(maxd);
	for(int i=0;i<=maxd;i++)				//�鼯��ʼ��
		parent[i]=i;
	sort(a,a+n);							//���� 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int day=Find(parent,a[i].dtime);	//���ҽ�ֹ����֮ǰ�Ŀ�ʱ�� 
		if(day>0)							//�ҵ���ʱ��
			parent[day]=day-1;				//�ϲ� 
		else
			ans+=a[i].punish;				//�ۼƿ۷� 
		
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


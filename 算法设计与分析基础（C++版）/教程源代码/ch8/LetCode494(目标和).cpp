#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 51
//问题表示
struct Action				//活动类型 
{	int b;					//活动起始时间
	int e;					//活动结束时间
	bool operator<(const Action &s) const
	{
		return e<=s.e;			//用于按活动结束时间递增排序
	}
};
//求解结果表示
bool flag[MAX];						//标记选择的活动
void greedly(vector<Action>& A)		//求解最大兼容活动子集
{
	int n=A.size();
	memset(flag,0,sizeof(flag));//初始化为false
	sort(A.begin(),A.end());			//A[1..n]按活动结束时间递增排序
	int preend=0;				//前一个兼容活动的结束时间
	for (int i=0;i<n;i++)
	{	if (A[i].b>=preend)
		{	flag[i]=true;		//选择A[i]活动
			preend=A[i].e;
		}
	}
}
int main()
{
	vector<Action> A={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};
	int cnt=0;					//选取的兼容活动个数
	greedly(A);
	printf("求解结果\n");
	printf("  选取的活动:");
	for (int i=0;i<A.size();i++)
		if (flag[i])
		{
			printf("[%d,%d] ",A[i].b,A[i].e);
			cnt++;
		}
	printf("\n  共%d个活动\n",cnt);
	return 0;
}

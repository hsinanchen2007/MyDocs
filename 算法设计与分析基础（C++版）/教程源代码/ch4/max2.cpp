//求解最大和次大元素算法
#include<iostream>
#include<vector> 
using namespace std;
#define INF 0x3f3f3f3f		//表示最大的整数
void solve1(vector<int>&a,int low,int high,int &max1,int &max2) //被solve调用 
{
	if (low==high)		//区间只有一个元素
	{
		max1=a[low];
		max2=-INF;
	}
	else if (low==high-1)	//区间只有两个元素
	{
		max1=max(a[low],a[high]);
		max2=min(a[low],a[high]);
	}
	else
	{
		int mid=(low+high)/2;
		int lmax1,lmax2;
		solve1(a,low,mid,lmax1,lmax2);		//左区间求lmax1和lmax2
		int rmax1,rmax2;
		solve1(a,mid+1,high,rmax1,rmax2);	//右区间求lmax1和lmax2
		if (lmax1>rmax1)
		{
			max1=lmax1;
			max2=max(lmax2,rmax1);	//lmax2,rmax1中求次大元素
		}
		else
		{
			max1=rmax1;
			max2=max(lmax1,rmax2);	//lmax1,rmax2中求次大元素
		}
	}
}
void solve(vector<int>&a,int &max1,int &max2)	//求a中最大和次大元素 
{
	solve1(a,0,a.size()-1,max1,max2);
}
int main()
{
	vector<int> a={1,3,3};
	int max1,max2;
	solve(a,max1,max2);
	printf("max1=%d,max2=%d\n",max1,max2);
	return 0;
}




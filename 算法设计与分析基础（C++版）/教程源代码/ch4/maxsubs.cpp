//求解最大连续子序列和的算法
#include<iostream>
#include<vector>
using namespace std;
int max3(int a,int b,int c)				//求出3个int整数中的最大值
{
	return max(max(a,b),c);
} 
int maxSubSum31(vector<int>&a,int low,int high)	//被maxSubSum3调用
{
	if (low==high)						//子序列只有一个元素时
	{	if (a[low]>0) 					//该元素大于0时返回它
			return a[low];
		else								//该元素小于或等于0时返回0
			return 0; 
	} 
	int mid=(low+high)/2;					//求中间位置
	int maxLeftSum=maxSubSum31(a,low,mid);		//求左边的最大连续子序列之和
	int maxRightSum=maxSubSum31(a,mid+1,high);	//求右边的最大连续子序列之和

	int maxLeftBorderSum=0,lowBorderSum=0;
	for (int i=mid;i>=low;i--)				//求出以左边加上a[mid]构成的连续序列的最大和
	{	lowBorderSum+=a[i];
		if (lowBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=lowBorderSum;
	}
	int maxRightBorderSum=0,highBorderSum=0;
	for (int j=mid+1;j<=high;j++)			//求出a[mid]右边元素构成的连续序列的最大和
	{	highBorderSum+=a[j];
		if (highBorderSum>maxRightBorderSum)
			maxRightBorderSum=highBorderSum;
	}
	int ans=max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum); 
	return max(ans,0);
}
int maxSubSum3(vector<int>&a)		//递归算法：求a序列中最大连续子序列和
{
	int n=a.size();
	return maxSubSum31(a,0,n-1);
}

int main()
{	vector<int> a{-2,11,-4,13,-5,-2};
	vector<int> b={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	printf("a序列的最大连续子序列的和: %d\n",maxSubSum3(a));
	printf("b序列的最大连续子序列的和: %d\n",maxSubSum3(b));
	return 0;
}

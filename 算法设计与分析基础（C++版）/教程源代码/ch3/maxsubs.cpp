#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubSum1(vector<int>& a)			//解法1
{
	int n=a.size();
	int maxsum=0,cursum;
	for (int i=0;i<n;i++)				//两重循环穷举所有的连续子序列
	{	for (int j=i;j<n;j++)
		{	cursum=0;
			for (int k=i;k<=j;k++)
				cursum+=a[k];
			maxsum=max(maxsum,cursum);	//通过比较求最大maxsum
		}
	}
	return maxsum;
}
int maxSubSum2(vector<int>& a)			//解法2
{
	int n=a.size();
	int maxsum=0,cursum;
	for (int i=0;i<n;i++)  
	{	cursum=0;
		for (int j=i;j<n;j++)
		{	cursum+=a[j];
			maxsum=max(maxsum,cursum);	//通过比较求最大maxsum
		}
	}
	return maxsum;
}

int maxSubSum3(vector<int>& a)			//解法3
{
	int n=a.size();
	int maxsum=0,cursum=0;
	for (int i=0;i<n;i++)  
	{
		cursum+=a[i];
		maxsum=max(maxsum,cursum);		//通过比较求最大maxsum
		if(cursum<0)					//若cursum<0，最大连续子序列从下一个位置开始 
			cursum=0;
	}
	return maxsum;
}

int main()
{	vector<int> a={-2,11,-4,13,-5,-2};
	vector<int> b={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	printf("a: ");
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n"); 
	printf("  解法1：最大连续子序列的和: %d\n",maxSubSum1(a));
	printf("  解法2：最大连续子序列的和: %d\n",maxSubSum2(a));
	printf("  解法3：最大连续子序列的和: %d\n",maxSubSum3(a));

	printf("b: ");
	for(int i=0;i<b.size();i++)
		printf("%d ",b[i]);
	printf("\n"); 
	printf("  解法1：最大连续子序列的和: %d\n",maxSubSum1(b));
	printf("  解法2：最大连续子序列的和: %d\n",maxSubSum2(b));
	printf("  解法3：最大连续子序列的和: %d\n",maxSubSum3(b));

	return 0;
	
}


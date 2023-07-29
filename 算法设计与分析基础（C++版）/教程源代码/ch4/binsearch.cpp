//递归和非递归折半查找算法
#include<iostream>
#include<vector>
using namespace std;
int BinSearch11(vector<int>&R,int low,int high,int k) //被BinSearch1调用
{	if (low<=high)				//当前区间存在元素时
	{	int mid=(low+high)/2;		//求查找区间的中间位置
		if (k==R[mid])			//找到后返回下标mid
			return mid;
		if (k<R[mid])			//当k<R[mid]时,在左区间中递归查找
			return BinSearch11(R,low,mid-1,k);
		else					//当k>R[mid]时,在右区间中递归查找
			return BinSearch11(R,mid+1,high,k);
	}
	else return -1;			//若当前查找区间为空时返回-1
}
int BinSearch1(vector<int>&R,int k) 	//递归二分查找算法
{
	int n=R.size();
	return BinSearch11(R,0,n-1,k); 
} 

int BinSearch2(vector<int>&R,int k)	//迭代算法：二分查找
{	int low=0,high=R.size()-1;
	while (low<=high)			//当前区间存在元素时循环
	{	int mid=(low+high)/2;		//求查找区间的中间位置
		if (k==R[mid])			//找到后返回其下标mid
			return mid;
		if (k<R[mid])			//当k<R[mid]时,在左区间中递归查找
			high=mid-1;
		else					//当k>R[mid]时,在右区间中递归查找
			low=mid+1;
	}
	return -1;					//若当前查找区间没有元素时返回-1
}
int main()
{
	vector<int> a={1,2,3,4,5,6,7,8,9,10};
	int k=6;
	int i=BinSearch2(a,k);
	if (i>=0)
		printf("a[%d]=%d\n",i,k);
	else
		printf("未找到%d元素\n",k);
	return 0;
}

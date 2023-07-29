#include<iostream>
#include<vector>
using namespace std;
int insertpoint(vector<int>& R,int k)
{	int n=R.size();
	int low=0,high=n;
	while (low<high)							//查找区间至少含两个元素 
	{
		printf("[%d..%d]\n",low,high);
		int mid=(low+high)/2;
		if (k<=R[mid])							//k<=R[mid]
			high=mid;							//在左区间中查找(含R[mid]) 
		else
			low=mid+1;							//在右区间中查找
	}
	
	printf("end:[%d..%d]\n",low,high);
	return low;									//返回low
}
int main()
{
	vector<int> a={1,2,2,4};
	int k=5;
	int i=insertpoint(a,k);
	printf("%d的插入点=%d\n",k,i);
	return 0;
}

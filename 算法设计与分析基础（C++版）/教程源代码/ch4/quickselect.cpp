#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
int Partition1(vector<int> &R,int s,int t)  	//划分算法1
{	int i=s,j=t;
 	int base=R[s];							//以表首元素为基准
 	while (i<j)								//从表两端交替向中间遍历,直至i=j为止
  	{	while (j>i && R[j]>=base)
      		j--;							//从后向前遍历,找一个小于等于基准的R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]前移覆盖R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;						//从前向后遍历,找一个大于基准的R[i]
     	if (i<j)
      	{	R[j]=R[i];					//R[i]后移覆盖R[j]
        	j--;
    	}
	}
 	R[i]=base;								//基准归位
 	return i;								//返回归位的位置
}
int QuickSelect11(vector<int>&R,int s,int t,int k)	//被QuickSelect1调用
{
	if (s<t) 								//区间内至少存在2个元素的情况
	{
		int i=Partition1(R,s,t);			//可以使用前面两种划分算法中的任意一种

		printf("划分结果i=%d: ",i);
		for(int j=0;j<5;j++)
			printf("%3d",R[j]); 
		printf("\n");

		if (k-1==i)
		{
			printf("k=i-1找到\n"); 
			return R[i];
		}
		else if(k-1<i)
		{
			printf("在R[%d..%d]中查找\n",s,i-1); 
			return QuickSelect11(R,s,i-1,k);			//在左区间中递归查找
		}
		else
		{
			printf("在R[%d..%d]中查找\n",i+1,t); 
			return QuickSelect11(R,i+1,t,k);			//在右区间中递归查找
		}
	}
	else if (s==t && s==k-1)					//区间内只有一个元素且s=k-1
	{
		printf("一个元素\n"); 
		return R[k-1];
	}
}
int QuickSelect1(vector<int>&R,int k)		//递归算法：在R找第k小的元素
{
	int n=R.size();
	return QuickSelect11(R,0,n-1,k);
}

int main()
{
	vector<int> a{2,5,1,4,3};
	int k=3;
	int e=QuickSelect1(a,k);
	printf("第%d小的元素:%d\n",k,e);
	return 0;
}

/* 
int main()
{
	vector<int> a{2,5,1,7,10,6,9,4,3,8};
	for (int k=1;k<=a.size();k++)
	{	int e=QuickSelect(a,k);
		printf("第%d小的元素:%d\n",k,e);
	}
	return 0;
}
*/


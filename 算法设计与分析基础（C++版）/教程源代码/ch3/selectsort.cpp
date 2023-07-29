#include<iostream>
#include<vector>
using namespace std;

/********************************************/
/***迭代算法*****************************/
/********************************************/
void Select(vector<int>& R,int i)				//在R[i..n-1]中选择最小元素交换到R[i]位置
{
	int minj=i;									//minj表示R[i..n-1]中最小元素的下标
	for (int j=i+1;j<R.size();j++)				//在R[i..n-1]中找最小元素
		if (R[j]<R[minj])
			minj=j;
	if (minj!=i)								//若最小元素不是R[i]
		swap(R[minj],R[i]);						//交换
}

void SelectSort1(vector<int>& R)				//迭代法：简单选择排序
{	int n=R.size();
	for (int i=0;i<n-1;i++)		//进行n-1趟排序
		Select(R,i);
}


/********************************************/
/***先递后合算法*****************************/
/********************************************/
void SelectSort21(vector<int>& R,int i)			//递归的简单选择排序
{
	if (i==-1) return;							//满足递归出口条件
	SelectSort21(R,i-1);
	Select(R,i);
}
void SelectSort2(vector<int>& R)				//递归的简单选择排序
{
	SelectSort21(R,R.size()-2);
}


/********************************************/
/***先合后递算法*****************************/
/********************************************/
void SelectSort31(vector<int>& R,int i)			//递归的简单选择排序
{
	int n=R.size();
	if (i==n-1) return;							//满足递归出口条件
	Select(R,i);
	SelectSort31(R,i+1);
}

void SelectSort3(vector<int>& R)				//递归的简单选择排序
{
	SelectSort31(R,0);
}
	
/********************************************/

void disp(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
}


int main()
{
	vector<int> a={2,5,4,1,3};
	printf("a: "); disp(a);
	printf("排序\n");
	SelectSort3(a);
	printf("a: "); disp(a);
	return 0;
}

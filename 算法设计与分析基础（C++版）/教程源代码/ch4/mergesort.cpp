#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int>&R)			//输出a中所有元素
{
	for (int i=0;i<R.size();i++)
		printf("%d ",R[i]);
	printf("\n");
}

void Merge(vector<int>&R,int low,int mid,int high)
//将R[low..mid]和R[mid+1..high]两个相邻的有序子序列归并为有序子序列R[low..high]
{	vector<int> R1;
	int i=low,j=mid+1;			//i、j分别为两个子表的下标
	while (i<=mid && j<=high)	//在子表1和子表2均未遍历完时循环
		if (R[i]<=R[j])			//将子表1中的元素归并到R1
		{	R1.push_back(R[i]);
			i++; 
		}
		else					//将子表2中的元素归并到R1
		{	R1.push_back(R[j]);
			j++; 
		}
	while (i<=mid)					//将子表1余下元素改变到R1
	{	R1.push_back(R[i]);
		i++; 
	}
	while (j<=high)					//将子表2余下元素改变到R1
	{	R1.push_back(R[j]);
		j++;;
	}
	for (int k=0,i=low;i<=high;k++,i++) 	//将R1复制回R中
		R[i]=R1[k];
}
//****自底向上的二路归并排序算法***************
void MergePass(vector<int>&R,int length)	//一趟二路归并排序
{	int i,n=R.size();
	for (i=0;i+2*length-1<n;i=i+2*length)	//归并length长的两相邻子表
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)						//余下两个子表,后者长度小于length
		Merge(R,i,i+length-1,n-1);			//归并这两个子表
}
void MergeSort1(vector<int>&R)				//自底向上的二路归并算法
{	for (int length=1;length<R.size();length=2*length)
		MergePass(R,length);
}
//****自顶向下的二路归并排序算法***************
void MergeSort21(vector<int>&R,int low,int high)	//被MergeSort2调用
{
	if (low<high)					//子序列有两个或以上元素
	{	int mid=(low+high)/2;			//取中间位置
		MergeSort21(R,low,mid);		//对a[low..mid]子序列排序
		MergeSort21(R,mid+1,high);	//对a[mid+1..high]子序列排序
		Merge(R,low,mid,high);		//将两子序列合并,见前面的算法
	}
}
void MergeSort2(vector<int>&R)				//二路归并算法
{	int n=R.size();
	MergeSort21(R,0,n-1);
} 
int main()
{
	vector<int> a={2,5,1,7,10,6,9,4,3,8};
	//vector<int> a={6,2,1,4,5,3};
	printf("排序前:"); disp(a);
	MergeSort2(a);
	printf("排序后:"); disp(a);
	return 0;
}


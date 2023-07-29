#include<iostream>
#include<vector>
using namespace std; 
long long ans; 											//存放逆序数
void Merge(vector<int> &R,int low,int mid,int high)
//将R[low..mid]和R[mid+1..high]两个有序段二路归并为一个有序段R[low..high]
{	vector<int> R1;
	R1.resize(high-low+1);							//设置R1的长度为high-low+1
	int i=low,j=mid+1,k=0;							//k是R1的下标,i、j分别为第1、2段的下标
	while (i<=mid && j<=high)						//在第1段和第2段均未扫描完时循环
	{	if (R[i]>R[j])										//将第2段中的元素放入R1中
		{	R1[k]=R[j];
			ans+=mid-i+1;								//累计逆序数
			j++; k++;
		}
		else													//将第1段中的元素放入R1中
		{	R1[k]=R[i];
			i++; k++;
		}
	}
	while (i<=mid)										//将第1段余下部分复制到R1
	{	R1[k]=R[i];
		i++; k++;
	}
	while (j<=high)										//将第2段余下部分复制到R1
	{	R1[k]=R[j];
		j++; k++;
	}
	for (k=0,i=low;i<=high;k++,i++)				//将R1复制回R中
		R[i]=R1[k];
}
void MergeSort21(vector<int> &R,int s,int t)	//被MergeSort2调用
{	if (s>=t) return;										//R[s..t]的长度为0或者1时返回
	int m=(s+t)/2;											//取中间位置m
	MergeSort21(R,s,m);								//对前子表排序
	MergeSort21(R,m+1,t);							//对后子表排序
	Merge(R,s,m,t);										//将两个有序子表合并成一个有序表
}
void MergeSort2(vector<int> &R,int n)		//自顶向下的二路归并排序
{
	MergeSort21(R,0,n-1);
}
int main()
{	int n,x;
	while(scanf("%d",&n)!=EOF)
	{	if (n==0) break;
		vector<int> R;
		for (int i=0;i<n;i++)
		{	scanf("%d",&x);
			R.push_back(x);
		}
		ans=0;		
		MergeSort2(R,n);
		printf("%lld\n",ans);
	}
	return 0;
}


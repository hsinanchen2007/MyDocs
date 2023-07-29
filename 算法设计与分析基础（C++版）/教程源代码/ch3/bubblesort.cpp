#include<iostream>
#include<vector>
using namespace std;

void disp(vector<int>&a)
{
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
}

void Bubble(vector<int>& R,int i,bool& exchange)	//在R[i..n-1]中冒泡最小元素到R[i]位置
{
	int n=R.size();
	for (int j=n-1;j>i;j--)							//无序区元素比较,找出最小元素
		if (R[j-1]>R[j])							//当相邻元素反序时
		{	swap(R[j],R[j-1]);						//a[j]与a[j-1]进行交换
			exchange=true;							//本趟排序发生交换置exchange为true
		}
}
/********************************************/
/***迭代算法*****************************/
/********************************************/
void BubbleSort1(vector<int>& R)		//迭代算法：冒泡排序
{
	int n=R.size();
	bool exchange;
	for (int i=0;i<n-1;i++)			//进行n-1趟排序
	{	exchange=false;				//本趟排序前置exchange为false
		Bubble(R,i,exchange);
		if (exchange==false)		//本趟未发生交换时结束算法
			return;
	}
}


/********************************************/
/***先递后合算法*****************************/
/********************************************/

void Bubble1(vector<int>& R,int i)				//在R[i..n-1]中冒泡最小元素到R[i]位置
{
	int n=R.size();
	for (int j=n-1;j>i;j--)						//无序区元素比较,找出最小元素
		if (R[j-1]>R[j])						//当相邻元素反序时
			swap(R[j],R[j-1]);					//R[j]与R[j-1]进行交换
}

void BubbleSort21(vector<int>& R,int i)			//递归的冒泡排序
{
	if (i==-1) return;							//满足递归出口条件
	BubbleSort21(R,i-1);						//递归调用 
	Bubble1(R,i);
}
void BubbleSort2(vector<int>& R)				//递归冒泡排序 
{
	int n=R.size();
	BubbleSort21(R,n-2);
}


/********************************************/
/***先合后递算法*****************************/
/********************************************/

void BubbleSort31(vector<int>& R,int i)			//递归的简单选择排序
{
	int n=R.size();
	if (i==n-1) return;							//满足递归出口条件
	Bubble1(R,i);								//递归调用 
	BubbleSort31(R,i+1);
}

void BubbleSort3(vector<int>& R)				//递归冒泡排序
{
	BubbleSort31(R,0);
}
	
/********************************************/



int main()
{
	vector<int> a={2,5,4,1,3};
	printf("a: "); disp(a);
	printf("排序\n");
	BubbleSort3(a);
	printf("a: "); disp(a);
	return 0;
}

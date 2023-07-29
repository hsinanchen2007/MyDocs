#include<iostream>
#include<vector>
using namespace std;
void Insert(vector<int>&R,int i)		//将R[i]有序插入到R[0..i-1]中
{
	int tmp=R[i];
	int j=i-1; 
	do									//找R[i]的插入位置
	{	R[j+1]=R[j];   					//将关键字大于R[i]的元素后移
		j--;
	} while(j>=0 && R[j]>tmp);			//直到R[j]<=tmp为止 
	R[j+1]=tmp;      					//在j+1处插入R[i]
}
/********************************************/
/***迭代算法*****************************/
/********************************************/
void InsertSort1(vector<int> &R) 		//迭代算法：直接插入排序
{	int n=R.size();
	for (int i=1;i<n;i++) 
	{	if (R[i]<R[i-1])				//反序时
			Insert(R,i);
	}
}

/********************************************/
/***先递后合算法*****************************/
/********************************************/

void InsertSort21(vector<int> &R,int i) //递归直接插入排序
{
	if(i==0) return;
	InsertSort21(R,i-1);
	if (R[i]<R[i-1])					//反序时
		Insert(R,i);
}
void InsertSort2(vector<int> &R) 		//递归算法：直接插入排序
{
	int n=R.size();
	InsertSort21(R,n-1);
}

/*
/********************************************/
/***先合后递算法*****************************/
/********************************************/

void InsertSort31(vector<int> &R,int i) //递归直接插入排序
{
	int n=R.size();
	if(i<1 || i>n-1) return;
	if (R[i]<R[i-1])					//反序时
		Insert(R,i);
	InsertSort31(R,i+1);
}
void InsertSort3(vector<int> &R) 		//递归算法：直接插入排序
{
	InsertSort31(R,1);
}

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
	InsertSort2(a);
	printf("a: "); disp(a);
	return 0;
}

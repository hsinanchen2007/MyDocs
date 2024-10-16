//寻找两个等长有序序列的中位数的算法
#include<iostream>
#include<vector>
using namespace std;

void prepart(int &s,int &t)			//求a[s..t]序列的前半子序列
{	int m=(s+t)/2;
	t=m;
}
void postpart(int &s,int &t)		//求a[s..t]序列的后半子序列
{	int m=(s+t)/2;
	if ((s+t)%2==0)					//序列中有奇数个元素
		s=m;
	else							//序列中有偶数个元素
		s=m+1;
}
void display(int a[],int s,int t)
{
	for (int i=s;i<=t;i++)
		printf("%d ",a[i]);
	printf("\t");
}
int midnum11(int a[],int s1,int t1,int b[],int s2,int t2) //求两个有序序列a[s1..t1]和b[s2..t2]的中位数
{
	int m1,m2;
	if (s1==t1 && s2==t2)				//两序列只有一个元素时返回较小者
		return a[s1]<b[s2]?a[s1]:b[s2];
	else
	{	m1=(s1+t1)/2;				//求a的中位数
		m2=(s2+t2)/2;				//求b的中位数
		if (a[m1]==b[m2])			//两中位数相等时返回该中位数
		{
			printf("%d=%d:  ",a[m1],b[m2]);		
			return a[m1];
		}
		if (a[m1]<b[m2])			//当a[m1]<b[m2]时
		{	postpart(s1,t1);		//a取后半部分
			prepart(s2,t2);			//b取前半部分

			printf("%d<%d:  ",a[m1],b[m2]);
			printf("a:"); display(a,s1,t1);
			printf("b:"); display(b,s2,t2);
			printf("\n");

			return midnum11(a,s1,t1,b,s2,t2);
		}
		else						//当a[m1]>b[m2]时
		{	prepart(s1,t1);			//a取前半部分
			postpart(s2,t2);		//b取后半部分

			printf("%d>%d:  ",a[m1],b[m2]);
			printf("a:"); display(a,s1,t1);
			printf("b:"); display(b,s2,t2);
			printf("\n");

			return midnum11(a,s1,t1,b,s2,t2);
		}
	}
}
int midnum1(int a[],int b[],int n) 	//求两个有序序列a和b的中位数
{
	return midnum11(a,0,n-1,b,0,n-1);
}

int midnum2(int a[],int b[],int n)		//求两个有序序列a和b的中位数
{	int s1,t1,m1,s2,t2,m2;
	s1=0; t1=n-1;
	s2=0; t2=n-1;
	while (s1!=t1 || s2!=t2)
	{	m1=(s1+t1)/2;
		m2=(s2+t2)/2;
		if (a[m1]==b[m2])
			return a[m1];
		if (a[m1]<b[m2])
		{	postpart(s1,t1);
			prepart(s2,t2);
		}
		else
		{	prepart(s1,t1);
			postpart(s2,t2);
		}
	}
	return a[s1]<b[s2]?a[s1]:b[s2];
}

int main()
{
	//int a[]={1,3,5,7};
	//int b[]={2,4,6,8};
	int a[]={1,3,4,6,9};
	int b[]={2,3,5,8,10};
	int n=sizeof(a)/sizeof(a[0]);
	printf("a:"); display(a,0,n-1);
	printf("b:"); display(b,0,n-1); printf("\n");
	printf("中位数:%d\n",midnum1(a,b,n));
	return 0;
}

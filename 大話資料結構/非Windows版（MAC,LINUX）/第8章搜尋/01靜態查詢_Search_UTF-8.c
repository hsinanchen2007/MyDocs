#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 纗丁癬﹍だ皌秖 */

typedef int Status;	/* Status琌ㄧ计篈,ㄤ琌ㄧ计挡狦篈祘Α絏OK单 */ 

int F[100]; /* 禣ん计 */

/* 礚抖琩高a皚n璶琩高皚计key璶琩高闽龄 */
int Sequential_Search(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return 0;
}
/* Τ抖琩高 */
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;
	i=n;
	while(a[i]!=key)
	{
		i--;
	}
	return i;
}

/* ч琩高 */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ﹚竡程ま癘魁 */
	high=n;	/* ﹚竡程蔼ま癘魁ソ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ч */
		if (key<a[mid])		/* 璝琩高ゑい */
			high=mid-1;		/* 程蔼ま秸俱いま */
		else if (key>a[mid])/* 璝琩高ゑい */
			low=mid+1;		/* 程ま秸俱いま */
		else
			return mid;		/* 璝单玥弧mid琩高竚 */		
	}
	return 0;
}

/* 础琩高 */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ﹚竡程ま癘魁 */
	high=n;	/* ﹚竡程蔼ま癘魁ソ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* 础 */
		if (key<a[mid])		/* 璝琩高ゑ础 */
			high=mid-1;		/* 程蔼ま秸俱础ま */
		else if (key>a[mid])/* 璝琩高ゑ础 */
			low=mid+1;		/* 程ま秸俱础ま */
		else
			return mid;		/* 璝单玥弧mid琩高竚 */
	}
	return 0;
}

/* 禣ん琩高 */
int Fibonacci_Search(int *a,int n,int key)
{
	int low,high,mid,i,k=0;
	low=1;						/* ﹚竡程ま癘魁 */
	high=n;						/* ﹚竡程蔼ま癘魁ソ */
	while(n>F[k]-1)
		k++;
	for (i=n;i<F[k]-1;i++)
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;
		if (key<a[mid])
		{
			high=mid-1;		
			k=k-1;
		}
		else if (key>a[mid])
		{
			low=mid+1;		
			k=k-2;
		}
		else
		{
			if (mid<=n)
				return mid;		/* 璝单玥弧mid琩高竚 */
			else 
				return n;
		}
	}
	return 0;
}




  

int main(void)
{    

	int a[MAXSIZE+1],i,result;
	int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};
		
	for(i=0;i<=MAXSIZE;i++)
	{
		a[i]=i;
	}
	result=Sequential_Search(a,MAXSIZE,MAXSIZE);
	printf("Sequential_Search:%d \n",result);
	result=Sequential_Search2(a,MAXSIZE,1);
	printf("Sequential_Search2:%d \n",result);

	result=Binary_Search(arr,10,62);
	printf("Binary_Search:%d \n",result);

	
	result=Interpolation_Search(arr,10,62);
	printf("Interpolation_Search:%d \n",result);

	
	F[0]=0;
	F[1]=1;
	for(i = 2;i < 100;i++)  
	{ 
		F[i] = F[i-1] + F[i-2];  
	} 
	result=Fibonacci_Search(arr,10,62);
	printf("Fibonacci_Search:%d \n",result);
	
	return 0;
}

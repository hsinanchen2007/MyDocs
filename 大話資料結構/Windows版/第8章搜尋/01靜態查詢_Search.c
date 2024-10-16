#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ーーー釦脱ー */

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/ 

int F[100]; /* ー�戞次�P */

/* �Qーーーーーーーーーーーーーーー�Vーkeyーーーーーーー */
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
/* ーーーーーー*/
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

/* ーー啄 */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ー�{�鵝咫次次治f */
	high=n;	/* ー�{�N〉ーーー�f */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ーー*/
		if (key<a[mid])		/* ーーー�}ーーー */
			high=mid-1;		/* ー�N〉ーー僚ーーーー�f */
		else if (key>a[mid])/* ーーー�}ーーー*/
			low=mid+1;		/* ー�鵝咫次捨宗次次次治f */
		else
		{
			return mid;		/* ーー�隋次�midーーー��ーー */
		}
		
	}
	return 0;
}

/* ー塗ー */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ー�{�鵝咫次次治f */
	high=n;	/* ー�{�N〉ーーー�f */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ー株/
		if (key<a[mid])		/* ーーー�}ーー */
			high=mid-1;		/* ー�N〉ーー�Z�pーーー�f */
		else if (key>a[mid])/* ーーー�}ー憮 */
			low=mid+1;		/* ー�鵝咫次珠Z�pーーー�f */
		else
			return mid;		/* ーー�隋次�midーーー��ーー */
	}
	return 0;
}

/* ー�戞次次�*/
int Fibonacci_Search(int *a,int n,int key)
{
	int low,high,mid,i,k=0;
	low=1;						/* ー�{�鵝咫次次治f */
	high=n;						/* ー�{�N〉ーーー�f */
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
				return mid;		/* ーー�隋次�midーーー��ーー */
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

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */ 

int F[100]; /* �O��ƦC */

/* �L��L���Ǭd�ߡAa���}�C�An���n�d�ߪ��}�C�ӼơAkey���n�d�ߪ�����r */
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
/* ����L���Ǭd�� */
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

/* ��b�d�� */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* �w�q�̧C���ެ��O������ */
	high=n;	/* �w�q�̰����ެ��O������ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ��b */
		if (key<a[mid])		/* �Y�d�߭Ȥ񤤭Ȥp */
			high=mid-1;		/* �̰����޽վ�줤����ޤp�@�� */
		else if (key>a[mid])/* �Y�d�߭Ȥ񤤭Ȥj */
			low=mid+1;		/* �̧C���޽վ�줤����ޤj�@�� */
		else
			return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */		
	}
	return 0;
}

/* ���Ȭd�� */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* �w�q�̧C���ެ��O������ */
	high=n;	/* �w�q�̰����ެ��O������ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ���� */
		if (key<a[mid])		/* �Y�d�߭Ȥ񴡭Ȥp */
			high=mid-1;		/* �̰����޽վ�촡�ȯ��ޤp�@�� */
		else if (key>a[mid])/* �Y�d�߭Ȥ񴡭Ȥj */
			low=mid+1;		/* �̧C���޽վ�촡�ȯ��ޤj�@�� */
		else
			return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */
	}
	return 0;
}

/* �O��d�� */
int Fibonacci_Search(int *a,int n,int key)
{
	int low,high,mid,i,k=0;
	low=1;						/* �w�q�̧C���ެ��O������ */
	high=n;						/* �w�q�̰����ެ��O������ */
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
				return mid;		/* �Y�۵��h����mid�Y���d�ߨ쪺��m */
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

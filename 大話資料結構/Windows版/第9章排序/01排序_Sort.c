#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* ���������������\����������������/

typedef int Status; 


#define MAXSIZE 10000  /* ���������������V�����ЇR�������*/
typedef struct
{
	int r[MAXSIZE+1];	/* ������������������[0]����������������/
	int length;			/* ���������������� */
}SqList;

/* ��������r�T�ӡ�i���ʳ�/
void swap(SqList *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}

void print(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}

/* ��������������������������*/
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* ����>r[i]��L->r[j]�ʳ�/
			}
		}
	}
}

/* ��������e������ */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* ����j������������*/
		{
			if(L->r[j]>L->r[j+1]) /* ������������������/�������������á�/
			{
				 swap(L,j,j+1);/* ����>r[j]��L->r[j+1]�ʳ�/
			}
		}
	}
}

/* ���������O�ء����Y*/
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag��4��������*/
	for(i=1;i<L->length && flag;i++) /* ��flag��true���ҡ����������䡼������*/
	{
		flag=FALSE;				/* ����False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* ����>r[j]��L->r[j+1]�ʳ�/
				 flag=TRUE;		/* ���񡼡�������flag��true */
			}
		}
	}
}


/* �����������꡼���� */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ����������������������*/
		for (j = i+1;j<=L->length;j++)/* �������� */
        {
			if (L->r[min]>L->r[j])	/* ���񡼡��Z������������ */
                min = j;				/* ���������T�ӡ�����in */
        }
		if(i!=min)						/* ��min�������������k�ա����� */
			swap(L,i,min);				/* ����>r[i]��L->r[min]�ʳ�/
	}
}

/* �������������O���� */
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* ����->r[i]����������*/
		{
			L->r[0]=L->r[i]; /* ��������*/
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* ������ */
			L->r[j+1]=L->r[0]; /* ���������f�� */
		}
	}
}

/* ����������������/
void ShellSort(SqList *L)
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/* ����P */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*  ����->r[i]������������*/ 
			{ 
				L->r[0]=L->r[i]; /*  ������->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ������������� */
				L->r[j+increment]=L->r[0]; /*  ����/
			}
		}
		printf("	�`d����������",++k);
		print(*L);
	}
	while(increment>1);

}


/* �ҡ���******************************** */

/* ����L->r[s..m]�������ڡ���->r[s]�����g���⡼����*/
/* �����ݡ�>r[s]������,��L->r[s..m]�����w����*/
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* ���ڡ������������������� */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j���ڡ���������������*/
		if(temp>=L->r[j])
			break; /* rc�������f��s�� */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* ����/
}

/*  ����������������/
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  �����x�Q�򡼭w����*/
		 HeapAdjust(L,i,L->length);

	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* ����λ�������_�{������P�������֡�����*/
		 HeapAdjust(L,1,i-1); /*  ��->r[1..i-1]�����ݡ����� */
	}
}

/* **************************************** */


/* �ԡ���********************************** */

/* ������SR[i..m]��R[m+1..n]�ԡ�������R[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��R���������ߡ����� */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* ������R[i..m]ū���� */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* ������R[j..n]ū���� */
	}
}


/* ���r */
/* ��R[s..t]�ԡ�����TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ��R[s..t]������[s..m]��R[m+1..t] */
		MSort(SR,TR2,s,m);		/* ���ܡ�R[s..m]�ԡ�������R2[s..m] */
		MSort(SR,TR2,m+1,t);	/* ���ܡ�R[m+1..t]�ԡ�������R2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* ��R2[s..m]��R2[m+1..t]�ԡ�TR1[s..t] */
	}
}

/* ���������ԡ��� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* �����r */
/* ��R[]����Z������������}}�ԡ�TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* }}�ԡ�/
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* �ԡ�������P */
		Merge(SR,TR,i,i+s-1,n);
	else /* �����������lݾ��P */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ���������ԡ����\�� */
void MergeSort2(SqList *L)
{
	int* TR=(int*)malloc(L->length * sizeof(int));/* �����ܡ���*/
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/* ����P��������/
		MergePass(TR,L->r,k,L->length);
		k=2*k;/* ����P��������/       
	}
}

/* **************************************** */

/* ��������****************************** */
 
/* �������������������������������f�����������f�� */
/* ����������(���k�������������� */
int Partition(SqList *L,int low,int high)
{ 
	int pivotkey;

	pivotkey=L->r[low]; /* ������������������������/
	while(low<high) /*  ����}�����L������ */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);/* �����������k���������u*/
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);/* �����������k���������u*/
	}
	return low; /* �_���������f�� */
}

/* ��������������L->r[low..high]����������/
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); /*  ��->r[low..high]����������������pivot */
			QSort(L,low,pivot-1);		/*  �Ρ������X����/
			QSort(L,pivot+1,high);		/*  �񡼡����X����/
	}
}

/* ����������������/
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* **************************************** */

/* �O�`��������****************************** */

/* ������������ */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ���������������T�ӡ�/  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);	/* �����ݡ�̹��������������/
	if (L->r[m]>L->r[high])
		swap(L,high,m);		/* ��������̹��������������/
	if (L->r[m]>L->r[low])
		swap(L,m,low);		/* ��������̹��������������/
	
	pivotkey=L->r[low]; /* ������������������������/
	L->r[0]=pivotkey;  /* �����ڡ�������>r[0] */
	while(low<high) /*  ����}�����L������ */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 L->r[low]=L->r[high];
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low; /* �_���������f�� */
}

void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); /*  ��->r[low..high]����������������pivot */
		QSort1(L,low,pivot-1);		/*  �Ρ������X����/
		QSort1(L,pivot+1,high);		/*  �񡼡����X����/
	}
	else
		InsertSort(L);
}

/* ����������������/
void QuickSort1(SqList *L)
{ 
	QSort1(L,1,L->length);
}

/* �]�����O/
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /*  ��->r[low..high]����������������pivot */
			QSort2(L,low,pivot-1);		/*  �Ρ������X����/
			low=pivot+1;	/* �]�����O/
		}
	}
	else
		InsertSort(L);
}

/* �������������������� */
void QuickSort2(SqList *L)
{ 
	QSort2(L,1,L->length);
}

/* **************************************** */
#define N 9
int main()
{
   int i;
   
   /* int d[N]={9,1,5,8,3,7,4,6,2}; */
   int d[N]={50,10,90,30,70,40,80,60,20};
   /* int d[N]={9,8,7,6,5,4,3,2,1}; */

   SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11;
   
   for(i=0;i<N;i++)
     l0.r[i+1]=d[i];
   l0.length=N;
   l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l11=l0;
   printf("������:\n");
   print(l0);

   printf("���k������:\n");
   BubbleSort0(&l0);
   print(l0);
   
   printf("e������:\n");
   BubbleSort(&l1);
   print(l1);
   
   printf("�O�ء�����:\n");
   BubbleSort2(&l2);
   print(l2);
   
   printf("��������:\n");
   SelectSort(&l3);
   print(l3);
   
   printf("�����O����:\n");
   InsertSort(&l4);
   print(l4);

   printf("��������n");
   ShellSort(&l5);
   print(l5);
	
   printf("�ҡ���n");
   HeapSort(&l6);
   print(l6);

   printf("�ԡ���������:\n");
   MergeSort(&l7);
   print(l7);

   printf("�ԡ�����������:\n");
   MergeSort2(&l8);
   print(l8);

   printf("��������n");
   QuickSort(&l9);
   print(l9);

   printf("�O��������:\n");
   QuickSort1(&l10);
   print(l10);

   printf("�O��������(�]���_\n");
   QuickSort2(&l11);
   print(l11);


    /*��������*/
	/* 
	srand(time(0));  
	int Max=10000;
	int d[10000];
	int i;
	SqList l0;
	for(i=0;i<Max;i++)
		d[i]=rand()%Max+1;
	for(i=0;i<Max;i++)
		l0.r[i+1]=d[i];
	l0.length=Max;
	MergeSort(l0);
	print(l0);
	*/
	return 0;
}

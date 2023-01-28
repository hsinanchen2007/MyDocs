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

#define MAX_LENGTH_INSERT_SORT 7 /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ù\¡¼¡¼¡¼¡¼¡¼¡¼¡¼³ô/

typedef int Status; 


#define MAXSIZE 10000  /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶V¡¼¡¼¤Ð‡R¬î¡¼¡¼¡¼¡¼*/
typedef struct
{
	int r[MAXSIZE+1];	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼[0]¡¼¡¼¡¼¡¼¡¼¡¼¡¼Èà/
	int length;			/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
}SqList;

/* ¡¼¡¼¡¼¡¼rßT¡Ó¡¼i¡¼ºÊ³ô/
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

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼®ó¡¼*/
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* ¡¼¡¼>r[i]¡¼L->r[j]ºÊ³ô/
			}
		}
	}
}

/* ¡¼¡¼¡¼¡¼e¡¼¡¼¡¼ */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* ¡¼¡¼j¡¼¡¼¡¼¡¼¡¼¡¼*/
		{
			if(L->r[j]>L->r[j+1]) /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/¡¼¡¼¡¼¡¼´þ¡¼Ã¡¼/
			{
				 swap(L,j,j+1);/* ¡¼¡¼>r[j]¡¼L->r[j+1]ºÊ³ô/
			}
		}
	}
}

/* ¡¼¡¼¡¼¡¼ÛO¯Ø¡¼¡¼¸Y*/
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag¡¼4¡¼¡¼¡¼¡¼*/
	for(i=1;i<L->length && flag;i++) /* ¡¼flag¡¼true¡¼¡Ò¡¼»ô¡¼¡¼¡¼õä¡¼¡¼¡¼¡¼*/
	{
		flag=FALSE;				/* ¡¼¡¼False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* ¡¼¡¼>r[j]¡¼L->r[j+1]ºÊ³ô/
				 flag=TRUE;		/* ¡¼èñ¡¼¡¼¡¼¡¼¡¼flag¡¼true */
			}
		}
	}
}


/* ¡¼¡¼¡¼¡¼¡¼Ëê¡¼¡¼¡¼ */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		for (j = i+1;j<=L->length;j++)/* ¡¼¡¼ úäñ¡¼ */
        {
			if (L->r[min]>L->r[j])	/* ¡¼èñ¡¼¡¼ÌZ¡¼¡¼¡¼õÁ¡¼¡¼ */
                min = j;				/* ¡¼¡¼¡¼¡¼ßT¡Ó¡¼¡¼¡¼in */
        }
		if(i!=min)						/* ¡¼min¡¼¡¼¡¼¡¼¡¼¡¼±kÕ¡¼¡¼¡¼ */
			swap(L,i,min);				/* ¡¼¡¼>r[i]¡¼L->r[min]ºÊ³ô/
	}
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼§O¡¼¡¼ */
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* ¡¼¡¼->r[i]¡¼¡¼¡¼¡¼¡¼*/
		{
			L->r[0]=L->r[i]; /* ¡¼¡¼¡¼¡¼*/
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* ¡¼¡¼¡¼ */
			L->r[j+1]=L->r[0]; /* ¡¼¡¼¡¼¡¼£f¡¼ */
		}
	}
}

/* ¡¼¡¼¡¼¡¼¡¼·À¡¼¡¼/
void ShellSort(SqList *L)
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/* ¡¼¡¼P */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*  ¡¼¡¼->r[i]¡¼¡¼¡¼¡¼¡¼¡¼*/ 
			{ 
				L->r[0]=L->r[i]; /*  ¡¼¡¼¡¼->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ¡¼¡¼¡¼¡¼Âï¡¼¡¼¡¼ */
				L->r[j+increment]=L->r[0]; /*  ¡¼¡¼/
			}
		}
		printf("	Ã`d¡¼¡¼¡¼¡¼¡¼",++k);
		print(*L);
	}
	while(increment>1);

}


/* ïÒ¡¼¡¼******************************** */

/* ¡¼¡¼L->r[s..m]¡¼¡¼¡¼ÍÚ¡¼¡¼->r[s]¡¼¡¼ g¡¼áâ¡¼¡¼¡¼*/
/* ¡¼‡¹öÝ¡¼>r[s]õÁ¡¼¡¼,¡¼L->r[s..m]¡¼¡¼­w¡¼áë*/
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* ¡¼ÍÚ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j¡¼ÍÚ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		if(temp>=L->r[j])
			break; /* rc¡¼¡¼¡¼£f¡¼s¡¼ */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* ¡¼¡¼/
}

/*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  ¡¼¡¼ÀxÆQ«ò¡¼­w¡¼áë*/
		 HeapAdjust(L,i,L->length);

	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* ¡¼¡¼Î»¡¼¡¼¡¼£_›{¡¼¡¼¡¼Pèö ú¡¼×Ö¡¼¡¼¡¼*/
		 HeapAdjust(L,1,i-1); /*  ¡¼->r[1..i-1]¡¼¡¼öÝ¡¼¡¼¡¼ */
	}
}

/* **************************************** */


/* äÔ¡¼¡¼********************************** */

/* ¡¼¡¼¡¼SR[i..m]¡¼R[m+1..n]äÔ¡¼¡¼¡¼¾©R[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ¡¼R¡¼¡¼¡¼¡¼Éß¡¼¡¼¡¼ */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* ¡¼¡¼èõR[i..m]Å«¡¼¡¼ */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* ¡¼¡¼èõR[j..n]Å«¡¼¡¼ */
	}
}


/* ¥Þør */
/* ¡¼R[s..t]äÔ¡¼¡¼¡¼TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ¡¼R[s..t]¡¼²¨¡¼[s..m]¡¼R[m+1..t] */
		MSort(SR,TR2,s,m);		/* ¥ÞñÜ¡¼R[s..m]äÔ¡¼¡¼¡¼¾©R2[s..m] */
		MSort(SR,TR2,m+1,t);	/* ¥ÞñÜ¡¼R[m+1..t]äÔ¡¼¡¼¡¼¾©R2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* ¡¼R2[s..m]¡¼R2[m+1..t]äÔ¡¼TR1[s..t] */
	}
}

/* ¡¼¡¼¡¼¡¼äÔ¡¼¡¼ */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* ¡¼¡¼ør */
/* ¡¼R[]¡¼¡¼Z¡¼¡¼¡¼¡¼¡¼¡¼}}äÔ¡¼TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* }}äÔ¡¼/
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* äÔ¡¼¡¼¡¼¡¼P */
		Merge(SR,TR,i,i+s-1,n);
	else /* ¡¼¡¼¡¼¡¼¡¼¦lÝ¾¡¼P */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ¡¼¡¼¡¼¡¼äÔ¡¼¥Þö\¡¼ */
void MergeSort2(SqList *L)
{
	int* TR=(int*)malloc(L->length * sizeof(int));/* ¡¼¡¼ÕÜ¡¼¡¼*/
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/* ¡¼¡¼P¡¼¡¼¡¼®è/
		MergePass(TR,L->r,k,L->length);
		k=2*k;/* ¡¼¡¼P¡¼¡¼¡¼®è/       
	}
}

/* **************************************** */

/* ¡¼¡¼¡¼¡¼****************************** */
 
/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼£f¡¼¡¼¡¼¡¼¡¼£f¡¼ */
/* ¡¼¡¼¡¼¡¼¡¼(¡¼Åk¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
int Partition(SqList *L,int low,int high)
{ 
	int pivotkey;

	pivotkey=L->r[low]; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	while(low<high) /*  ¡¼¡¼}«û¡¼áL¡¼¡¼¡¼ */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);/* ¡¼¡¼¡¼¡¼¡¼Åk¡¼¡¼¡¼¡¼Õu*/
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);/* ¡¼¡¼¡¼¡¼¡¼Åk¡¼¡¼¡¼¡¼Õu*/
	}
	return low; /* ß_¡¼¡¼¡¼¡¼£f¡¼ */
}

/* ¡¼¡¼¡¼¡¼èö¡¼¡¼L->r[low..high]¡¼¡¼¡¼¡¼¡¼/
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); /*  ¡¼->r[low..high]¡¼²¨¡¼¡¼¡¼¡¼¡¼¡¼pivot */
			QSort(L,low,pivot-1);		/*  ‹Î¡¼¡¼¡¼ÅX¡¼¡¼/
			QSort(L,pivot+1,high);		/*  §ñ¡¼¡¼¡¼ÅX¡¼¡¼/
	}
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* **************************************** */

/* ÛO°`¡¼¡¼¡¼¡¼****************************** */

/* ¡¼¡¼¡¼¡¼¡¼¡¼ */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ßT¡Ó¡¼/  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);	/* ¡¼¡¼©Ý¡¼Ì¹¡¼¡¼¡¼¡¼«û¡¼¡¼/
	if (L->r[m]>L->r[high])
		swap(L,high,m);		/* ¡¼¡¼¡¼¡¼Ì¹¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	if (L->r[m]>L->r[low])
		swap(L,m,low);		/* ¡¼¡¼¡¼¡¼Ì¹¡¼¡¼¡¼¡¼«û¡¼¡¼/
	
	pivotkey=L->r[low]; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	L->r[0]=pivotkey;  /* ¡¼¡¼ÍÚ¡¼¡¼¡¼¡¼>r[0] */
	while(low<high) /*  ¡¼¡¼}«û¡¼áL¡¼¡¼¡¼ */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 L->r[low]=L->r[high];
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low; /* ß_¡¼¡¼¡¼¡¼£f¡¼ */
}

void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); /*  ¡¼->r[low..high]¡¼²¨¡¼¡¼¡¼¡¼¡¼¡¼pivot */
		QSort1(L,low,pivot-1);		/*  ‹Î¡¼¡¼¡¼ÅX¡¼¡¼/
		QSort1(L,pivot+1,high);		/*  §ñ¡¼¡¼¡¼ÅX¡¼¡¼/
	}
	else
		InsertSort(L);
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
void QuickSort1(SqList *L)
{ 
	QSort1(L,1,L->length);
}

/* £]¥ÞÃþ§O/
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /*  ¡¼->r[low..high]¡¼²¨¡¼¡¼¡¼¡¼¡¼¡¼pivot */
			QSort2(L,low,pivot-1);		/*  ‹Î¡¼¡¼¡¼ÅX¡¼¡¼/
			low=pivot+1;	/* £]¥ÞÃþ§O/
		}
	}
	else
		InsertSort(L);
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ùÂ */
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
   printf("¡¼¡¼¡¼:\n");
   print(l0);

   printf("¡¼´k¡¼¡¼¡¼:\n");
   BubbleSort0(&l0);
   print(l0);
   
   printf("e¡¼¡¼¡¼:\n");
   BubbleSort(&l1);
   print(l1);
   
   printf("ÛO¯Ø¡¼¡¼¡¼:\n");
   BubbleSort2(&l2);
   print(l2);
   
   printf("¡¼¡¼¡¼¡¼:\n");
   SelectSort(&l3);
   print(l3);
   
   printf("¡¼¡¼§O¡¼¡¼:\n");
   InsertSort(&l4);
   print(l4);

   printf("¡¼·À¡¼¡¼n");
   ShellSort(&l5);
   print(l5);
	
   printf("ïÒ¡¼¡¼n");
   HeapSort(&l6);
   print(l6);

   printf("äÔ¡¼¡¼¡¼¡¼¶»:\n");
   MergeSort(&l7);
   print(l7);

   printf("äÔ¡¼¡¼¡¼¡¼¡¼¶»:\n");
   MergeSort2(&l8);
   print(l8);

   printf("¡¼¡¼¡¼¡¼n");
   QuickSort(&l9);
   print(l9);

   printf("ÛO©¹£»¡¼¡¼:\n");
   QuickSort1(&l10);
   print(l10);

   printf("ÛO©¹£»¡¼¡¼(£]¥Þõ_\n");
   QuickSort2(&l11);
   print(l11);


    /*¡¼¡¼¡¼¡¼*/
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

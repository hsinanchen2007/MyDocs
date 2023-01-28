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

#define MAX_LENGTH_INSERT_SORT 7 /* �Ω�ֳt�ƧǮɧP�_�O�_��δ��J�Ƨ����� */

typedef int Status; 


#define MAXSIZE 10000  /* �Ω�n�Ƨǰ}�C�ӼƳ̤j�ȡA�i�ھڻݭn�ק� */
typedef struct
{
	int r[MAXSIZE+1];	/* �Ω��x�s�n�Ƨǰ}�C�Ar[0]�Χ@��L���{���ܼ� */
	int length;			/* �Ω�O���`�Ǧ�C������ */
}SqList;

/* �洫L���}�Cr�����ެ�i�Mj���� */
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

/* ��`�Ǧ�CL�@�洫�Ƨǡ]�Ϫ@�ƧǪ�Ū��^ */
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* �洫L->r[i]�PL->r[j]���� */
			}
		}
	}
}

/* ��`�Ǧ�CL�@�Ϫ@�Ƨ� */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* �`�Nj�O�q�᩹�e�`�� */
		{
			if(L->r[j]>L->r[j+1]) /* �Y�e�̤j���̡]�`�N�o�̻P�W�@��k���t���^*/
			{
				 swap(L,j,j+1);/* �洫L->r[j]�PL->r[j+1]���� */
			}
		}
	}
}

/* ��`�Ǧ�CL�@��i�Ϫ@��k */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag�Ψӧ@���Х� */
	for(i=1;i<L->length && flag;i++) /* �Yflag��true�������L��ƥ洫�A�_�h����`�� */
	{
		flag=FALSE;				/* �_�l��False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* �洫L->r[j]�PL->r[j+1]���� */
				 flag=TRUE;		/* �Y�G����ƥ洫�A�hflag��true */
			}
		}
	}
}


/* ��`�Ǧ�CL�@²�����Ƨ� */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* �N�ثe���ީw�q���̤p�ȯ��� */
		for (j = i+1;j<=L->length;j++)/* �`�����᪺��� */
        {
			if (L->r[min]>L->r[j])	/* �Y�G���p��ثe�̤p�Ȫ�����r */
                min = j;				/* �N������r�����޵����ȵ�min */
        }
		if(i!=min)						/* �Ymin������i�A�������̤p�ȡA�洫 */
			swap(L,i,min);				/* �洫L->r[i]�PL->r[min]���� */
	}
}

/* ��`�Ǧ�CL�@�������J�Ƨ� */
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* �ݱNL->r[i]���J���Ǥl�� */
		{
			L->r[0]=L->r[i]; /* �]�w��L */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* �O���Ჾ */
			L->r[j+1]=L->r[0]; /* ���J�쥿�T��m */
		}
	}
}

/* ��`�Ǧ�CL�@�ƺ��Ƨ� */
void ShellSort(SqList *L)
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/* �W�q�ǦC */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*  �ݱNL->r[i]���J���ǼW�q�l�� */ 
			{ 
				L->r[0]=L->r[i]; /*  �Ȧs�bL->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  �O���Ჾ�A�d�ߴ��J��m */
				L->r[j+increment]=L->r[0]; /*  ���J */
			}
		}
		printf("	��%d��Ƨǵ��G: ",++k);
		print(*L);
	}
	while(increment>1);

}


/* ��Ƨ�********************************** */

/* �w��L->r[s..m]���O��������r��L->r[s]���~�������諸�w�q�A */
/* ����ƽվ�L->r[s]������r,��L->r[s..m]�����@�Ӥj���� */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* �u����r���j���Ĥl�`�I�V�U�z�� */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j������r�����j���O�������� */
		if(temp>=L->r[j])
			break; /* rc�����J�b��ms�W */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* ���J */
}

/*  ��`�Ǧ�CL�i���Ƨ� */
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  ��L����r�غc���@�Ӥj���� */
		 HeapAdjust(L,i,L->length);

	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* �N�ﳻ�O���M�ثe���g�ƧǤl�ǦC���̫�@�ӰO���洫 */
		 HeapAdjust(L,1,i-1); /*  �NL->r[1..i-1]���s�վ㬰�j���� */
	}
}

/* **************************************** */


/* �k�ñƧ�********************************** */

/* �N���Ǫ�SR[i..m]�MSR[m+1..n]�k�ì����Ǫ�TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* �NSR���O���Ѥp��j�a�äJTR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* �N�ѧE��SR[i..m]�ƻs��TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* �N�ѧE��SR[j..n]�ƻs��TR */
	}
}


/* ���k�k */
/* �NSR[s..t]�k�ñƧǬ�TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* �NSR[s..t]������SR[s..m]�MSR[m+1..t] */
		MSort(SR,TR2,s,m);		/* ���k�a�NSR[s..m]�k�ì����Ǫ�TR2[s..m] */
		MSort(SR,TR2,m+1,t);	/* ���k�a�NSR[m+1..t]�k�ì����Ǫ�TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* �NTR2[s..m]�MTR2[m+1..t]�k�è�TR1[s..t] */
	}
}

/* ��`�Ǧ�CL�@�k�ñƧ� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* �D���k�k */
/* �NSR[]���۾F���׬�s���l�ǦC����k�è�TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* ����k�� */
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* �k�ó̫��ӧǦC */
		Merge(SR,TR,i,i+s-1,n);
	else /* �Y�̫�u�ѤU��@�l�ǦC */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ��`�Ǧ�CL�@�k�ëD���k�Ƨ� */
void MergeSort2(SqList *L)
{
	int* TR=(int*)malloc(L->length * sizeof(int));/* �ӽ��B�~�Ŷ� */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/* �l�ǦC���ץ[�� */
		MergePass(TR,L->r,k,L->length);
		k=2*k;/* �l�ǦC���ץ[�� */       
	}
}

/* **************************************** */

/* �ֳt�Ƨ�******************************** */
 
/* �洫�`�Ǧ�CL���l���O���A�ϼ϶b�O���X��A�öǦ^��Ҧb��m */
/* ���ɦb�����e(��)���O�������j(�p)�󥦡C */
int Partition(SqList *L,int low,int high)
{ 
	int pivotkey;

	pivotkey=L->r[low]; /* �Τl���Ĥ@�ӰO���@�϶b�O�� */
	while(low<high) /*  �q����ݥ���a�V�������y */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);/* �N��϶b�O���p���O���洫��C�� */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);/* �N��϶b�O���j���O���洫�찪�� */
	}
	return low; /* �Ǧ^�϶b�Ҧb��m */
}

/* ��`�Ǧ�CL�����l�ǦCL->r[low..high]�@�ֳt�Ƨ� */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); /*  �NL->r[low..high]�@�����G�A��X�϶b��pivot */
			QSort(L,low,pivot-1);		/*  ��C�l���k�Ƨ� */
			QSort(L,pivot+1,high);		/*  �ﰪ�l���k�Ƨ� */
	}
}

/* ��`�Ǧ�CL�@�ֳt�Ƨ� */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* **************************************** */

/* ��i��ֳt�Ƨ�******************************** */

/* �ֳt�Ƨǧﵽ��k */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* �p��}�C���������������� */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);	/* �洫���ݻP�k�ݸ�ơA�T�O���ݸ��p */
	if (L->r[m]>L->r[high])
		swap(L,high,m);		/* �洫�����P�k�ݸ�ơA�T�O�������p */
	if (L->r[m]>L->r[low])
		swap(L,m,low);		/* �洫�����P���ݸ�ơA�T�O���ݸ��p */
	
	pivotkey=L->r[low]; /* �Τl���Ĥ@�ӰO���@�϶b�O�� */
	L->r[0]=pivotkey;  /* �N�϶b����r�ƥ���L->r[0] */
	while(low<high) /*  �q����ݥ���a�V�������y */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 L->r[low]=L->r[high];
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low; /* �Ǧ^�϶b�Ҧb��m */
}

void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); /*  �NL->r[low..high]�@�����G�A��X�϶b��pivot */
		QSort1(L,low,pivot-1);		/*  ��C�l���k�Ƨ� */
		QSort1(L,pivot+1,high);		/*  �ﰪ�l���k�Ƨ� */
	}
	else
		InsertSort(L);
}

/* ��`�Ǧ�CL�@�ֳt�Ƨ� */
void QuickSort1(SqList *L)
{ 
	QSort1(L,1,L->length);
}

/* �����k */
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /*  �NL->r[low..high]�@�����G�A��X�϶b��pivot */
			QSort2(L,low,pivot-1);		/*  ��C�l���k�Ƨ� */
			low=pivot+1;	/* �����k */
		}
	}
	else
		InsertSort(L);
}

/* ��`�Ǧ�CL�@�ֳt�Ƨ�(�����k) */
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
   printf("�Ƨǫe:\n");
   print(l0);

   printf("��ŤϪ@�Ƨ�:\n");
   BubbleSort0(&l0);
   print(l0);
   
   printf("�Ϫ@�Ƨ�:\n");
   BubbleSort(&l1);
   print(l1);
   
   printf("��i�Ϫ@�Ƨ�:\n");
   BubbleSort2(&l2);
   print(l2);
   
   printf("����Ƨ�:\n");
   SelectSort(&l3);
   print(l3);
   
   printf("�������J�Ƨ�:\n");
   InsertSort(&l4);
   print(l4);

   printf("�ƺ��Ƨ�:\n");
   ShellSort(&l5);
   print(l5);
	
   printf("��Ƨ�:\n");
   HeapSort(&l6);
   print(l6);

   printf("�k�ñƧǡ]���k�^:\n");
   MergeSort(&l7);
   print(l7);

   printf("�k�ñƧǡ]�D���k�^:\n");
   MergeSort2(&l8);
   print(l8);

   printf("�ֳt�Ƨ�:\n");
   QuickSort(&l9);
   print(l9);

   printf("��i�ֳt�Ƨ�:\n");
   QuickSort1(&l10);
   print(l10);

   printf("��i�ֳt�Ƨ�(�����k):\n");
   QuickSort2(&l11);
   print(l11);


    /*�j��ƱƧ�*/
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

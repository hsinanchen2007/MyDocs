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

#define MAX_LENGTH_INSERT_SORT 7 /* 用於快速排序時判斷是否選用插入排序闕值 */

typedef int Status; 


#define MAXSIZE 10000  /* 用於要排序陣列個數最大值，可根據需要修改 */
typedef struct
{
	int r[MAXSIZE+1];	/* 用於儲存要排序陣列，r[0]用作哨兵或臨時變數 */
	int length;			/* 用於記錄循序串列的長度 */
}SqList;

/* 交換L中陣列r的索引為i和j的值 */
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

/* 對循序串列L作交換排序（反昇排序初級版） */
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* 交換L->r[i]與L->r[j]的值 */
			}
		}
	}
}

/* 對循序串列L作反昇排序 */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* 注意j是從後往前循環 */
		{
			if(L->r[j]>L->r[j+1]) /* 若前者大於後者（注意這裡與上一算法的差異）*/
			{
				 swap(L,j,j+1);/* 交換L->r[j]與L->r[j+1]的值 */
			}
		}
	}
}

/* 對循序串列L作改進反昇算法 */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag用來作為標示 */
	for(i=1;i<L->length && flag;i++) /* 若flag為true說明有過資料交換，否則停止循環 */
	{
		flag=FALSE;				/* 起始為False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* 交換L->r[j]與L->r[j+1]的值 */
				 flag=TRUE;		/* 若果有資料交換，則flag為true */
			}
		}
	}
}


/* 對循序串列L作簡單選取排序 */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* 將目前索引定義為最小值索引 */
		for (j = i+1;j<=L->length;j++)/* 循環之後的資料 */
        {
			if (L->r[min]>L->r[j])	/* 若果有小於目前最小值的關鍵字 */
                min = j;				/* 將此關鍵字的索引給予值給min */
        }
		if(i!=min)						/* 若min不等於i，說明找到最小值，交換 */
			swap(L,i,min);				/* 交換L->r[i]與L->r[min]的值 */
	}
}

/* 對循序串列L作直接插入排序 */
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* 需將L->r[i]插入有序子表 */
		{
			L->r[0]=L->r[i]; /* 設定哨兵 */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* 記錄後移 */
			L->r[j+1]=L->r[0]; /* 插入到正確位置 */
		}
	}
}

/* 對循序串列L作希爾排序 */
void ShellSort(SqList *L)
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;/* 增量序列 */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])/*  需將L->r[i]插入有序增量子表 */ 
			{ 
				L->r[0]=L->r[i]; /*  暫存在L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  記錄後移，查詢插入位置 */
				L->r[j+increment]=L->r[0]; /*  插入 */
			}
		}
		printf("	第%d趟排序結果: ",++k);
		print(*L);
	}
	while(increment>1);

}


/* 堆排序********************************** */

/* 已知L->r[s..m]中記錄的關鍵字除L->r[s]之外均滿足堆的定義， */
/* 本函數調整L->r[s]的關鍵字,使L->r[s..m]成為一個大頂堆 */
void HeapAdjust(SqList *L,int s,int m)
{ 
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) /* 沿關鍵字較大的孩子節點向下篩選 */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; /* j為關鍵字中較大的記錄的索引 */
		if(temp>=L->r[j])
			break; /* rc應插入在位置s上 */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* 插入 */
}

/*  對循序串列L進行堆排序 */
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  把L中的r建構成一個大頂堆 */
		 HeapAdjust(L,i,L->length);

	for(i=L->length;i>1;i--)
	{ 
		 swap(L,1,i); /* 將堆頂記錄和目前未經排序子序列的最後一個記錄交換 */
		 HeapAdjust(L,1,i-1); /*  將L->r[1..i-1]重新調整為大頂堆 */
	}
}

/* **************************************** */


/* 歸並排序********************************** */

/* 將有序的SR[i..m]和SR[m+1..n]歸並為有序的TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* 將SR中記錄由小到大地並入TR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* 將剩余的SR[i..m]複製到TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* 將剩余的SR[j..n]複製到TR */
	}
}


/* 遞歸法 */
/* 將SR[s..t]歸並排序為TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* 將SR[s..t]平分為SR[s..m]和SR[m+1..t] */
		MSort(SR,TR2,s,m);		/* 遞歸地將SR[s..m]歸並為有序的TR2[s..m] */
		MSort(SR,TR2,m+1,t);	/* 遞歸地將SR[m+1..t]歸並為有序的TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* 將TR2[s..m]和TR2[m+1..t]歸並到TR1[s..t] */
	}
}

/* 對循序串列L作歸並排序 */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* 非遞歸法 */
/* 將SR[]中相鄰長度為s的子序列兩兩歸並到TR[] */
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* 兩兩歸並 */
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* 歸並最後兩個序列 */
		Merge(SR,TR,i,i+s-1,n);
	else /* 若最後只剩下單一子序列 */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* 對循序串列L作歸並非遞歸排序 */
void MergeSort2(SqList *L)
{
	int* TR=(int*)malloc(L->length * sizeof(int));/* 申請額外空間 */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;/* 子序列長度加倍 */
		MergePass(TR,L->r,k,L->length);
		k=2*k;/* 子序列長度加倍 */       
	}
}

/* **************************************** */

/* 快速排序******************************** */
 
/* 交換循序串列L中子表的記錄，使樞軸記錄合格，並傳回其所在位置 */
/* 此時在它之前(後)的記錄均不大(小)於它。 */
int Partition(SqList *L,int low,int high)
{ 
	int pivotkey;

	pivotkey=L->r[low]; /* 用子表的第一個記錄作樞軸記錄 */
	while(low<high) /*  從表的兩端交替地向中間掃描 */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);/* 將比樞軸記錄小的記錄交換到低端 */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);/* 將比樞軸記錄大的記錄交換到高階 */
	}
	return low; /* 傳回樞軸所在位置 */
}

/* 對循序串列L中的子序列L->r[low..high]作快速排序 */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); /*  將L->r[low..high]一分為二，算出樞軸值pivot */
			QSort(L,low,pivot-1);		/*  對低子表遞歸排序 */
			QSort(L,pivot+1,high);		/*  對高子表遞歸排序 */
	}
}

/* 對循序串列L作快速排序 */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* **************************************** */

/* 改進後快速排序******************************** */

/* 快速排序改善算法 */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* 計算陣列中間的元素的索引 */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);	/* 交換左端與右端資料，確保左端較小 */
	if (L->r[m]>L->r[high])
		swap(L,high,m);		/* 交換中間與右端資料，確保中間較小 */
	if (L->r[m]>L->r[low])
		swap(L,m,low);		/* 交換中間與左端資料，確保左端較小 */
	
	pivotkey=L->r[low]; /* 用子表的第一個記錄作樞軸記錄 */
	L->r[0]=pivotkey;  /* 將樞軸關鍵字備份到L->r[0] */
	while(low<high) /*  從表的兩端交替地向中間掃描 */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 L->r[low]=L->r[high];
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low; /* 傳回樞軸所在位置 */
}

void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); /*  將L->r[low..high]一分為二，算出樞軸值pivot */
		QSort1(L,low,pivot-1);		/*  對低子表遞歸排序 */
		QSort1(L,pivot+1,high);		/*  對高子表遞歸排序 */
	}
	else
		InsertSort(L);
}

/* 對循序串列L作快速排序 */
void QuickSort1(SqList *L)
{ 
	QSort1(L,1,L->length);
}

/* 尾遞歸 */
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /*  將L->r[low..high]一分為二，算出樞軸值pivot */
			QSort2(L,low,pivot-1);		/*  對低子表遞歸排序 */
			low=pivot+1;	/* 尾遞歸 */
		}
	}
	else
		InsertSort(L);
}

/* 對循序串列L作快速排序(尾遞歸) */
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
   printf("排序前:\n");
   print(l0);

   printf("初級反昇排序:\n");
   BubbleSort0(&l0);
   print(l0);
   
   printf("反昇排序:\n");
   BubbleSort(&l1);
   print(l1);
   
   printf("改進反昇排序:\n");
   BubbleSort2(&l2);
   print(l2);
   
   printf("選取排序:\n");
   SelectSort(&l3);
   print(l3);
   
   printf("直接插入排序:\n");
   InsertSort(&l4);
   print(l4);

   printf("希爾排序:\n");
   ShellSort(&l5);
   print(l5);
	
   printf("堆排序:\n");
   HeapSort(&l6);
   print(l6);

   printf("歸並排序（遞歸）:\n");
   MergeSort(&l7);
   print(l7);

   printf("歸並排序（非遞歸）:\n");
   MergeSort2(&l8);
   print(l8);

   printf("快速排序:\n");
   QuickSort(&l9);
   print(l9);

   printf("改進快速排序:\n");
   QuickSort1(&l10);
   print(l10);

   printf("改進快速排序(尾遞歸):\n");
   QuickSort2(&l11);
   print(l11);


    /*大資料排序*/
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

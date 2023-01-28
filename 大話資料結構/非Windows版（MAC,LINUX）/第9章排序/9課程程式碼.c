


#define MAXSIZE 10000  	/* 用於要排序陣列個數最大值，可根據需要修改 */
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
				 swap(L,i,j);	/* 交換L->r[i]與L->r[j]的值 */
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
		for(j=L->length-1;j>=i;j--) /* 注意j是從後往前循環 */
		{
			if(L->r[j]>L->r[j+1]) 	/* 若前者大於後者（注意這裡與上一算法的差異）*/
			{
				 swap(L,j,j+1);		/* 交換L->r[j]與L->r[j+1]的值 */
			}
		}
	}
}

/* 對循序串列L作改進反昇算法 */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;					/* flag用來作為標示 */
	for(i=1;i<L->length && flag;i++) 	/* 若flag為true有資料交換，否則離開循環 */
	{
		flag=FALSE;						/* 起始為False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);			/* 交換L->r[j]與L->r[j+1]的值 */
				flag=TRUE;				/* 若果有資料交換，則flag為true */
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
		for (j = i+1;j<=L->length;j++)	/* 循環之後的資料 */
        {
			if (L->r[min]>L->r[j])		/* 若果有小於目前最小值的關鍵字 */
                min = j;				/* 將此關鍵字的索引給予值給min */
        }
		if(i!=min)						/* 若min不等於i，說明找到最小值，交換 */
			swap(L,i,min);				/* 交換L->r[i]與L->r[min]的值 */
	}
}

void InsertSort(SqList *L) 			/* 對循序串列L作直接插入排序 */
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) 		/* 需將L->r[i]插入有序子表 */
		{
			L->r[0]=L->r[i]; 		/* 設定哨兵 */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; 	/* 記錄後移 */
			L->r[j+1]=L->r[0]; 		/* 插入到正確位置 */
		}
	}
}

void ShellSort(SqList *L) 					/* 對循序串列L作希爾排序 */
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;			/* 增量序列 */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])	/* 需將L->r[i]插入有序增量子表 */ 
			{ 
				L->r[0]=L->r[i]; 			/* 暫存在L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  記錄後移，查詢插入位置 */
				L->r[j+increment]=L->r[0]; 	/*  插入 */
			}
		}
	}
	while(increment>1);
}



void HeapSort(SqList *L)		/* 對循序串列L進行堆排序 */
{
	int i;
	for(i=L->length/2;i>0;i--) 	/* 把L中的r建構成一個大頂堆 */
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{ 
		swap(L,1,i); 			/* 將堆頂記錄和目前未經排序子序列最後一記錄交換 */
		HeapAdjust(L,1,i-1); 	/* 將L->r[1..i-1]重新調整為大頂堆 */
	}
}

void HeapAdjust(SqList *L,int s,int m)
{ /* 本函數調整L->r[s]的關鍵字，使L->r[s..m]成為一個大頂堆 */
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) 	/* 沿關鍵字較大的孩子節點向下篩選 */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; 			/* j為關鍵字中較大的記錄的索引 */
		if(temp>=L->r[j])
			break; 			/* rc應插入在位置s上 */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; 			/* 插入 */
}

/* 對循序串列L作歸並排序 */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

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


void Merge(int SR[],int TR[],int i,int m,int n)
{ /* 將有序的SR[i..m]和SR[m+1..n]歸並為有序的TR[i..n] */
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


void MergeSort2(SqList *L) 				 /* 對循序串列L作歸並非遞歸排序 */
{
	int* TR=(int*)malloc(L->length * sizeof(int));	/* 申請額外空間 */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;										/* 子序列長度加倍 */
		MergePass(TR,L->r,k,L->length);
		k=2*k;										/* 子序列長度加倍 */       
	}
}


void MergePass(int SR[],int TR[],int s,int n)
{/* 將SR[]中相鄰長度為s的子序列兩兩歸並到TR[] */
	int i=1;
	int j;
	while(i <= n-2*s+1)					/* 兩兩歸並 */
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) 						/* 歸並最後兩個序列 */
		Merge(SR,TR,i,i+s-1,n);
	else 								/* 若最後只剩下單一子序列 */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* 對循序串列L作快速排序 */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* 對循序串列L中的子序列L->r[low..high]作快速排序 */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
		/* 將L->r[low..high]一分為二，算出樞軸值pivot */
		pivot=Partition(L,low,high); 
		QSort(L,low,pivot-1);		 /*  對低子表遞歸排序 */
		QSort(L,pivot+1,high);		 /*  對高子表遞歸排序 */
	}
}

int Partition(SqList *L,int low,int high)
{/* 交換循序串列L中子表的記錄，使樞軸記錄合格，並傳回其所在位置，此時在它之前(後)均不大(小)於它。*/
	int pivotkey;

	pivotkey=L->r[low]; 	/* 用子表的第一個記錄作樞軸記錄 */
	while(low<high) 		/* 從表的兩端交替地向中間掃描 */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);	/* 將比樞軸記錄小的記錄交換到低端 */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);	/* 將比樞軸記錄大的記錄交換到高階 */
	}
	return low; 			/* 傳回樞軸所在位置 */
}

int pivotkey;

int m = low + (high - low) / 2; 	/* 計算陣列中間的元素的索引 */  
if (L->r[low]>L->r[high])			
	swap(L,low,high);				/* 交換左端與右端資料，確保左端較小 */
if (L->r[m]>L->r[high])
	swap(L,high,m);					/* 交換中間與右端資料，確保中間較小 */
if (L->r[m]>L->r[low])
	swap(L,m,low);					/* 交換中間與左端資料，確保左端較小 */

/* 此時L.r[low]已經為整個序列左中右三個關鍵字的中間值。*/

pivotkey=L->r[low]; 				/* 用子表的第一個記錄作樞軸記錄 */

/* 快速排序改善算法 */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* 計算陣列中間的元素的索引 */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);			/* 交換左端與右端資料，確保左端較小 */
	if (L->r[m]>L->r[high])
		swap(L,high,m);				/* 交換中間與右端資料，確保中間較小 */
	if (L->r[m]>L->r[low])
		swap(L,m,low);				/* 交換中間與左端資料，確保左端較小 */
	
	pivotkey=L->r[low]; 			/* 用子表的第一個記錄作樞軸記錄 */
	L->r[0]=pivotkey;  				/* 將樞軸關鍵字備份到L->r[0] */
	while(low<high) 				/*  從表的兩端交替地向中間掃描 */
	{ 
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];		/* 采用置換而不是交換的模式進行動作 */
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];		/* 采用置換而不是交換的模式進行動作 */
	}
	L->r[low]=L->r[0];				/* 將樞軸數值置換回L.r[low] */
	return low; 					/* 傳回樞軸所在位置 */
}

#define MAX_LENGTH_INSERT_SORT 7 /* 用於快速排序時判斷是否選用插入排序闕值 */
/* 對循序串列L中的子序列L.r[low..high]作快速排序 */
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); 	/* 將L->r[low..high]一分為二，算出樞軸值pivot */
		QSort1(L,low,pivot-1);			/* 對低子表遞歸排序 */
		QSort1(L,pivot+1,high);			/* 對高子表遞歸排序 */
	}
	else
		InsertSort(L);					/* 當high-low小於等於常量時用直接插入排序 */
}

/* 尾遞歸 */
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /* 將L->r[low..high]一分為二，算出樞軸值pivot */
			QSort2(L,low,pivot-1);		/* 對低子表遞歸排序 */
			low=pivot+1;				/* 尾遞歸 */
		}
	}
	else
		InsertSort(L);					/* 當high-low小於等於常量時用直接插入排序 */
}





#define MAXSIZE 10000  	/* ーーーーーーー�Vーーば�R�遏次次次�*/
typedef struct
{
	int r[MAXSIZE+1];	/* ーーーーーーーーー[0]ーーーーーーー彼/
	int length;			/* ーーーーーーーー */
}SqList;


/* ーーーーr�T〉ーiー妻株/
void swap(SqList *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}

/* ーーーーーーーーーーーー�鵝�*/
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);	/* ーー>r[i]ーL->r[j]妻株/
			}
		}
	}
}

/* ーーーーeーーー */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--) /* ーーjーーーーーー*/
		{
			if(L->r[j]>L->r[j+1]) 	/* ーーーーーーーーー/ーーーー棄ー�叩�/
			{
				 swap(L,j,j+1);		/* ーー>r[j]ーL->r[j+1]妻株/
			}
		}
	}
}

/* ーーーー�O�悄次叱Y*/
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;					/* flagー4ーーーー*/
	for(i=1;i<L->length && flag;i++) 	/* ーflagーtrueーー�aーーーーーー */
	{
		flag=FALSE;						/* ーーFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);			/* ーー>r[j]ーL->r[j+1]妻株/
				flag=TRUE;				/* ー蔡ーーーーーflagーtrue */
			}
		}
	}
}

/* ーーーーー槙ーーー */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ーーーーーーーーーーー*/
		for (j = i+1;j<=L->length;j++)	/* ーー��糀ー */
        {
			if (L->r[min]>L->r[j])		/* ー蔡ーー�Zーーー�繊次� */
                min = j;				/* ーーーー�T〉ーーーin */
        }
		if(i!=min)						/* ーminーーーーーー�k罱次次� */
			swap(L,i,min);				/* ーー>r[i]ーL->r[min]妻株/
	}
}

void InsertSort(SqList *L) 			/* ーーーーーー�Oーー */
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) 		/* ーー->r[i]ーーーーー*/
		{
			L->r[0]=L->r[i]; 		/* ーーーー*/
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; 	/* ーーー */
			L->r[j+1]=L->r[0]; 		/* ーーーー�fー */
		}
	}
}

void ShellSort(SqList *L) 					/* ーーーーー契ーー/
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;			/* ーーP */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])	/* ーー->r[i]ーーーーーー*/ 
			{ 
				L->r[0]=L->r[i]; 			/* ーーー->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ーーーー啄ーーー */
				L->r[j+increment]=L->r[0]; 	/*  ーー/
			}
		}
	}
	while(increment>1);
}



void HeapSort(SqList *L)		/* ーーーーーーーー/
{
	int i;
	for(i=L->length/2;i>0;i--) 	/* ーー�x�Q�髻辞wー瘠*/
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{ 
		swap(L,1,i); 			/* ーー了ーーー�_�{ーーーPーーーーーー/
		HeapAdjust(L,1,i-1); 	/* ー->r[1..i-1]ーー�檗次次� */
	}
}

void HeapAdjust(SqList *L,int s,int m)
{ /* ー�獄檗�>r[s]�繊次次朱�>r[s..m]ーー�wー瘠*/
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) 	/* ー遥ーーーーーーーーーー */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; 			/* jー遥ーーーーーーーー*/
		if(temp>=L->r[j])
			break; 			/* rcーーー�fーsー */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; 			/* ーー/
}

/* ーーーー簫ーー */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* ーR[s..t]簫ーーーTR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ーR[s..t]ー襖ー[s..m]ーR[m+1..t] */
		MSort(SR,TR2,s,m);		/* マ驅ーR[s..m]簫ーーー奨R2[s..m] */
		MSort(SR,TR2,m+1,t);	/* マ驅ーR[m+1..t]簫ーーー奨R2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* ーR2[s..m]ーR2[m+1..t]簫ーTR1[s..t] */
	}
}


void Merge(int SR[],int TR[],int i,int m,int n)
{ /* ーーーSR[i..m]ーR[m+1..n]簫ーーー奨R[i..n] */
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ーRーーーー敷ーーー */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* ーー蔘R[i..m]笛ーー */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* ーー蔘R[j..n]笛ーー */
	}
}


void MergeSort2(SqList *L) 				 /* ーーーー簫ーマ�\ー */
{
	int* TR=(int*)malloc(L->length * sizeof(int));	/* ーー學ーー*/
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;										/* ーーPーーー��/
		MergePass(TR,L->r,k,L->length);
		k=2*k;										/* ーーPーーー��/       
	}
}


void MergePass(int SR[],int TR[],int s,int n)
{/* ーR[]ーーZーーーーーー}}簫ーTR[] */
	int i=1;
	int j;
	while(i <= n-2*s+1)					/* }}簫ー/
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) 						/* 簫ーーーーP */
		Merge(SR,TR,i,i+s-1,n);
	else 								/* ーーーーー�l歉ーP */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ーーーーーーーー/
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* ーーーー蔬ーーL->r[low..high]ーーーーー/
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
		/* ー->r[low..high]ー襖ーーーーーーpivot */
		pivot=Partition(L,low,high); 
		QSort(L,low,pivot-1);		 /*  �痢次次偲Xーー/
		QSort(L,pivot+1,high);		 /*  яーーー�Xーー/
	}
}

int Partition(SqList *L,int low,int high)
{/* ーーーーーーーーーーーーーーー�fーーーーー�fーー�宗次次次�(ー�后�(ー)ーーー/
	int pivotkey;

	pivotkey=L->r[low]; 	/* ーーーーーーーーーーーー/
	while(low<high) 		/* ーー}��ー�Lーーー */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);	/* ーーーーー�kーーーー�u*/
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);	/* ーーーーー�kーーーー�u*/
	}
	return low; 			/* �_ーーーー�fー */
}

int pivotkey;

int m = low + (high - low) / 2; 	/* ーーーーーーー�T〉ー/  
if (L->r[low]>L->r[high])			
	swap(L,low,high);				/* ーー�檗写后次次次自�ーー/
if (L->r[m]>L->r[high])
	swap(L,high,m);					/* ーーーー鵡ーーーーーーー/
if (L->r[m]>L->r[low])
	swap(L,m,low);					/* ーーーー鵡ーーーー��ーー/

/* ーーr[low]ー�Α酌eーーーーー忤ーー妻ーーー/

pivotkey=L->r[low]; 				/* ーーーーーーーーーーーー/

/* ーーーーーー */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ーーーーーーー�T〉ー/  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);			/* ーー�檗写后次次次自�ーー/
	if (L->r[m]>L->r[high])
		swap(L,high,m);				/* ーーーー鵡ーーーーーーー/
	if (L->r[m]>L->r[low])
		swap(L,m,low);				/* ーーーー鵡ーーーー��ーー/
	
	pivotkey=L->r[low]; 			/* ーーーーーーーーーーーー/
	L->r[0]=pivotkey;  				/* ーー遥ーーーー>r[0] */
	while(low<high) 				/*  ーー}��ー�Lーーー */
	{ 
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];		/* ーI�s頑ーーー鮑ーーー吮/
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];		/* ーI�s頑ーーー鮑ーーー吮/
	}
	L->r[low]=L->r[0];				/* ーーーーーーー.r[low] */
	return low; 					/* �_ーーーー�fー */
}

#define MAX_LENGTH_INSERT_SORT 7 /* ーーーーーーー�\ーーーーーーー株/
/* ーーーー蔬ーーL.r[low..high]ーーーーー/
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); 	/* ー->r[low..high]ー襖ーーーーーーpivot */
		QSort1(L,low,pivot-1);			/* �痢次次偲Xーー/
		QSort1(L,pivot+1,high);			/* яーーー�Xーー/
	}
	else
		InsertSort(L);					/* 姓igh-lowーー表ーーーーーー�Oーー */
}

/* �]マ寵�O/
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /* ー->r[low..high]ー襖ーーーーーーpivot */
			QSort2(L,low,pivot-1);		/* �痢次次偲Xーー/
			low=pivot+1;				/* �]マ寵�O/
		}
	}
	else
		InsertSort(L);					/* 姓igh-lowーー表ーーーーーー�Oーー */
}


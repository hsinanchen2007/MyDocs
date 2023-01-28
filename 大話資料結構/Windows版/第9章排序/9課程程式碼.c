


#define MAXSIZE 10000  	/* ���������������V�����ЇR�������*/
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
				 swap(L,i,j);	/* ����>r[i]��L->r[j]�ʳ�/
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
		for(j=L->length-1;j>=i;j--) /* ����j������������*/
		{
			if(L->r[j]>L->r[j+1]) 	/* ������������������/�������������á�/
			{
				 swap(L,j,j+1);		/* ����>r[j]��L->r[j+1]�ʳ�/
			}
		}
	}
}

/* ���������O�ء����Y*/
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;					/* flag��4��������*/
	for(i=1;i<L->length && flag;i++) 	/* ��flag��true�����a������������ */
	{
		flag=FALSE;						/* ����False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);			/* ����>r[j]��L->r[j+1]�ʳ�/
				flag=TRUE;				/* ���񡼡�������flag��true */
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
		for (j = i+1;j<=L->length;j++)	/* �������� */
        {
			if (L->r[min]>L->r[j])		/* ���񡼡��Z������������ */
                min = j;				/* ���������T�ӡ�����in */
        }
		if(i!=min)						/* ��min�������������k�ա����� */
			swap(L,i,min);				/* ����>r[i]��L->r[min]�ʳ�/
	}
}

void InsertSort(SqList *L) 			/* �������������O���� */
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) 		/* ����->r[i]����������*/
		{
			L->r[0]=L->r[i]; 		/* ��������*/
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; 	/* ������ */
			L->r[j+1]=L->r[0]; 		/* ���������f�� */
		}
	}
}

void ShellSort(SqList *L) 					/* ����������������/
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;			/* ����P */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])	/* ����->r[i]������������*/ 
			{ 
				L->r[0]=L->r[i]; 			/* ������->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ������������� */
				L->r[j+increment]=L->r[0]; 	/*  ����/
			}
		}
	}
	while(increment>1);
}



void HeapSort(SqList *L)		/* ����������������/
{
	int i;
	for(i=L->length/2;i>0;i--) 	/* �����x�Q�򡼭w����*/
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{ 
		swap(L,1,i); 			/* ����λ�������_�{������P������������/
		HeapAdjust(L,1,i-1); 	/* ��->r[1..i-1]�����ݡ����� */
	}
}

void HeapAdjust(SqList *L,int s,int m)
{ /* �����ݡ�>r[s]����������>r[s..m]�����w����*/
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) 	/* ���ڡ������������������� */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; 			/* j���ڡ���������������*/
		if(temp>=L->r[j])
			break; 			/* rc�������f��s�� */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; 			/* ����/
}

/* ���������ԡ��� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

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


void Merge(int SR[],int TR[],int i,int m,int n)
{ /* ������SR[i..m]��R[m+1..n]�ԡ�������R[i..n] */
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


void MergeSort2(SqList *L) 				 /* ���������ԡ����\�� */
{
	int* TR=(int*)malloc(L->length * sizeof(int));	/* �����ܡ���*/
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;										/* ����P��������/
		MergePass(TR,L->r,k,L->length);
		k=2*k;										/* ����P��������/       
	}
}


void MergePass(int SR[],int TR[],int s,int n)
{/* ��R[]����Z������������}}�ԡ�TR[] */
	int i=1;
	int j;
	while(i <= n-2*s+1)					/* }}�ԡ�/
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) 						/* �ԡ�������P */
		Merge(SR,TR,i,i+s-1,n);
	else 								/* �����������lݾ��P */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ����������������/
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* ��������������L->r[low..high]����������/
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
		/* ��->r[low..high]����������������pivot */
		pivot=Partition(L,low,high); 
		QSort(L,low,pivot-1);		 /*  �Ρ������X����/
		QSort(L,pivot+1,high);		 /*  �񡼡����X����/
	}
}

int Partition(SqList *L,int low,int high)
{/* �������������������������������f�����������f��������������(������(��)������/
	int pivotkey;

	pivotkey=L->r[low]; 	/* ������������������������/
	while(low<high) 		/* ����}�����L������ */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);	/* �����������k���������u*/
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);	/* �����������k���������u*/
	}
	return low; 			/* �_���������f�� */
}

int pivotkey;

int m = low + (high - low) / 2; 	/* ���������������T�ӡ�/  
if (L->r[low]>L->r[high])			
	swap(L,low,high);				/* �����ݡ�̹��������������/
if (L->r[m]>L->r[high])
	swap(L,high,m);					/* ��������̹��������������/
if (L->r[m]>L->r[low])
	swap(L,m,low);					/* ��������̹��������������/

/* ����r[low]�������e�����������ء����ʡ�����/

pivotkey=L->r[low]; 				/* ������������������������/

/* ������������ */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ���������������T�ӡ�/  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);			/* �����ݡ�̹��������������/
	if (L->r[m]>L->r[high])
		swap(L,high,m);				/* ��������̹��������������/
	if (L->r[m]>L->r[low])
		swap(L,m,low);				/* ��������̹��������������/
	
	pivotkey=L->r[low]; 			/* ������������������������/
	L->r[0]=pivotkey;  				/* �����ڡ�������>r[0] */
	while(low<high) 				/*  ����}�����L������ */
	{ 
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];		/* ��I�s�衼����򺡼������/
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];		/* ��I�s�衼����򺡼������/
	}
	L->r[low]=L->r[0];				/* ��������������.r[low] */
	return low; 					/* �_���������f�� */
}

#define MAX_LENGTH_INSERT_SORT 7 /* ���������������\����������������/
/* ��������������L.r[low..high]����������/
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); 	/* ��->r[low..high]����������������pivot */
		QSort1(L,low,pivot-1);			/* �Ρ������X����/
		QSort1(L,pivot+1,high);			/* �񡼡����X����/
	}
	else
		InsertSort(L);					/* ��igh-low����ɽ�������������O���� */
}

/* �]�����O/
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /* ��->r[low..high]����������������pivot */
			QSort2(L,low,pivot-1);		/* �Ρ������X����/
			low=pivot+1;				/* �]�����O/
		}
	}
	else
		InsertSort(L);					/* ��igh-low����ɽ�������������O���� */
}


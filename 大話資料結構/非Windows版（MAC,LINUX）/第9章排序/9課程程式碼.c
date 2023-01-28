


#define MAXSIZE 10000  	/* �Ω�n�Ƨǰ}�C�ӼƳ̤j�ȡA�i�ھڻݭn�ק� */
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
				 swap(L,i,j);	/* �洫L->r[i]�PL->r[j]���� */
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
		for(j=L->length-1;j>=i;j--) /* �`�Nj�O�q�᩹�e�`�� */
		{
			if(L->r[j]>L->r[j+1]) 	/* �Y�e�̤j���̡]�`�N�o�̻P�W�@��k���t���^*/
			{
				 swap(L,j,j+1);		/* �洫L->r[j]�PL->r[j+1]���� */
			}
		}
	}
}

/* ��`�Ǧ�CL�@��i�Ϫ@��k */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;					/* flag�Ψӧ@���Х� */
	for(i=1;i<L->length && flag;i++) 	/* �Yflag��true����ƥ洫�A�_�h���}�`�� */
	{
		flag=FALSE;						/* �_�l��False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);			/* �洫L->r[j]�PL->r[j+1]���� */
				flag=TRUE;				/* �Y�G����ƥ洫�A�hflag��true */
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
		for (j = i+1;j<=L->length;j++)	/* �`�����᪺��� */
        {
			if (L->r[min]>L->r[j])		/* �Y�G���p��ثe�̤p�Ȫ�����r */
                min = j;				/* �N������r�����޵����ȵ�min */
        }
		if(i!=min)						/* �Ymin������i�A�������̤p�ȡA�洫 */
			swap(L,i,min);				/* �洫L->r[i]�PL->r[min]���� */
	}
}

void InsertSort(SqList *L) 			/* ��`�Ǧ�CL�@�������J�Ƨ� */
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) 		/* �ݱNL->r[i]���J���Ǥl�� */
		{
			L->r[0]=L->r[i]; 		/* �]�w��L */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; 	/* �O���Ჾ */
			L->r[j+1]=L->r[0]; 		/* ���J�쥿�T��m */
		}
	}
}

void ShellSort(SqList *L) 					/* ��`�Ǧ�CL�@�ƺ��Ƨ� */
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;			/* �W�q�ǦC */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])	/* �ݱNL->r[i]���J���ǼW�q�l�� */ 
			{ 
				L->r[0]=L->r[i]; 			/* �Ȧs�bL->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  �O���Ჾ�A�d�ߴ��J��m */
				L->r[j+increment]=L->r[0]; 	/*  ���J */
			}
		}
	}
	while(increment>1);
}



void HeapSort(SqList *L)		/* ��`�Ǧ�CL�i���Ƨ� */
{
	int i;
	for(i=L->length/2;i>0;i--) 	/* ��L����r�غc���@�Ӥj���� */
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{ 
		swap(L,1,i); 			/* �N�ﳻ�O���M�ثe���g�ƧǤl�ǦC�̫�@�O���洫 */
		HeapAdjust(L,1,i-1); 	/* �NL->r[1..i-1]���s�վ㬰�j���� */
	}
}

void HeapAdjust(SqList *L,int s,int m)
{ /* ����ƽվ�L->r[s]������r�A��L->r[s..m]�����@�Ӥj���� */
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) 	/* �u����r���j���Ĥl�`�I�V�U�z�� */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; 			/* j������r�����j���O�������� */
		if(temp>=L->r[j])
			break; 			/* rc�����J�b��ms�W */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; 			/* ���J */
}

/* ��`�Ǧ�CL�@�k�ñƧ� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

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


void Merge(int SR[],int TR[],int i,int m,int n)
{ /* �N���Ǫ�SR[i..m]�MSR[m+1..n]�k�ì����Ǫ�TR[i..n] */
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


void MergeSort2(SqList *L) 				 /* ��`�Ǧ�CL�@�k�ëD���k�Ƨ� */
{
	int* TR=(int*)malloc(L->length * sizeof(int));	/* �ӽ��B�~�Ŷ� */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;										/* �l�ǦC���ץ[�� */
		MergePass(TR,L->r,k,L->length);
		k=2*k;										/* �l�ǦC���ץ[�� */       
	}
}


void MergePass(int SR[],int TR[],int s,int n)
{/* �NSR[]���۾F���׬�s���l�ǦC����k�è�TR[] */
	int i=1;
	int j;
	while(i <= n-2*s+1)					/* ����k�� */
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) 						/* �k�ó̫��ӧǦC */
		Merge(SR,TR,i,i+s-1,n);
	else 								/* �Y�̫�u�ѤU��@�l�ǦC */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ��`�Ǧ�CL�@�ֳt�Ƨ� */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* ��`�Ǧ�CL�����l�ǦCL->r[low..high]�@�ֳt�Ƨ� */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
		/* �NL->r[low..high]�@�����G�A��X�϶b��pivot */
		pivot=Partition(L,low,high); 
		QSort(L,low,pivot-1);		 /*  ��C�l���k�Ƨ� */
		QSort(L,pivot+1,high);		 /*  �ﰪ�l���k�Ƨ� */
	}
}

int Partition(SqList *L,int low,int high)
{/* �洫�`�Ǧ�CL���l���O���A�ϼ϶b�O���X��A�öǦ^��Ҧb��m�A���ɦb�����e(��)�����j(�p)�󥦡C*/
	int pivotkey;

	pivotkey=L->r[low]; 	/* �Τl���Ĥ@�ӰO���@�϶b�O�� */
	while(low<high) 		/* �q����ݥ���a�V�������y */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);	/* �N��϶b�O���p���O���洫��C�� */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);	/* �N��϶b�O���j���O���洫�찪�� */
	}
	return low; 			/* �Ǧ^�϶b�Ҧb��m */
}

int pivotkey;

int m = low + (high - low) / 2; 	/* �p��}�C���������������� */  
if (L->r[low]>L->r[high])			
	swap(L,low,high);				/* �洫���ݻP�k�ݸ�ơA�T�O���ݸ��p */
if (L->r[m]>L->r[high])
	swap(L,high,m);					/* �洫�����P�k�ݸ�ơA�T�O�������p */
if (L->r[m]>L->r[low])
	swap(L,m,low);					/* �洫�����P���ݸ�ơA�T�O���ݸ��p */

/* ����L.r[low]�w�g����ӧǦC�����k�T������r�������ȡC*/

pivotkey=L->r[low]; 				/* �Τl���Ĥ@�ӰO���@�϶b�O�� */

/* �ֳt�Ƨǧﵽ��k */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* �p��}�C���������������� */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);			/* �洫���ݻP�k�ݸ�ơA�T�O���ݸ��p */
	if (L->r[m]>L->r[high])
		swap(L,high,m);				/* �洫�����P�k�ݸ�ơA�T�O�������p */
	if (L->r[m]>L->r[low])
		swap(L,m,low);				/* �洫�����P���ݸ�ơA�T�O���ݸ��p */
	
	pivotkey=L->r[low]; 			/* �Τl���Ĥ@�ӰO���@�϶b�O�� */
	L->r[0]=pivotkey;  				/* �N�϶b����r�ƥ���L->r[0] */
	while(low<high) 				/*  �q����ݥ���a�V�������y */
	{ 
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];		/* ���θm���Ӥ��O�洫���Ҧ��i��ʧ@ */
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];		/* ���θm���Ӥ��O�洫���Ҧ��i��ʧ@ */
	}
	L->r[low]=L->r[0];				/* �N�϶b�ƭȸm���^L.r[low] */
	return low; 					/* �Ǧ^�϶b�Ҧb��m */
}

#define MAX_LENGTH_INSERT_SORT 7 /* �Ω�ֳt�ƧǮɧP�_�O�_��δ��J�Ƨ����� */
/* ��`�Ǧ�CL�����l�ǦCL.r[low..high]�@�ֳt�Ƨ� */
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); 	/* �NL->r[low..high]�@�����G�A��X�϶b��pivot */
		QSort1(L,low,pivot-1);			/* ��C�l���k�Ƨ� */
		QSort1(L,pivot+1,high);			/* �ﰪ�l���k�Ƨ� */
	}
	else
		InsertSort(L);					/* ��high-low�p�󵥩�`�q�ɥΪ������J�Ƨ� */
}

/* �����k */
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /* �NL->r[low..high]�@�����G�A��X�϶b��pivot */
			QSort2(L,low,pivot-1);		/* ��C�l���k�Ƨ� */
			low=pivot+1;				/* �����k */
		}
	}
	else
		InsertSort(L);					/* ��high-low�p�󵥩�`�q�ɥΪ������J�Ƨ� */
}


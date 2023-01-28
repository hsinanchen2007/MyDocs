Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* �������������᡼��taller��TRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* �������������������ڡ��С��������O */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* ������T����������������/
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �_����/ 
				return FALSE;
			if(*taller) 		/* ������T�������������������᡼*/ 
			{
				switch((*T)->bf)/* ���򡼡��r*/ 
				{
					case LH: 	/* ���������������С�㺡��������z */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* �������������顼�������������ުࡼ����*/ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* �����������������ʡ�������������*/  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  ������T�������١�������/ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* �_����/ 
				return FALSE;
			if(*taller) 		/* ������T�������N���������᡼*/ 
			{
				switch((*T)->bf)/* ���򡼡��r*/ 
				{
					case LH: 	/* ���������������С������������顼*/ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* �������������顼�������������ުࡼ����*/
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* �����������������ʡ������������z */ 
						RightBalance(T); 
						*taller=FALSE; 
						break;
				}
			}
		}
	}
	return TRUE;
}

void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; 					/* L����T���������� */ 
	switch(L->bf)		/* ���򡼡����꡼�t�������������z */ 
	{ 
		 case LH:     	/* ����������T�������������������a����- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* ����������T������������ޤ������������/ 
			Lr=L->rchild; 				/* Lr����T�������������e */ 
			switch(Lr->bf)				/* ���C���������������� */ 
			{ 							
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); 	/* �d�����������������z */ 
			R_Rotate(T); 				/* �d�����������z */ 
	}
}

Status Delete(BiTree *p)
{/* ���ġ�������������p������������������ */
	BiTree q,s;
	if((*p)->rchild==NULL) /* �������ܡ����������������������K������������ª*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ���������������� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* ������������ */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* �������������v������������������/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* s�������L�ʡ�����(�������������n�]��������) */
		if(q!=*p)
			q->rchild=s->lchild;/*  ������������/ 
		else
			q->lchild=s->lchild;/*  ���������� */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* ���E�i����T����������ɽ��ey�񡼡�����������E������/
	if(!*T) 					/* �����ڡ�ɽ��ey�񡼡��� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* ���С���ɽ��ey�񡼡��� */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* ���á��E�i����T�����@��key, */ 
	if (!T)		/* ���������V����p��������û���{���������������FALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* ��������ٯ������p�����a�������������TRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* �������������c�� */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* �������������c�� */
}

int Fibonacci_Search(int *a,int n,int key) /* ���١�����*/
{
	int low,high,mid,i,k;
	low=1;						/* ���{��ӡ������f */
	high=n;						/* ���{�N�ӡ������f */
	k=0;
	while(n>F[k]-1)				/* ���������١���P���� */
		k++;
	for (i=n;i<F[k]-1;i++)		/* �����񡼡���/
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* �������n������*/
		if (key<a[mid])			/* �������������Z���顼��/
		{
			high=mid-1;			/* ���N�ӡ����ϡ�����id-1��*/
			k=k-1;				/* ���١���P�������f */
		}
		else if (key>a[mid])	/* �������������Z���顼��/
		{
			low=mid+1;			/* ����ӡ����ϡ�����id+1��*/
			k=k-2;				/* ���١���P�������f */
		}
		else
		{
			if (mid<=n)
				return mid;		/* �����硼��mid������������ */
			else 
				return n;		/* ��mid>n���ҡ����������n */
		}
	}
	return 0;
}

/* �����������������������������V��key�������������� */
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

/* ������������*/
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* ����a[0]���ڡ�������������������*/
	i=n;				/* ���������]���� */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* �_�������ҡ����a */
}

/* ������ */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* ���{��ӡ������f */
	high=n;					/* ���{�N�ӡ������f */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ����*/
		if (key<a[mid])		/* �������}������ */
			high=mid-1;		/* ���N�ӡ���ν���������f */
		else if (key>a[mid])/* �������}������*/
			low=mid+1;		/* ����ӡ���ν���������f */
		else
		{
			return mid;		/* �����硼��mid������������ */
		}
	}
	return 0;
}

/* ���ɡ� */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ���{��ӡ������f */
	high=n;	/* ���{�N�ӡ������f */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ����/
		if (key<a[mid])		/* �������}���� */
			high=mid-1;		/* ���N�ӡ����Z�p�������f */
		else if (key>a[mid])/* �������}���� */
			low=mid+1;		/* ����ӡ����Z�p�������f */
		else
			return mid;		/* �����硼��mid������������ */
	}
	return 0;
}

/* �E�����t���������� */
typedef  struct BiTNode					/* ������*/
{
	int data;							/* �����D*/
	struct BiTNode *lchild, *rchild;	/* ���������� */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* ��������*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  �����������b*/
		else if (key<p->data) 
			p->lchild = s;				/*  ����������*/
		else 
			p->rchild = s;  			/*  ����������*/
		return TRUE;
	} 
	else 
		return FALSE;  					/*  ���������ڡ������С���������/
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* �E�����t���������� */
typedef  struct BiTNode					/* ������*/
{
	int data;							/* �����D*/
	int bf; 							/*  ���������� */ 
	struct BiTNode *lchild, *rchild;	/* ���������� */
} BiTNode, *BiTree;


/* �㡼���ࡼ�ġ��������������� */
/* ���������������e�������������������������b*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  L����P���������� */ 
	(*P)->lchild=L->rchild; /*  L������¹���������� */ 
	L->rchild=(*P);
	*P=L; 					/*  P�����������b*/ 
}

/* �㡼���ࡼ�ġ��������������� */
/* ���������������e���������������������s�ա���0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  R����P�������e����/ 
	(*P)->rchild=R->lchild; /* R������ມ�����������/ 
	R->lchild=(*P);
	*P=R; 					/*  P�����������b*/ 
}

#define LH +1 /*  ����*/ 
#define EH 0  /*  �顼*/ 
#define RH -1 /*  ����*/ 

/*  �㡼��T���������ࡼ�ġ���������������/
/*  �������᡼��T�����������b*/



/*  �㡼��T���������ࡼ�ġ��������������� */ 
/*  �������᡼��T�����������b*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* R����T�������e����/ 
	switch(R->bf)
	{ /* ���򡼡����s�ա������������������z */ 
	 case RH: /* ����������T������������ޤ�����M������/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* ����������T��������������������������/ 
			  Rl=R->lchild; 			/* Rl����T��������������*/ 
			  switch(Rl->bf)			/* ���C���������������� */ 
			  { 						
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); 	/* �d�������ʡ��������z */ 
			  L_Rotate(T); 				/* �d�����������z */ 
	}
}



int i;
int a[10]={3,2,1,4,5,6,7,10,9,8};
BiTree T=NULL;
Status taller;
for(i=0;i<10;i++)
{
	InsertAVL(&T,a[i],&taller);
}


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 	/* ����P���������_�� */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* ���������������iæ���� */
   int count; 			/*  �Z�������V��/
}HashTable;

int m=0; 				/* ��P������������/

/* ������P��*/
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}

/* ��P����/
int Hash(int key)
{
	return key % m; /* �������Y*/
}

/* ����������P��*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* ����P����/
	while (H->elem[addr] != NULLKEY) 	/* ���v���롼����/
	{
		addr = (addr+1) % m; 			/* �������������� */
	}
	H->elem[addr] = key; 				/* ����������������*/
}


/* ��P�����ڡ� */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* ����P����/
	while(H.elem[*addr] != key) 							/* ���v���롼����/
	{
		*addr = (*addr+1) % m; 								/* �������������� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ���¡������b*/
			return UNSUCCESS;								/* �������ڡ����� */
	}
	return SUCCESS;
}







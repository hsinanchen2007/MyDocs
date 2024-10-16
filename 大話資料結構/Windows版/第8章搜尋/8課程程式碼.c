Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* ーーーーーーメーーtallerーTRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* ーーーーーーーーー遥ー�弌次次次磁O */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* ーー繍T蔬ーーーーーー吮/
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �_ーー/ 
				return FALSE;
			if(*taller) 		/* ーーーT蔬ーーーーーーーーメー*/ 
			{
				switch((*T)->bf)/* ー鋳ーー�r*/ 
				{
					case LH: 	/* ーーーーーーー衾ー禳ーーーー�z */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* ーーーーーー�蕁次次次次次次酒洽燹次実�*/ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ーーーー�А次次腫福次次次次而�堆*/  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  ーー繍T蔘ーー瞹ーーー吮/ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* �_ーー/ 
				return FALSE;
			if(*taller) 		/* ーーーT蔘ーー�Nーーーーメー*/ 
			{
				switch((*T)->bf)/* ー鋳ーー�r*/ 
				{
					case LH: 	/* ーーーーーーー衾ーーーーーー�蕁�*/ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* ーーーーーー�蕁次次次次次次酒洽燹次実�*/
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ーーーー�А次次腫福次次次次次写z */ 
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
	L=(*T)->lchild; 					/* LーーT蔬ーーーー */ 
	switch(L->bf)		/* ー鋳ーーー粨ー�tーーーーーー�z */ 
	{ 
		 case LH:     	/* ーーーーーT蔬ーー蔬ーーーーー�aーー- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* ーーーーーT蔬ーー蔘ーー泙ーーーーーー/ 
			Lr=L->rchild; 				/* LrーーT蔬ーー蔘ーー�e */ 
			switch(Lr->bf)				/* ー�Cーーーーーーーー */ 
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
			L_Rotate(&(*T)->lchild); 	/* �d蔬ーーーーーーー�z */ 
			R_Rotate(T); 				/* �dーーーーー�z */ 
	}
}

Status Delete(BiTree *p)
{/* ー�帖次次次次次次�pーーーーーーーーー */
	BiTree q,s;
	if((*p)->rchild==NULL) /* ーーー�棔次次次次次次次次次次爾Kーーーーーー捉*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ーーーーーーーー */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* ーーーー�后� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* ーーーーーー�vーーーーーーーーー/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* sーーー�L貶ーーー(ーーーーー妻�n�]ーーーー) */
		if(q!=*p)
			q->rchild=s->lchild;/*  ーー蔘ーー吮/ 
		else
			q->lchild=s->lchild;/*  ーー蔬ーー */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* ー�E�iーーTーーーーー表ーey糀ーーーーーーーEーーー/
	if(!*T) 					/* ーー遥ー表ーey糀ーーー */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* ー�弌次蕊宗�ey糀ーーー */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* マ饕ー�E�iーーTーー�@ーkey, */ 
	if (!T)		/* ーーーー�Vーーpーーーー短ー�{ーー��ーーーー甬FALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* ーーーー扼ーーーpーー�aーーーーーー甬TRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* ーーーーーー�cー */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* ーーーーーー�cー */
}

int Fibonacci_Search(int *a,int n,int key) /* ー�戞次次�*/
{
	int low,high,mid,i,k;
	low=1;						/* ー�{�鵝咫次次治f */
	high=n;						/* ー�{�N〉ーーー�f */
	k=0;
	while(n>F[k]-1)				/* ーーーー�戞次�P厚ー */
		k++;
	for (i=n;i<F[k]-1;i++)		/* ーー糀ーーー/
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* ーーー�nーーー*/
		if (key<a[mid])			/* ーーーーーー�Zー檎ーー/
		{
			high=mid-1;			/* ー�N〉ーー�蓮次次�id-1ー*/
			k=k-1;				/* ー�戞次�Pーー�Γf */
		}
		else if (key>a[mid])	/* ーーーーーー�Zー檎ーー/
		{
			low=mid+1;			/* ー�鵝咫次磁蓮次次�id+1ー*/
			k=k-2;				/* ー�戞次�Pーー旭�f */
		}
		else
		{
			if (mid<=n)
				return mid;		/* ーー�隋次�midーーー��ーー */
			else 
				return n;		/* ーmid>nー〈ーーーーー甬n */
		}
	}
	return 0;
}

/* ーーーーーーーーーーーーーー�Vーkeyーーーーーーー */
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

/* ーーーーーー*/
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* ーーa[0]ー遥ーーーーーー��ーー嗽*/
	i=n;				/* ーーーー�]ーー */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* �_ーーー〈ーー�a */
}

/* ーー啄 */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* ー�{�鵝咫次次治f */
	high=n;					/* ー�{�N〉ーーー�f */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ーー*/
		if (key<a[mid])		/* ーーー�}ーーー */
			high=mid-1;		/* ー�N〉ーー僚ーーーー�f */
		else if (key>a[mid])/* ーーー�}ーーー*/
			low=mid+1;		/* ー�鵝咫次捨宗次次次治f */
		else
		{
			return mid;		/* ーー�隋次�midーーー��ーー */
		}
	}
	return 0;
}

/* ー塗ー */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ー�{�鵝咫次次治f */
	high=n;	/* ー�{�N〉ーーー�f */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ー株/
		if (key<a[mid])		/* ーーー�}ーー */
			high=mid-1;		/* ー�N〉ーー�Z�pーーー�f */
		else if (key>a[mid])/* ーーー�}ー憮 */
			low=mid+1;		/* ー�鵝咫次珠Z�pーーー�f */
		else
			return mid;		/* ーー�隋次�midーーー��ーー */
	}
	return 0;
}

/* �Eー亭��tーーー��ー */
typedef  struct BiTNode					/* ーー��*/
{
	int data;							/* ーー�D*/
	struct BiTNode *lchild, *rchild;	/* ーーーー褸 */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* ーーーー*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  ーーー椿綴�b*/
		else if (key<p->data) 
			p->lchild = s;				/*  ーーーーー*/
		else 
			p->rchild = s;  			/*  ーーーーー*/
		return TRUE;
	} 
	else 
		return FALSE;  					/*  ーーーー遥ーーー�弌次次次次�/
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* �Eー亭��tーーー��ー */
typedef  struct BiTNode					/* ーー��*/
{
	int data;							/* ーー�D*/
	int bf; 							/*  ーーーーー */ 
	struct BiTNode *lchild, *rchild;	/* ーーーー褸 */
} BiTNode, *BiTree;


/* �磧次蔀燹��帖次次次次次次次� */
/* ーーーーーー糀�eーーーーーーー蔬ーー椿綴�b*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  LーーP蔬ーーーー */ 
	(*P)->lchild=L->rchild; /*  L蔘ーー孫ーーーーー */ 
	L->rchild=(*P);
	*P=L; 					/*  Pーーー椿綴�b*/ 
}

/* �磧次蔀燹��帖次次次次次次次� */
/* ーーーーーー糀�eーーーーーーー蔘ーー�s箇ーー0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  RーーP蔘ーー�eーー/ 
	(*P)->rchild=R->lchild; /* R蔬ーー犧ーーーーー吮/ 
	R->lchild=(*P);
	*P=R; 					/*  Pーーー椿綴�b*/ 
}

#define LH +1 /*  ー堆*/ 
#define EH 0  /*  �蕁�*/ 
#define RH -1 /*  ー堆*/ 

/*  �磧手�Tーーーー逐ー�帖次次次次次次次�/
/*  ーーー�瓠手�Tーーー椿綴�b*/



/*  �磧手�Tーーーー逐ー�帖次次次次次次次� */ 
/*  ーーー�瓠手�Tーーー椿綴�b*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* RーーT蔘ーー�eーー/ 
	switch(R->bf)
	{ /* ー鋳ーーー�s箇ーーーーーーーーー�z */ 
	 case RH: /* ーーーーーT蔘ーー蔘ーー泙ーー�Mーーー/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* ーーーーーT蔘ーー蔬ーーーーーーーーー/ 
			  Rl=R->lchild; 			/* RlーーT蔘ーー蔬ーー顆*/ 
			  switch(Rl->bf)			/* ー�Cーーーーーーーー */ 
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
			  R_Rotate(&(*T)->rchild); 	/* �d蔘ーー淙ーーーー�z */ 
			  L_Rotate(T); 				/* �dーーーーー�z */ 
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
#define HASHSIZE 12 	/* ー俾Pーーーー�_ー */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* ー��ーーーーー�i脱ーー */
   int count; 			/*  �Zー��ー�Vー/
}HashTable;

int m=0; 				/* ーPーーーーー彼/

/* ーーーPー*/
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

/* ーPーー/
int Hash(int key)
{
	return key % m; /* ーーー�Y*/
}

/* ーーーー昔Pー*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* ーーP紘吮/
	while (H->elem[addr] != NULLKEY) 	/* ー�vー�襦次次�/
	{
		addr = (addr+1) % m; 			/* ーー雜棄ーーーー */
	}
	H->elem[addr] = key; 				/* ー訣ーーーーーーー*/
}


/* ーPー啄遥ー */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* ーーP紘吮/
	while(H.elem[*addr] != key) 							/* ー�vー�襦次次�/
	{
		*addr = (*addr+1) % m; 								/* ーー雜棄ーーーー */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ー饗ーーー�b*/
			return UNSUCCESS;								/* ーー〈遥ーーー */
	}
	return SUCCESS;
}







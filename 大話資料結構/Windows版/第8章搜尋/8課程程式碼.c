Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* ¡¼¡¼¡¼¡¼¡¼¡¼¥á¡¼¡¼taller¡¼TRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÍÚ¡¼÷Ð¡¼¡¼¡¼¡¼§O */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* ¡¼¡¼½«Tèö¡¼¡¼¡¼¡¼¡¼¡¼Òä/
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  £_¡¼¡¼/ 
				return FALSE;
			if(*taller) 		/* ¡¼¡¼¡¼Tèö¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¥á¡¼*/ 
			{
				switch((*T)->bf)/* ¡¼Ãò¡¼¡¼Ýr*/ 
				{
					case LH: 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼êÐ¡¼ãº¡¼¡¼¡¼¡¼Ìz */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼¡¼¡¼¡¼¡¼¡¼¡¼òÞªà¡¼¡¼ÂÏ*/ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ¡¼¡¼¡¼¡¼ô§¡¼¡¼¡¼ðÊ¡¼¡¼¡¼¡¼¡¼©¬ÂÏ*/  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  ¡¼¡¼½«Tèõ¡¼¡¼âÙ¡¼¡¼¡¼Òä/ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* £_¡¼¡¼/ 
				return FALSE;
			if(*taller) 		/* ¡¼¡¼¡¼Tèõ¡¼¡¼¿N¡¼¡¼¡¼¡¼¥á¡¼*/ 
			{
				switch((*T)->bf)/* ¡¼Ãò¡¼¡¼Ýr*/ 
				{
					case LH: 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼êÐ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼*/ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼¡¼¡¼¡¼¡¼¡¼¡¼òÞªà¡¼¡¼ÂÏ*/
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ¡¼¡¼¡¼¡¼ô§¡¼¡¼¡¼ðÊ¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
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
	L=(*T)->lchild; 					/* L¡¼¡¼Tèö¡¼¡¼¡¼¡¼ */ 
	switch(L->bf)		/* ¡¼Ãò¡¼¡¼¡¼äê¡¼Ýt¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
	{ 
		 case LH:     	/* ¡¼¡¼¡¼¡¼¡¼Tèö¡¼¡¼èö¡¼¡¼¡¼¡¼¡¼Îa¡¼¡¼- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* ¡¼¡¼¡¼¡¼¡¼Tèö¡¼¡¼èõ¡¼¡¼Þ¤¡¼¡¼¡¼¡¼¡¼¡¼/ 
			Lr=L->rchild; 				/* Lr¡¼¡¼Tèö¡¼¡¼èõ¡¼¡¼Áe */ 
			switch(Lr->bf)				/* ¡¼ùC¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
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
			L_Rotate(&(*T)->lchild); 	/* Ädèö¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
			R_Rotate(T); 				/* Äd¡¼¡¼¡¼¡¼¡¼Ìz */ 
	}
}

Status Delete(BiTree *p)
{/* ¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼p¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	BiTree q,s;
	if((*p)->rchild==NULL) /* ¡¼¡¼¡¼‹Ü¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¤K¡¼¡¼¡¼¡¼¡¼¡¼Âª*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* ¡¼¡¼¡¼¡¼ ¹¡¼ */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* ¡¼¡¼¡¼¡¼¡¼¡¼Ìv¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* s¡¼¡¼¡¼‚LìÊ¡¼¡¼¡¼(¡¼¡¼¡¼¡¼¡¼ºÊÊn©]¡¼¡¼¡¼¡¼) */
		if(q!=*p)
			q->rchild=s->lchild;/*  ¡¼¡¼èõ¡¼¡¼Òä/ 
		else
			q->lchild=s->lchild;/*  ¡¼¡¼èö¡¼¡¼ */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* ¡¼êEÝi¡¼¡¼T¡¼¡¼¡¼¡¼¡¼É½¡¼eyäñ¡¼¡¼¡¼¡¼¡¼¡¼¡¼E¡¼¡¼¡¼/
	if(!*T) 					/* ¡¼¡¼ÍÚ¡¼É½¡¼eyäñ¡¼¡¼¡¼ */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* ¡¼§Ð¡¼¡¼É½¡¼eyäñ¡¼¡¼¡¼ */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* ¥ÞñÃ¡¼êEÝi¡¼¡¼T¡¼¡¼÷@¡¼key, */ 
	if (!T)		/* ¡¼¡¼¡¼¡¼ïV¡¼¡¼p¡¼¡¼¡¼¡¼Ã»¡¼Ò{¡¼¡¼ ú¡¼¡¼¡¼¡¼áµFALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* ¡¼¡¼¡¼¡¼Ù¯¡¼¡¼¡¼p¡¼¡¼Ða¡¼¡¼¡¼¡¼¡¼¡¼áµTRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* ¡¼¡¼¡¼¡¼¡¼¡¼³c¡¼ */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* ¡¼¡¼¡¼¡¼¡¼¡¼³c¡¼ */
}

int Fibonacci_Search(int *a,int n,int key) /* ¡¼¯Ù¡¼¡¼¡¼*/
{
	int low,high,mid,i,k;
	low=1;						/* ¡¼«{¨ó¡Ó¡¼¡¼¡¼£f */
	high=n;						/* ¡¼«{÷N¡Ó¡¼¡¼¡¼£f */
	k=0;
	while(n>F[k]-1)				/* ¡¼¡¼¡¼¡¼¯Ù¡¼¡¼P¸ü¡¼ */
		k++;
	for (i=n;i<F[k]-1;i++)		/* ¡¼¡¼äñ¡¼¡¼¡¼/
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* ¡¼¡¼¡¼¯n¡¼¡¼¡¼*/
		if (key<a[mid])			/* ¡¼¡¼¡¼¡¼¡¼¡¼ÌZ¡¼¸é¡¼¡¼/
		{
			high=mid-1;			/* ¡¼÷N¡Ó¡¼¡¼§Ï¡¼¡¼¡¼id-1¡¼*/
			k=k-1;				/* ¡¼¯Ù¡¼¡¼P¡¼¡¼«¦£f */
		}
		else if (key>a[mid])	/* ¡¼¡¼¡¼¡¼¡¼¡¼ÌZ¡¼¸é¡¼¡¼/
		{
			low=mid+1;			/* ¡¼¨ó¡Ó¡¼¡¼§Ï¡¼¡¼¡¼id+1¡¼*/
			k=k-2;				/* ¡¼¯Ù¡¼¡¼P¡¼¡¼°°£f */
		}
		else
		{
			if (mid<=n)
				return mid;		/* ¡¼¡¼­ç¡¼¡Òmid¡¼¡¼¡¼­£¡¼¡¼ */
			else 
				return n;		/* ¡¼mid>n¡¼¡Ò¡¼¡¼¡¼¡¼¡¼áµn */
		}
	}
	return 0;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶V¡¼key¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
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

/* ¡¼¡¼¡¼¡¼¡¼¡¼*/
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* ¡¼¡¼a[0]¡¼ÍÚ¡¼¡¼¡¼¡¼¡¼¡¼Žû¡¼¡¼ÓÖ*/
	i=n;				/* ¡¼¡¼¡¼¡¼£]¡¼¡¼ */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* ß_¡¼¡¼¡¼¡Ò¡¼¡¼ða */
}

/* ¡¼¡¼Âï */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* ¡¼«{¨ó¡Ó¡¼¡¼¡¼£f */
	high=n;					/* ¡¼«{÷N¡Ó¡¼¡¼¡¼£f */
	while(low<=high)
	{
		mid=(low+high)/2;	/* ¡¼¡¼*/
		if (key<a[mid])		/* ¡¼¡¼¡¼©}¡¼¡¼¡¼ */
			high=mid-1;		/* ¡¼÷N¡Ó¡¼¡¼Î½¡¼¡¼¡¼¡¼£f */
		else if (key>a[mid])/* ¡¼¡¼¡¼©}¡¼¡¼¡¼*/
			low=mid+1;		/* ¡¼¨ó¡Ó¡¼¡¼Î½¡¼¡¼¡¼¡¼£f */
		else
		{
			return mid;		/* ¡¼¡¼­ç¡¼¡Òmid¡¼¡¼¡¼­£¡¼¡¼ */
		}
	}
	return 0;
}

/* ¡¼ÅÉ¡¼ */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ¡¼«{¨ó¡Ó¡¼¡¼¡¼£f */
	high=n;	/* ¡¼«{÷N¡Ó¡¼¡¼¡¼£f */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ¡¼³ô/
		if (key<a[mid])		/* ¡¼¡¼¡¼©}¡¼¡¼ */
			high=mid-1;		/* ¡¼÷N¡Ó¡¼¡¼îZØp¡¼¡¼¡¼£f */
		else if (key>a[mid])/* ¡¼¡¼¡¼©}¡¼Øã */
			low=mid+1;		/* ¡¼¨ó¡Ó¡¼¡¼îZØp¡¼¡¼¡¼£f */
		else
			return mid;		/* ¡¼¡¼­ç¡¼¡Òmid¡¼¡¼¡¼­£¡¼¡¼ */
	}
	return 0;
}

/* êE¡¼ÄâÄt¡¼¡¼¡¼õ©¡¼ */
typedef  struct BiTNode					/* ¡¼¡¼ö¿*/
{
	int data;							/* ¡¼¡¼•D*/
	struct BiTNode *lchild, *rchild;	/* ¡¼¡¼¡¼¡¼êú */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* ¡¼¡¼¡¼¡¼*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  ¡¼¡¼¡¼ÄØÄÖÃb*/
		else if (key<p->data) 
			p->lchild = s;				/*  ¡¼¡¼¡¼¡¼¡¼*/
		else 
			p->rchild = s;  			/*  ¡¼¡¼¡¼¡¼¡¼*/
		return TRUE;
	} 
	else 
		return FALSE;  					/*  ¡¼¡¼¡¼¡¼ÍÚ¡¼¡¼¡¼÷Ð¡¼¡¼¡¼¡¼¡¼/
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* êE¡¼ÄâÄt¡¼¡¼¡¼õ©¡¼ */
typedef  struct BiTNode					/* ¡¼¡¼ö¿*/
{
	int data;							/* ¡¼¡¼•D*/
	int bf; 							/*  ¡¼¡¼¡¼¡¼¡¼ */ 
	struct BiTNode *lchild, *rchild;	/* ¡¼¡¼¡¼¡¼êú */
} BiTNode, *BiTree;


/* öã¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼¡¼¡¼¡¼äñÁe¡¼¡¼¡¼¡¼¡¼¡¼¡¼èö¡¼¡¼ÄØÄÖÃb*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  L¡¼¡¼Pèö¡¼¡¼¡¼¡¼ */ 
	(*P)->lchild=L->rchild; /*  Lèõ¡¼¡¼Â¹¡¼¡¼¡¼¡¼¡¼ */ 
	L->rchild=(*P);
	*P=L; 					/*  P¡¼¡¼¡¼ÄØÄÖÃb*/ 
}

/* öã¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼¡¼¡¼¡¼äñÁe¡¼¡¼¡¼¡¼¡¼¡¼¡¼èõ¡¼¡¼¸s²Õ¡¼¡¼0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  R¡¼¡¼Pèõ¡¼¡¼Áe¡¼¡¼/ 
	(*P)->rchild=R->lchild; /* Rèö¡¼¡¼àº¡¼¡¼¡¼¡¼¡¼Òä/ 
	R->lchild=(*P);
	*P=R; 					/*  P¡¼¡¼¡¼ÄØÄÖÃb*/ 
}

#define LH +1 /*  ¡¼ÂÏ*/ 
#define EH 0  /*  ¨é¡¼*/ 
#define RH -1 /*  ¡¼ÂÏ*/ 

/*  öã¡¼êúT¡¼¡¼¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
/*  ¡¼¡¼¡¼ªá¡¼êúT¡¼¡¼¡¼ÄØÄÖÃb*/



/*  öã¡¼êúT¡¼¡¼¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
/*  ¡¼¡¼¡¼ªá¡¼êúT¡¼¡¼¡¼ÄØÄÖÃb*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* R¡¼¡¼Tèõ¡¼¡¼Áe¡¼¡¼/ 
	switch(R->bf)
	{ /* ¡¼Ãò¡¼¡¼¡¼¸s²Õ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
	 case RH: /* ¡¼¡¼¡¼¡¼¡¼Tèõ¡¼¡¼èõ¡¼¡¼Þ¤¡¼¡¼®M¡¼¡¼¡¼/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* ¡¼¡¼¡¼¡¼¡¼Tèõ¡¼¡¼èö¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/ 
			  Rl=R->lchild; 			/* Rl¡¼¡¼Tèõ¡¼¡¼èö¡¼¡¼ðù*/ 
			  switch(Rl->bf)			/* ¡¼ùC¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
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
			  R_Rotate(&(*T)->rchild); 	/* Ädèõ¡¼¡¼ÞÊ¡¼¡¼¡¼¡¼Ìz */ 
			  L_Rotate(T); 				/* Äd¡¼¡¼¡¼¡¼¡¼Ìz */ 
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
#define HASHSIZE 12 	/* ¡¼ÐìP¡¼¡¼¡¼¡¼Ã_¡¼ */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* ¡¼”÷¡¼¡¼¡¼¡¼¡¼ˆiÃ¦¡¼¡¼ */
   int count; 			/*  ÌZ¡¼”÷¡¼¶V¡¼/
}HashTable;

int m=0; 				/* ¡¼P¡¼¡¼¡¼¡¼¡¼Èà/

/* ¡¼¡¼¡¼P¡¼*/
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

/* ¡¼P¡¼¡¼/
int Hash(int key)
{
	return key % m; /* ¡¼¡¼¡¼¸Y*/
}

/* ¡¼¡¼¡¼¡¼ÀÎP¡¼*/
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* ¡¼¡¼P¹ÉÒä/
	while (H->elem[addr] != NULLKEY) 	/* ¡¼øv¡¼‹ë¡¼¡¼¡¼/
	{
		addr = (addr+1) % m; 			/* ¡¼¡¼ð¸´þ¡¼¡¼¡¼¡¼ */
	}
	H->elem[addr] = key; 				/* ¡¼·í¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
}


/* ¡¼P¡¼ÂïÍÚ¡¼ */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* ¡¼¡¼P¹ÉÒä/
	while(H.elem[*addr] != key) 							/* ¡¼øv¡¼‹ë¡¼¡¼¡¼/
	{
		*addr = (*addr+1) % m; 								/* ¡¼¡¼ð¸´þ¡¼¡¼¡¼¡¼ */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ¡¼¶Â¡¼¡¼¡¼Ãb*/
			return UNSUCCESS;								/* ¡¼¡¼¡ÒÍÚ¡¼¡¼¡¼ */
	}
	return SUCCESS;
}







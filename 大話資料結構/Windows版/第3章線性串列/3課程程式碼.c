Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
	int j, k, l;   
	k = MAXSIZE - 1;   					/* ¡¼¡¼k¡¼£r¡¼¡¼¡¼¡¼¡¼¡¼ßT¡Ó¡¼/
	if (i < 1 || i > ListLength(L) + 1)   
		return ERROR;   
	j = Malloc_SSL(L);   				/* ¡¼y¡¼¡¼¡¼¡¼¡¼¡¼*/
	if (j)   
	{   
		L[j].data = e;   				/* ¡¼¡¼»­±`¡¼¡¼¡¼data */
		for(l = 1; l <= i - 1; l++)   	/* ¡¼­£¡¼àd¡¼¡¼¡¼¸ü¡¼ */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    		/* ¡¼¡¼àd¡¼¡¼¡¼¼sur»­±`¡¼¡¼¡¼¼sur */
		L[k].cur = j;           		/* ¡¼¡¼¡¼ßT¡Ó¡¼¡¼¿æ¡¼àd¡¼¡¼¡¼¡¼¡¼ñìr */
		return OK;   
	}   
	return ERROR;   
}

/*¡¼¾R¾©¡¼¡¼¡¼¡¼¡¼À¨¡¼La¡¼äñ¡¼¡¼¡¼¡¼¡¼La¡¼*/
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;                        /*¡¼¡Ò¡¼La¡¼b¡¼¡¼äñ¡¼¡¼¡¼e*/
	La_len=ListLength(*La);            /*¡¼¡¼¡¼¡¼¡¼¡¼ */
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);              /*¡¼Lb¡¼¿£¶V¡¼¡¼¡¼ÁËÄû/
		if (!LocateElem(*La,e))        /*La¡¼¡¼¡¼¡¼¡¼¡¼¡¼”÷¡¼*/
			ListInsert(La,++La_len,e); /*¡¼¡¼
	}
}



#define MAXSIZE 20          /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */
typedef int ElemType;       /* ElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼int */
typedef struct
{
	ElemType data[MAXSIZE]; /* ¡¼¡¼¡¼Ï«¡¼”÷¡¼ */
	int length;             /* ¡¼¡¼¡¼¡¼¡¼¡¼*/
}SqList;


#define OK 1
#define ERROR 0
/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef int Status;         

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼istLength(L) */
/* ¡¼Ó\¡¼¡¼eß_¡¼¡¼¿£¶V¡¼¡¼¡¼ºÊ¤Ð¡¼¡¼i¡¼¡¼£f¡¼¡¼¡¼à`¡¼äñ¡¼¡¼¡¼¡¼¡¼/
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];

	return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼1¡¼¡¼istLength(L)¡¼*/
/* ¡¼Ó\¡¼¡¼L¡¼¿£à`¡¼¡¼¡¼¡¼¡¼äñ¡¼¡¼¡¼e¡¼Ã_¡¼¡¼ */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  			/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
		return ERROR;
	if (i<1 || i>L->length+1)			/* ïÂ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ ú¡¼£f¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
		return ERROR;				

	if (i<=L->length)        			/* ¡¼¡¼¡¼”ñ¡¼¡¼¡¼¡¼ */
	{
		for(k=L->length-1;k>=i-1;k--)  	/* ¡¼¡¼¡¼£f¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          			/* ¡¼¡¼¡¼¡¼¡¼/
	L->length++;

	return OK;
}


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼istLength(L) */
/* ¡¼Ó\¡¼¡¼¡¼ñì¡¼¶V¡¼¡¼¡¼¡¼¡¼eß_¡¼¡¼¡¼Ã_¡¼¡¼ */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
	int k;
	if (L->length==0)               /* ¡¼¡¼¡¼¡¼ */
		return ERROR;
	if (i<1 || i>L->length)         /* ¡¼¡¼¡¼¡¼¡¼ */
		return ERROR;
	*e=L->data[i-1];
	if (i<L->length)                /* ¡¼Ædž\¡¼¡¼ ú£f¡¼ */
	{
		for(k=i;k<L->length;k++)	/* ¡¼ž\£f¡¼¡¼¡¼¡¼¡¼¡¼ */
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

/* ¡¼¡¼¡¼¡¼°¼¡¼Ï«¡¼Ãþ§O/
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* ¡¼¦JnkList */


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼istLength(L) */
/* ¡¼Ó\¡¼¡¼eß_¡¼¡¼¿£¶V¡¼¡¼¡¼ºÊ³ô/
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ¡¼¡Ò¡¼¡¼¡¼*/
	p = L->next;		/* ¡¼p¡¼¡¼t¡¼ñì¡¼¡¼¡¼¡¼/
	j = 1;		/*  j¡¼¡¼¡¼ */
	while (p && j<i)  /* p¡¼¡¼¡¼¡¼¡¼¡¼j¡¼¡¼É½¡¼¡¼¡¼¡¼¡¼÷P/
	{   
		p = p->next;  /* ¡¼p¡¼¡¼¡¼¡¼¡¼¡¼ */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ¿£àd¡¼¡¼¡¼ */
	*e = p->data;   /*  ¡¼¿£àd¡¼äñ¡¼ */
	return OK;
}


s->next = p->next;    /* ¡¼õÀ¡¼¡¼¡¼¡¼ë½õÀ¡¼  */
p->next = s;          /* ¡¼»­±`põÀ¡¼ */


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼1¡¼¡¼istLength(L)¡¼*/
/* ¡¼Ó\¡¼¡¼L¡¼¿£à`¡¼¡¼¡¼¡¼¡¼äñ¡¼¡¼¡¼e¡¼Ã_¡¼¡¼ */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     				/* ¡¼¡¼¿£¡¼¡¼ */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   				/* ¿£àd¡¼¡¼¡¼ */

	s = (LinkList)malloc(sizeof(Node)); /* ¡¼¡¼¡¼¡¼(C¡¼¡¼¡¼¡¼¡¼) */
	s->data = e;  
	s->next = p->next;    				/* ¡¼õÀ¡¼¡¼¡¼¡¼ë½õÀ¡¼ */
	p->next = s;          				/* ¡¼»­±`põÀ¡¼ */
	return OK;
}

q = p->next;
p->next = q->next;			/* ¡¼õÀ¡¼»­±`põÀ¡¼ */


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼istLength(L) */
/* ¡¼Ó\¡¼¡¼¡¼ñì¡¼¶V¡¼¡¼¡¼¡¼¡¼eß_¡¼¡¼¡¼Ã_¡¼¡¼ */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ¡¼¡¼¡¼¿£àd¡¼ */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) 
		return ERROR;           /* ¿£àd¡¼¡¼¡¼ */
	q = p->next;
	p->next = q->next;			/* ¡¼õÀ¡¼»­±`põÀ¡¼ */
	*e = q->data;               /* ¡¼¡¼¡¼äñ¡¼çõ */
	free(q);                    /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼®è/
	return OK;
}

/*  ¡¼¡¼¡¼nàd¡¼ºÊ¤Ð¡¼¡¼¡¼Ó\§§¡¼°¼¡¼¡¼¡¼¡¼µ°¿qÃþ§O/
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /* £r¡¼¡¼­w²ü¡¼¡¼¹Ý¡¼ */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /* ¡¼¡¼¡¼¡¼ */
		p->data = rand()%100+1;             /* ¡¼¡¼¡¼100¡¼¡¼äñ¡¼ */
		p->next = (*L)->next;    
		(*L)->next = p;						/* ¡¼¡¼¡¼Òä/
	}
}

/*  ¡¼¡¼¡¼nàd¡¼ºÊ¤Ð¡¼¡¼¡¼Ó\§§¡¼°¼¡¼¡¼¡¼¡¼¡¼¿qÃþ§O/
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                     	/* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	*L = (LinkList)malloc(sizeof(Node)); 	/* L¡¼¡¼àa¡¼¡¼¡¼/
	r=*L;                                	/* r¡¼¡¼¡¼£]¡¼¡¼¡¼ */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); 	/* ¡¼¡¼¡¼¡¼ */
		p->data = rand()%100+1;           	/* ¡¼¡¼¡¼100¡¼¡¼äñ¡¼ */
		r->next=p;                        	/* ¡¼¡¼¡¼«û¡¼ºÊêú¡¼¡¼¡¼¡¼¡¼/
		r = p;                            	/* ¡¼¡¼¾ª¡¼¡¼¡¼á¶¡¼¢y«û¡¼ */
	}
	r->next = NULL;                       	/* ¡¼žò¡¼t¡¼¡¼ */
}


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼‹ù¡¼/
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p¡¼¡¼»ò¡¼¡¼¡¼/
	while(p)                /*  u¼v¡¼ */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ¡¼¡¼¡¼¡¼¡¼¡¼‹è*/
	return OK;
}


#define MAXSIZE 1000 	/* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

/* ¡¼¡¼¡¼¡¼¡¼t¡¼Ï«¡¼Ãþ§O/
typedef struct 
{
	ElemType data;
	int cur;  			/* ¡¼¡¼Cursor) ¡¼¡¼¡¼¡¼£Q¡¼¡¼ */
} Component,StaticLinkList[MAXSIZE];



/* ¡¼¡¼¡¼¡¼space¡¼Ãß¡¼ƒä¡¼¡¼¡¼A¡¼¡¼pace[0].cur¡¼¡¼¡¼¡¼¡¼0"¡¼‚â¡¼¡¼ */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; 	/* ¡¼¡¼ª¡¼¡¼¡¼¡¼ ú¡¼àd¡¼¼sur¡¼0 */
	return OK;
}

/* ¡¼¡¼y¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼ */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* ÌZ¡¼¡¼»ò¡¼¡¼¡¼¼sur¡¼¡¼³ô/
											/* Žy¡¼¡¼¡¼¡¼¡¼¡¼¡¼y¡¼¡¼¡¼¡Ó¡¼/
	if (space[0]. cur)         
		space[0]. cur = space[i].cur;       /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ƒ¤¡¼¡¼K¡¼*/
											/* ¡¼¡¼£ECŽÆe¡¼¡¼¡¼¡¼çï*/
											/* ¡¼Šè4¡¼¡¼a*/
	return i;
}

/*  ¡¼¡¼¡¼¡¼¿£¶V¡¼¡¼¡¼   */
Status ListDelete(StaticLinkList L, int i)   
{ 
	int j, k;   
	if (i < 1 || i > ListLength(L))   
		return ERROR;   
	k = MAXSIZE - 1;   
	for (j = 1; j <= i - 1; j++)   
		k = L[k].cur;   
	j = L[k].cur;   
	L[k].cur = L[j].cur;   
	Free_SSL(L, j);   
	return OK;   
} 

/*  ¡¼¡Ó¡¼k¨à¡¼¡¼¡¼¡¼¡¼¡¼¡¼t¡¼*/
void Free_SSL(StaticLinkList space, int k) 
{  
	space[k].cur = space[0].cur;    /* ¡¼¡¼¡¼¡¼¡¼¼sur¡¼ÁËãº¡¼¡¼¡¼¡¼ÿr */
	space[0].cur = k;               /* ¡¼¡¼¡¼¡¼¡¼‰b¡¼¡¼¿æ¡¼¡¼¡¼¡¼¼sur */
}

/* ¡¼¡¼¡¼¡¼¡¼t¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼”÷¡¼¶V¡¼/
int ListLength(StaticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		i=L[i].cur;
		j++;
	}
	return j;
}

p=rearA->next;   			    /* ¡¼®®¡¼¡¼¡¼¡¼¡¼¡¼*/
rearA->next=rearB->next->next;	/* ¡¼þS¡¼¡¼B¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ó\ôB»ê
                 				/* »­±`reaA->next¡¼¡¼ */
q=rearB->next;
rearB->next=p;				   	/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¹PearB->next¡¼¡¼ */
free¡¼¡¼					   	/* ¡¼¡¼ */



/*¡¼¡¼¡¼¡¼¡¼t¡¼Ï«¡¼»ê
typedef struct DulNode
{
		ElemType data;
		struct DuLNode *prior;    	/*¡¼¡¼¡¼¡¼¡¼*/
		struct DuLNode *next;		/*¡¼¡¼¡¼¡¼¡¼*/
} DulNode, *DuLinkList;


p->next->prior = p = p->prior->next

s - >prior = p;   			/*¡¼»­±`säë¡¼¡¼ôn¡¼¡¼/
s -> next = p -> next;		/*¡¼->next»­±`sõÀ¡¼¡¼ôn¡¼¡¼/
p -> next -> prior = s;		/*¡¼»­±`p->nextäë¡¼¡¼ôn¡¼¡¼/
p -> next = s;				/*¡¼»­±`põÀ¡¼¡¼ôn¡¼¡¼/


p->prior->next=p->next;   	/*¡¼->next»­±`p->priorõÀ¡¼¡¼ôn¡¼¡¼/
p->next->prior=p->prior;	/*¡¼->prior»­±`p->nextäë¡¼¡¼ôn¡¼¡¼/
free¡¼¡¼					/*¡¼º´¡¼*/















































































































































































































































































































































































































































































































































































































































































































































































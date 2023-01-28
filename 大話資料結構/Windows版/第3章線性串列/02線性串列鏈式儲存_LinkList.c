#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status;/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef int ElemType;/* ElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* ¡¼¦JnkList */

/* ¡¼¡¼t¡¼¡¼¡¼¡¼*/
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* ¡¼¡¼¡¼¡¼¡¼L¡¼¡¼¡¼Ó\Ãb*/
    if(!(*L)) /* ¡¼¡¼¡¼¡¼¡¼*/
            return ERROR;
    (*L)->next=NULL; /* ¡¼¡¼¡¼¡¼‹è*/

    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼L¡¼‹ù¡¼¡¼ß_¡¼RUE¡¼¡¼ß_¡¼ALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
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

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼”÷¡¼¶V¡¼/
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p¡¼¡¼»ò¡¼¡¼¡¼/
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

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

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼Ó\¡¼¡¼¡¼¡¼À¸àc¡¼¡¼ìF¡¼¡¼”÷¡¼¸ü¡¼¡¼*/
/* ¡¼¡¼¡¼äñ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* ¡¼¿ý¢µäñ¡¼¡¼¡¼ */
                return i;
        p=p->next;
    }

    return 0;
}


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼1¡¼¡¼istLength(L)¡¼*/
/* ¡¼Ó\¡¼¡¼L¡¼¿£à`¡¼¡¼¡¼¡¼¡¼äñ¡¼¡¼¡¼e¡¼Ã_¡¼¡¼ */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* ¡¼¡¼¿£¡¼¡¼ */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* ¿£àd¡¼¡¼¡¼ */
	s = (LinkList)malloc(sizeof(Node));  /*  ¡¼¡¼¡¼¡¼(C¡¼¡¼¡¼¡¼¡¼) */
	s->data = e;  
	s->next = p->next;      /* ¡¼õÀ¡¼¡¼¡¼¡¼ë½õÀ¡¼  */
	p->next = s;          /* ¡¼»­±`põÀ¡¼ */
	return OK;
}

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

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼Ó\¡¼¡¼¡¼¡¼äç¡`¡¼”÷¡¼¡¼¡¼*/
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/*  ¡¼¡¼¡¼nàd¡¼ºÊ¤Ð¡¼¡¼¡¼Ó\§§¡¼°¼¡¼¡¼¡¼¡¼µ°¿qÃþ§O/
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  £r¡¼¡¼­w²ü¡¼¡¼¹Ý¡¼ */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  ¡¼¡¼¡¼¡¼ */
		p->data = rand()%100+1;             /*  ¡¼¡¼¡¼100¡¼¡¼äñ¡¼ */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ¡¼¡¼¡¼Òä/
	}
}

/*  ¡¼¡¼¡¼nàd¡¼ºÊ¤Ð¡¼¡¼¡¼Ó\§§¡¼°¼¡¼¡¼¡¼¡¼¡¼¿qÃþ§O/
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	*L = (LinkList)malloc(sizeof(Node)); /* L¡¼¡¼àa¡¼¡¼¡¼/
	r=*L;                                /* r¡¼¡¼¡¼£]¡¼¡¼¡¼ */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  ¡¼¡¼¡¼¡¼ */
		p->data = rand()%100+1;           /*  ¡¼¡¼¡¼100¡¼¡¼äñ¡¼ */
		r->next=p;                        /* ¡¼¡¼¡¼«û¡¼ºÊêú¡¼¡¼¡¼¡¼¡¼/
		r = p;                            /* ¡¼¡¼¾ª¡¼¡¼¡¼á¶¡¼¢y«û¡¼ */
	}
	r->next = NULL;                       /* ¡¼žò¡¼t¡¼¡¼ */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("¡¼¡¼L¡¼¡¼stLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("¡¼Lï·¡¼¡¼¡¼§O1¡¼¡¼¡¼data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L¡¼ÐG¡¼¡¼%d(1:¡¼ 0:øû\n",i);

    i=ClearList(&L);
    printf("¡¼‹Ô¡¼¡¼stLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L¡¼ÐG¡¼¡¼%d(1:¡¼ 0:øû\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("¡¼Lï·¡¼¡¼¡¼§O1¡¼0¡¼¡¼data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("¡¼Lï·¡¼¡¼¡¼¡¼L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("ô@àd¡¼ºÊá¶¡¼d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("Ã`dàd¡¼ºÊá¶%d\n",k,j);
            else
                    printf("u¡¼¡¼¡¼%d¾©¡¼\n",j);
    }
    

    k=ListLength(L); /* k¡¼¡¼¡¼/
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ¡¼¡¼¡¼¶V¡¼ */
            if(i==ERROR)
                    printf("¡¼¡¼¡¼d¶V¡¼¡¼¡¼n",j);
            else
                    printf("¡¼¡¼¡¼dÓå¡¼¡¼¡¼¡¼¡¼d\n",j,e);
    }
    printf("¡¼¡¼¡¼L¾©¡¼¡¼);
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ¡¼¡¼¡¼¶V¡¼ */
    printf("¡¼¡¼¡¼dÓå¡¼¡¼¡¼¡¼¡¼d\n",j,e);

    printf("¡¼¡¼¡¼L¾©¡¼¡¼);
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n¡¼‹Ô¡¼¡¼stLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("¡¼¡¼¡¼¯ô¡¼¡¼(¡¼¡¼¸Ú¡¼;
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n¡¼¡¼¡¼¡¼stLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("¡¼¡¼¡¼¯ô¡¼¡¼(£]¡¼¸Ú¡¼;
    ListTraverse(L); 


    return 0;
}


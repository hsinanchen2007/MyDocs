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

#define MAXSIZE 20 /* ーーー釦脱ー */

typedef int Status;/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/
typedef int ElemType;/* ElemType ー築ー忽ーー鼠ーーー�mint */


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
typedef struct Node *LinkList; /* ー�JnkList */

/* ーーtーーーー*/
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* ーーーーーLーーー�\�b*/
    if(!(*L)) /* ーーーーー*/
            return ERROR;
    (*L)->next=NULL; /* ーーーー��*/

    return OK;
}

/* ーーーーーーーーーーーーーーーーLー��ーー�_ーRUEーー�_ーALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* ーーーーーーーーーーーーーーーーーーー��ー/
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  pーー賜ーーー/
	while(p)                /*  u�vー */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ーーーーーー��*/
	return OK;
}

/* ーーーーーーーーーーーーーーー�_ーーー��ー�Vー/
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pーー賜ーーー/
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* ーーーーーーーーーーーーーーistLength(L) */
/* ー�\ーーe�_ーー殖�Vーーー妻株/
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ー〈ーーー*/
	p = L->next;		/* ーpーーtー骭ーーーー/
	j = 1;		/*  jーーー */
	while (p && j<i)  /* pーーーーーーjーー表ーーーーー�P/
	{   
		p = p->next;  /* ーpーーーーーー */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  殖�dーーー */
	*e = p->data;   /*  ー殖�dー糀ー */
	return OK;
}

/* ーーーーーーーーーーー*/
/* ー�\ーーーー生�cーー�Fーー��ー厚ーー*/
/* ーーー糀ーーーーーーーー甼0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* ー雀�灸顱次次� */
                return i;
        p=p->next;
    }

    return 0;
}


/* ーーーーーーーーーーー1ーーistLength(L)ー*/
/* ー�\ーーLー殖�`ーーーーー糀ーーーeー�_ーー */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* ーー殖ーー */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 殖�dーーー */
	s = (LinkList)malloc(sizeof(Node));  /*  ーーーー(Cーーーーー) */
	s->data = e;  
	s->next = p->next;      /* ー�澄次次次朱助澄�  */
	p->next = s;          /* ー鮫�`p�澄� */
	return OK;
}

/* ーーーーーーーーーーーーーーistLength(L) */
/* ー�\ーーー骭ー�Vーーーーーe�_ーーー�_ーー */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ーーー殖�dー */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* 殖�dーーー */
	q = p->next;
	p->next = q->next;			/* ー�澄嫉��`p�澄� */
	*e = q->data;               /* ーーー糀ー苺 */
	free(q);                    /* ーーーーーーーーーーー��/
	return OK;
}

/* ーーーーーーーーーーー*/
/* ー�\ーーーー粢�`ー��ーーー*/
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

/*  ーーーn�dー妻ばーーー�\Ёー絢ーーーー軌�q寵�O/
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ーーーーーー */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �rーー�w戒ーー鋼ー */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  ーーーー */
		p->data = rand()%100+1;             /*  ーーー100ーー糀ー */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ーーー吮/
	}
}

/*  ーーーn�dー妻ばーーー�\Ёー絢ーーーーー�q寵�O/
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ーーーーーー */
	*L = (LinkList)malloc(sizeof(Node)); /* Lーー�aーーー/
	r=*L;                                /* rーーー�]ーーー */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  ーーーー */
		p->data = rand()%100+1;           /*  ーーー100ーー糀ー */
		r->next=p;                        /* ーーー��ー妻褸ーーーーー/
		r = p;                            /* ーー妾ーーー甼ー�y��ー */
	}
	r->next = NULL;                       /* ー�髻�tーー */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("ーーLーーstLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("ーL鏃ーーー�O1ーーーdata=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("Lー�Gーー%d(1:ー 0:��\n",i);

    i=ClearList(&L);
    printf("ー�圈次�stLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("Lー�Gーー%d(1:ー 0:��\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("ーL鏃ーーー�O1ー0ーーdata=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("ーL鏃ーーーーL.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("�@�dー妻甼ーd\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("�`d�dー妻甼%d\n",k,j);
            else
                    printf("uーーー%d奨ー\n",j);
    }
    

    k=ListLength(L); /* kーーー/
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ーーー�Vー */
            if(i==ERROR)
                    printf("ーーーd�Vーーーn",j);
            else
                    printf("ーーーd嚆ーーーーーd\n",j,e);
    }
    printf("ーーーL奨ーー);
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ーーー�Vー */
    printf("ーーーd嚆ーーーーーd\n",j,e);

    printf("ーーーL奨ーー);
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\nー�圈次�stLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("ーーー�堯次�(ーー鈷ー;
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\nーーーーstLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("ーーー�堯次�(�]ー鈷ー;
    ListTraverse(L); 


    return 0;
}


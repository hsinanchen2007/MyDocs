#include "string.h"
#include "ctype.h"      

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status;           /* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef char ElemType;        /* ElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mchar */


Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼t¡¼Ï«¡¼Ãþ§O/
typedef struct 
{
    ElemType data;
    int cur;  /* ¡¼¡¼Cursor) ¡¼¡¼¡¼¡¼£Q¡¼¡¼ */
} Component,StaticLinkList[MAXSIZE];


/* ¡¼¡¼¡¼¡¼space¡¼Ãß¡¼ƒä¡¼¡¼¡¼A¡¼¡¼pace[0].cur¡¼¡¼¡¼¡¼¡¼0"¡¼‚â¡¼¡¼ */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* ¡¼¡¼ª¡¼¡¼¡¼¡¼ ú¡¼àd¡¼¼sur¡¼0 */
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

/*  ¡¼L¡¼¿£àd¡¼¡¼¡¼¡¼¡¼äñ¡¼¡¼¡¼e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* ¡¼¡¼k¡¼£r¡¼¡¼¡¼¡¼¡¼¡¼ßT¡Ó¡¼/
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* ¡¼y¡¼¡¼¡¼¡¼¡¼¡¼*/
    if (j)   
    {   
		L[j].data = e;   /* ¡¼¡¼»­±`¡¼¡¼¡¼data */
		for(l = 1; l <= i - 1; l++)   /* ¡¼­£¡¼àd¡¼¡¼¡¼¸ü¡¼ */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* ¡¼¡¼àd¡¼¡¼¡¼¼sur»­±`¡¼¡¼¡¼¼sur */
		L[k].cur = j;           /* ¡¼¡¼¡¼ßT¡Ó¡¼¡¼¿æ¡¼àd¡¼¡¼¡¼¡¼¡¼ñìr */
		return OK;   
    }   
    return ERROR;   
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

Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
            visit(L[i].data);
            i=L[i].cur;
            j++;
    }
    return j;
    printf("\n");
    return OK;
}


int main()
{
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("¡¼¡¼L¡¼¡¼length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n¡¼Lï·¡¼¡¼¡¼§OFEDBA¡¼¡¼L.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n¡¼LÀw!¡¼¡¼¡¼Î¡¼¡¼C¡¼¡¼\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n¡¼L»üž\¡¼¡¼¡¼\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}


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

#define MAXSIZE 1000 /* ーーー釦脱ー */

typedef int Status;           /* Statusーーー ー,ーーーーーーー驚ーーOK�R*/
typedef char ElemType;        /* ElemType ー築ー忽ーー鼠ーーー�mchar */


Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

/* ーーーーーtー労ー寵�O/
typedef struct 
{
    ElemType data;
    int cur;  /* ーーCursor) ーーーー�Qーー */
} Component,StaticLinkList[MAXSIZE];


/* ーーーーspaceー蓄ー�筺次次�Aーーpace[0].curーーーーー0"ー�癲次� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* ーー��ーーーー��ー�dー�surー0 */
	return OK;
}


/* ーーyーーーーーー�_ーーーーーーーー�_ー */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* �Zーー賜ーーー�surーー株/
	                                		/* �yーーーーーーーyーーー〉ー/
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;       /* ーーーーーーー�ぁ次�Kー*/
	                                        /* ーー�ECﾆeーーーー苡*/
	                                        /* ー��4ーーa*/
	return i;
}


/*  ー〉ーk�燹次次次次次次�tー*/
void Free_SSL(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* ーーーーー�surー阻禳ーーーー�r */
    space[0].cur = k;               /* ーーーーー�bーー炊ーーーー�sur */
}

/* ーーーーーtーーーーーーーー�_ーーー��ー�Vー/
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

/*  ーLー殖�dーーーーー糀ーーーe   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* ーーkー�rーーーーーー�T〉ー/
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* ーyーーーーーー*/
    if (j)   
    {   
		L[j].data = e;   /* ーー鮫�`ーーーdata */
		for(l = 1; l <= i - 1; l++)   /* ー��ー�dーーー厚ー */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* ーー�dーーー�sur鮫�`ーーー�sur */
		L[k].cur = j;           /* ーーー�T〉ーー炊ー�dーーーーー骭r */
		return OK;   
    }   
    return ERROR;   
}

/*  ーーーー殖�Vーーー   */
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
    printf("ーーLーーlength=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\nーL鏃ーーー�OFEDBAーーL.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\nーL�w!ーーー�痢次�Cーー\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\nーL慈�\ーーー\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}


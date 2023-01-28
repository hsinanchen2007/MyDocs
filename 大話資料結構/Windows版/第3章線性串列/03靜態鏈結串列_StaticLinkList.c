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

#define MAXSIZE 1000 /* ��������æ�� */

typedef int Status;           /* Status������ ��,���������������á���OK�R*/
typedef char ElemType;        /* ElemType ���ۡ��������͡������mchar */


Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

/* ����������t��ϫ�����O/
typedef struct 
{
    ElemType data;
    int cur;  /* ����Cursor) ���������Q���� */
} Component,StaticLinkList[MAXSIZE];


/* ��������space���ߡ��䡼����A����pace[0].cur����������0"���⡼�� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* �������������������d���sur��0 */
	return OK;
}


/* ����y�������������_�����������������_�� */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* �Z�����򡼡����sur������/
	                                		/* �y��������������y�������ӡ�/
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;       /* ��������������������K��*/
	                                        /* �����EC��e����������*/
	                                        /* ����4����a*/
	return i;
}


/*  ���ӡ�k�ࡼ������������t��*/
void Free_SSL(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* �����������sur����㺡��������r */
    space[0].cur = k;               /* �����������b�����桼�������sur */
}

/* ����������t�����������������_�����������V��/
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

/*  ��L�����d�����������񡼡���e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* ����k���r�������������T�ӡ�/
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* ��y������������*/
    if (j)   
    {   
		L[j].data = e;   /* �������`������data */
		for(l = 1; l <= i - 1; l++)   /* �������d���������� */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* �����d�������sur���`�������sur */
		L[k].cur = j;           /* �������T�ӡ����桼�d������������r */
		return OK;   
    }   
    return ERROR;   
}

/*  �����������V������   */
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
    printf("����L����length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n��L﷡������OFEDBA����L.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n��L�w!�������Ρ���C����\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n��L���\������\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}


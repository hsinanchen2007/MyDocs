
#include "stdio.h"    

#include "stdlib.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */
typedef int ElemType;       /* ElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */
typedef struct
{
    ElemType data[MAXSIZE]; /* ¡¼¡¼¡¼Ï«¡¼”÷¡¼ */
    int length;             /* ¡¼¡¼¡¼¡¼¡¼¡¼*/
}SqList;

typedef int Status;         /* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼L¡¼‹ù¡¼¡¼ß_¡¼RUE¡¼¡¼ß_¡¼ALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼‹ù¡¼/
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼”÷¡¼¶V¡¼/
int ListLength(SqList L)
{
	return L.length;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼istLength(L) */
/* ¡¼Ó\¡¼¡¼eß_¡¼¡¼¿£¶V¡¼¡¼¡¼ºÊéQ¡¼i¡¼¡¼£f¡¼¡¼¡¼à`¡¼äñ¡¼¡¼¡¼¡¼¡¼/
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼Ó\¡¼¡¼¡¼¡¼À¸àc¡¼¡¼ìF¡¼¡¼”÷¡¼¸ü¡¼¡¼*/
/* ¡¼¡¼¡¼äñ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;

    return i+1;
}


/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼1¡¼¡¼istLength(L)¡¼*/
/* ¡¼Ó\¡¼¡¼L¡¼¿£à`¡¼¡¼¡¼¡¼¡¼äñ¡¼¡¼¡¼e¡¼Ã_¡¼¡¼ */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
		return ERROR;
	if (i<1 || i>L->length+1)/* ïÂ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ ú¡¼£f¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
		return ERROR;

	if (i<=L->length)        /* ¡¼¡¼¡¼”ñ¡¼¡¼¡¼¡¼ */
	{
		for(k=L->length-1;k>=i-1;k--)  /* ¡¼¡¼¡¼£f¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Šà£f */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* ¡¼¡¼¡¼¡¼¡¼/
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
        for(k=i;k<L->length;k++)/* ¡¼ž\£f¡¼¡¼¡¼¡¼¡¼¡¼ */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼Ó\¡¼¡¼¡¼¡¼äç¡`¡¼”÷¡¼¡¼¡¼*/
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
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

int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("¡¼¡¼L¡¼¡¼length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("¡¼Lï·¡¼¡¼¡¼§O1¡¼¡¼¡¼data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L¡¼ÐG¡¼¡¼%d(1:¡¼ 0:øû\n",i);

    i=ClearList(&L);
    printf("¡¼‹Ô¡¼¡¼length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L¡¼ÐG¡¼¡¼%d(1:¡¼ 0:øû\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("¡¼Lï·¡¼¡¼¡¼§O1¡¼0¡¼¡¼data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("¡¼Lï·¡¼¡¼¡¼¡¼L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

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

	//øe¡¼àc¡¼0¶V¡¼Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("¡¼¡¼¡¼¡¼¡¼Lbäï¾©¡¼¡¼);
    ListTraverse(L); 

    return 0;
}


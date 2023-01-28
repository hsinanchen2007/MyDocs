
#include "stdio.h"    

#include "stdlib.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* 儲存空間起始分配量 */
typedef int ElemType;       /* ElemType型態根據實際情況而定，這裡假設為int */
typedef struct
{
    ElemType data[MAXSIZE]; /* 陣列，儲存資料元素 */
    int length;             /* 線性串列目前長度 */
}SqList;

typedef int Status;         /* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 起始化順序線性串列 */
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* 起始條件：順序線性串列L已存在。動作結果：若L為空表，則傳回TRUE，否則傳回FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 起始條件：順序線性串列L已存在。動作結果：將L重設為空表 */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* 起始條件：順序線性串列L已存在。動作結果：傳回L中資料元素個數 */
int ListLength(SqList L)
{
	return L.length;
}

/* 起始條件：順序線性串列L已存在，1□i□ListLength(L) */
/* 動作結果：用e傳回L中第i個資料元素的值,注意i是指位置，第1個位置的陣列是從0開始 */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 起始條件：順序線性串列L已存在 */
/* 動作結果：傳回L中第1個與e滿足關系的資料元素的位序。 */
/* 若這樣的資料元素不存在，則傳回值為0 */
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


/* 起始條件：順序線性串列L已存在,1□i□ListLength(L)， */
/* 動作結果：在L中第i個位置之前插入新的資料元素e，L的長度加1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* 順序線性串列已經滿 */
		return ERROR;
	if (i<1 || i>L->length+1)/* 當i比第一位置小或是比最後一位置後一位置還要大時 */
		return ERROR;

	if (i<=L->length)        /* 若插入資料位置不在表尾 */
	{
		for(k=L->length-1;k>=i-1;k--)  /* 將要插入位置之後的資料元素向後搬移一位 */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* 將新元素插入 */
	L->length++;

	return OK;
}

/* 起始條件：順序線性串列L已存在，1□i□ListLength(L) */
/* 動作結果：移除L的第i個資料元素，並用e傳回其值，L的長度減1 */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
    int k;
    if (L->length==0)               /* 線性串列為空 */
		return ERROR;
    if (i<1 || i>L->length)         /* 移除位置不正確 */
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)                /* 若果移除不是最後位置 */
    {
        for(k=i;k<L->length;k++)/* 將移除位置後繼元素前移 */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

/* 起始條件：順序線性串列L已存在 */
/* 動作結果：依次對L的每個資料元素輸出 */
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
}

/*將所有的線上性表Lb中但不在La中的資料元素插入到La中*/
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;                        /*宣告與La和Lb相同的資料元素e*/
	La_len=ListLength(*La);            /*求線性串列的長度 */
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);              /*取Lb中第i個資料元素賦給e*/
		if (!LocateElem(*La,e))        /*La中不存在和e相同資料元素*/
			ListInsert(La,++La_len,e); /*插入*/
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
    printf("起始化L後：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的標頭依次插入1～5後：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清理L後：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10後：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的標頭插入0後：L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("第5個元素的值為：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d個元素的值為%d\n",k,j);
            else
                    printf("沒有值為%d的元素\n",j);
    }
    

    k=ListLength(L); /* k為表長 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 移除第j個資料 */
            if(i==ERROR)
                    printf("移除第%d個資料失敗\n",j);
            else
                    printf("移除第%d個的元素值為：%d\n",j,e);
    }
    printf("依次輸出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 移除第5個資料 */
    printf("移除第%d個的元素值為：%d\n",j,e);

    printf("依次輸出L的元素：");
    ListTraverse(L); 

	//建構一個有10個數的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次輸出合並了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}


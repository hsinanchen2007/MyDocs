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

#define MAXSIZE 1000 /* 儲存空間起始分配量 */

typedef int Status;           /* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef char ElemType;        /* ElemType型態根據實際情況而定，這裡假設為char */


Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

/* 線性串列的靜態鏈結串列儲存結構 */
typedef struct 
{
    ElemType data;
    int cur;  /* 游標(Cursor) ，為0時表示無指向 */
} Component,StaticLinkList[MAXSIZE];


/* 將一維陣列space中各分量鏈成一個備用鏈結串列，space[0].cur為頭指標，"0"表示空指標 */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* 目前靜態鏈結串列為空，最後一個元素的cur為0 */
	return OK;
}


/* 若備用空間鏈結串列非空，則傳回分配的節點索引，否則傳回0 */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* 目前陣列第一個元素的cur存的值 */
	                                		/* 就是要傳回的第一個備用閒置的索引 */
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;       /* 由於要拿出一個分量來使用了， */
	                                        /* 所以我們就得把它的下一個 */
	                                        /* 分量用來做備用 */
	return i;
}


/*  將索引為k的閒置節點回收到備用鏈結串列 */
void Free_SSL(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* 把第一個元素的cur值賦給要移除的分量cur */
    space[0].cur = k;               /* 把要移除的分量索引給予值給第一個元素的cur */
}

/* 起始條件：靜態鏈結串列L已存在。動作結果：傳回L中資料元素個數 */
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

/*  在L中第i個元素之前插入新的資料元素e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
    int j, k, l;   
    k = MAXSIZE - 1;   /* 注意k首先是最後一個元素的索引 */
    if (i < 1 || i > ListLength(L) + 1)   
        return ERROR;   
    j = Malloc_SSL(L);   /* 獲得閒置分量的索引 */
    if (j)   
    {   
		L[j].data = e;   /* 將資料給予值給此分量的data */
		for(l = 1; l <= i - 1; l++)   /* 找到第i個元素之前的位置 */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    /* 把第i個元素之前的cur給予值給新元素的cur */
		L[k].cur = j;           /* 把新元素的索引給予值給第i個元素之前元素的ur */
		return OK;   
    }   
    return ERROR;   
}

/*  移除在L中第i個資料元素   */
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
    printf("起始化L後：L.length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n在L的標頭依次插入FEDBA後：\nL.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n在L的“B”與“D”之間插入“C”後：\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n在L的移除“A”後：\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}


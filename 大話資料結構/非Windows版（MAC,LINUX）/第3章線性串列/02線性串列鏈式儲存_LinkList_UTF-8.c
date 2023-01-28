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

#define MAXSIZE 20 /* 儲存空間起始分配量 */

typedef int Status;/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef int ElemType;/* ElemType型態根據實際情況而定，這裡假設為int */


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
typedef struct Node *LinkList; /* 定義LinkList */

/* 起始化鏈式線性串列 */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 產生頭節點,並使L指向此頭節點 */
    if(!(*L)) /* 儲存分配失敗 */
            return ERROR;
    (*L)->next=NULL; /* 指標域為空 */

    return OK;
}

/* 起始條件：鏈式線性串列L已存在。動作結果：若L為空表，則傳回TRUE，否則傳回FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* 起始條件：鏈式線性串列L已存在。動作結果：將L重設為空表 */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p指向第一個節點 */
	while(p)                /*  沒到表尾 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* 頭節點指標域為空 */
	return OK;
}

/* 起始條件：鏈式線性串列L已存在。動作結果：傳回L中資料元素個數 */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一個節點 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 起始條件：鏈式線性串列L已存在，1□i□ListLength(L) */
/* 動作結果：用e傳回L中第i個資料元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* 宣告一節點p */
	p = L->next;		/* 讓p指向鏈結串列L的第一個節點 */
	j = 1;		/*  j為計數器 */
	while (p && j<i)  /* p不為空或是計數器j還沒有等於i時，循環繼續 */
	{   
		p = p->next;  /* 讓p指向下一個節點 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i個元素不存在 */
	*e = p->data;   /*  取第i個元素的資料 */
	return OK;
}

/* 起始條件：鏈式線性串列L已存在 */
/* 動作結果：傳回L中第1個與e滿足關系的資料元素的位序。 */
/* 若這樣的資料元素不存在，則傳回值為0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* 找到這樣的資料元素 */
                return i;
        p=p->next;
    }

    return 0;
}


/* 起始條件：鏈式線性串列L已存在,1□i□ListLength(L)， */
/* 動作結果：在L中第i個位置之前插入新的資料元素e，L的長度加1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* 尋找第i個節點 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 第i個元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  產生新節點(C語系標准函數) */
	s->data = e;  
	s->next = p->next;      /* 將p的後繼節點給予值給s的後繼  */
	p->next = s;          /* 將s給予值給p的後繼 */
	return OK;
}

/* 起始條件：鏈式線性串列L已存在，1□i□ListLength(L) */
/* 動作結果：移除L的第i個資料元素，並用e傳回其值，L的長度減1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 檢查尋找第i個元素 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* 第i個元素不存在 */
	q = p->next;
	p->next = q->next;			/* 將q的後繼給予值給p的後繼 */
	*e = q->data;               /* 將q節點中的資料給e */
	free(q);                    /* 讓系統回收此節點，釋放記憶體 */
	return OK;
}

/* 起始條件：鏈式線性串列L已存在 */
/* 動作結果：依次對L的每個資料元素輸出 */
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

/*  隨機產生n個元素的值，建立帶標頭節點的單鏈線性串列L（頭插法） */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* 起始化隨機數種子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一個帶頭節點的單鏈結串列 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  產生新節點 */
		p->data = rand()%100+1;             /*  隨機產生100以內的數字 */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  插入到標頭 */
	}
}

/*  隨機產生n個元素的值，建立帶標頭節點的單鏈線性串列L（尾插法） */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* 起始化隨機數種子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L為整個線性串列 */
	r=*L;                                /* r為指向尾部的節點 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  產生新節點 */
		p->data = rand()%100+1;           /*  隨機產生100以內的數字 */
		r->next=p;                        /* 將表尾終端節點的指標指向新節點 */
		r = p;                            /* 將目前的新節點定義為表尾終端節點 */
	}
	r->next = NULL;                       /* 表示目前鏈結串列結束 */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("起始化L後：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的標頭依次插入1～5後：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清理L後：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10後：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的標頭插入0後：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

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

    i=ClearList(&L);
    printf("\n清理L後：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整體建立L的元素(頭插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n移除L後：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整體建立L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}


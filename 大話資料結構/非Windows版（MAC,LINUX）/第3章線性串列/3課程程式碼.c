Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
	int j, k, l;   
	k = MAXSIZE - 1;   					/* 注意k首先是最後一個元素的索引 */
	if (i < 1 || i > ListLength(L) + 1)   
		return ERROR;   
	j = Malloc_SSL(L);   				/* 獲得閒置分量的索引 */
	if (j)   
	{   
		L[j].data = e;   				/* 將資料給予值給此分量的data */
		for(l = 1; l <= i - 1; l++)   	/* 找到第i個元素之前的位置 */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    		/* 把第i個元素之前的cur給予值給新元素的cur */
		L[k].cur = j;           		/* 把新元素的索引給予值給第i個元素之前元素的ur */
		return OK;   
	}   
	return ERROR;   
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



#define MAXSIZE 20          /* 儲存空間起始分配量 */
typedef int ElemType;       /* ElemType型態根據實際情況而定，這裡為int */
typedef struct
{
	ElemType data[MAXSIZE]; /* 陣列，儲存資料元素 */
	int length;             /* 線性串列目前長度 */
}SqList;


#define OK 1
#define ERROR 0
/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef int Status;         

/* 起始條件：順序線性串列L已存在，1□i□ListLength(L) */
/* 動作結果：用e傳回L中第i個資料元素的值，注意i是指位置，第1個位置的陣列是從0開始 */
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];

	return OK;
}

/* 起始條件：順序線性串列L已存在,1□i□ListLength(L)， */
/* 動作結果：在L中第i個位置之前插入新的資料元素e，L的長度加1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  			/* 順序線性串列已經滿 */
		return ERROR;
	if (i<1 || i>L->length+1)			/* 當i比第一位置小或是比最後一位置後一位置還要大時 */
		return ERROR;				

	if (i<=L->length)        			/* 若插入資料位置不在表尾 */
	{
		for(k=L->length-1;k>=i-1;k--)  	/* 將要插入位置後的元素向後移一位 */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          			/* 將新元素插入 */
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
		for(k=i;k<L->length;k++)	/* 將移除位置後繼元素前移 */
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

/* 線性串列的單鏈結串列儲存結構 */
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定義LinkList */


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


s->next = p->next;    /* 將p的後繼節點給予值給s的後繼  */
p->next = s;          /* 將s給予值給p的後繼 */


/* 起始條件：鏈式線性串列L已存在,1□i□ListLength(L)， */
/* 動作結果：在L中第i個位置之前插入新的資料元素e，L的長度加1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     				/* 尋找第i個節點 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   				/* 第i個元素不存在 */

	s = (LinkList)malloc(sizeof(Node)); /* 產生新節點(C語系標准函數) */
	s->data = e;  
	s->next = p->next;    				/* 將p的後繼節點給予值給s的後繼 */
	p->next = s;          				/* 將s給予值給p的後繼 */
	return OK;
}

q = p->next;
p->next = q->next;			/* 將q的後繼給予值給p的後繼 */


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

/*  隨機產生n個元素的值，建立帶標頭節點的單鏈線性串列L（頭插法） */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* 起始化隨機數種子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /* 先建立一個帶頭節點的單鏈結串列 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /* 產生新節點 */
		p->data = rand()%100+1;             /* 隨機產生100以內的數字 */
		p->next = (*L)->next;    
		(*L)->next = p;						/* 插入到標頭 */
	}
}

/*  隨機產生n個元素的值，建立帶標頭節點的單鏈線性串列L（尾插法） */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                     	/* 起始化隨機數種子 */
	*L = (LinkList)malloc(sizeof(Node)); 	/* L為整個線性串列 */
	r=*L;                                	/* r為指向尾部的節點 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); 	/* 產生新節點 */
		p->data = rand()%100+1;           	/* 隨機產生100以內的數字 */
		r->next=p;                        	/* 將表尾終端節點的指標指向新節點 */
		r = p;                            	/* 將目前的新節點定義為表尾終端節點 */
	}
	r->next = NULL;                       	/* 表示目前鏈結串列結束 */
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


#define MAXSIZE 1000 	/* 儲存空間起始分配量 */

/* 線性串列的靜態鏈結串列儲存結構 */
typedef struct 
{
	ElemType data;
	int cur;  			/* 游標(Cursor) ，為0時表示無指向 */
} Component,StaticLinkList[MAXSIZE];



/* 將一維陣列space中各分量鏈成一個備用鏈結串列，space[0].cur為頭指標，"0"表示空指標 */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; 	/* 目前靜態鏈結串列為空，最後一個元素的cur為0 */
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

p=rearA->next;   			    /* 儲存A表的頭節點，即１ */
rearA->next=rearB->next->next;	/* 將本是指向B表的第一個節點（不是頭節點）*/
                 				/* 給予值給reaA->next，即２ */
q=rearB->next;
rearB->next=p;				   	/* 將原A表的頭節點給予值給rearB->next，即３ */
free（q）;					   	/* 釋放q */



/*線性串列的雙向鏈結串列儲存結構*/
typedef struct DulNode
{
		ElemType data;
		struct DuLNode *prior;    	/*直接前驅指標*/
		struct DuLNode *next;		/*後繼指標*/
} DulNode, *DuLinkList;


p->next->prior = p = p->prior->next

s - >prior = p;   			/*把p給予值給s的前驅，如圖中１*/
s -> next = p -> next;		/*把p->next給予值給s的後繼，如圖中２*/
p -> next -> prior = s;		/*把s給予值給p->next的前驅，如圖中３*/
p -> next = s;				/*把s給予值給p的後繼，如圖中４*/


p->prior->next=p->next;   	/*把p->next給予值給p->prior的後繼，如圖中１*/
p->next->prior=p->prior;	/*把p->prior給予值給p->next的前驅，如圖中２*/
free（p）;					/*釋放節點*/















































































































































































































































































































































































































































































































































































































































































































































































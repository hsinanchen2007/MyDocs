
/* 樹的雙親表示法節點結構定義 */
#define MAX_TREE_SIZE 100

typedef int TElemType;				/* 樹節點的資料型態，目前暫定為整數 */

typedef struct PTNode				/* 節點結構 */
{
	TElemType data;					/* 節點資料 */
	int parent;						/* 雙親位置 */
} PTNode;

typedef struct						/* 樹結構 */
{
	PTNode nodes[MAX_TREE_SIZE];	/* 節點陣列 */
	int r,n;						/* 根的位置和節點數 */
} PTree;


/* 樹的孩子表示法結構定義 */
#define MAX_TREE_SIZE 100

typedef int TElemType;			/* 樹節點的資料型態，目前暫定為整數 */

typedef struct CTNode			/* 孩子節點 */
{
	int child;	
	struct CTNode *next;	
} *ChildPtr;

typedef struct 					/* 標頭結構 */
{
	TElemType data;	
	ChildPtr firstchild;	
} CTBox;

typedef struct	     			/* 樹結構 */
{
	CTBox nodes[MAX_TREE_SIZE];	/* 節點陣列 */
	int r,n;					/* 根的位置和節點數 */
} CTree;



/* 樹的孩子兄弟表示法結構定義 */
typedef struct CSNode
{
	TElemType data;	
	struct CSNode *firstchild,*rightsib;	
} CSNode,*CSTree;



/* 二元樹的二叉鏈結串列節點結構定義 */
typedef struct BiTNode  			/* 節點結構 */
{
   TElemType data;					/* 節點資料 */
   struct BiTNode *lchild,*rchild; 	/* 左右孩子指標 */
}BiTNode,*BiTree;


/* 二元樹的前序檢查遞歸算法 */
/* 起始條件: 二元樹T存在 */
/* 動作結果: 前序遞歸檢查T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);		/* 顯示節點資料，可以變更為其它對節點動作 */
	PreOrderTraverse(T->lchild);/* 再先序檢查左子樹 */
	PreOrderTraverse(T->rchild);/* 最後先序檢查右子樹 */
}

/* 二元樹的中序檢查遞歸算法 */
/* 起始條件: 二元樹T存在 */
/* 動作結果: 中序遞歸檢查T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序檢查左子樹 */
	printf("%c",T->data);		/* 顯示節點資料，可以變更為其它對節點動作 */
	InOrderTraverse(T->rchild); /* 最後中序檢查右子樹 */
}

/* 二元樹的後序檢查遞歸算法 */
/* 起始條件: 二元樹T存在 */
/* 動作結果: 後序遞歸檢查T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 	/* 先後序檢查左子樹  */
	PostOrderTraverse(T->rchild); 	/* 再後序檢查右子樹  */
	printf("%c",T->data);			/* 顯示節點資料，可以變更為其它對節點動作 */
}

/* 按前序輸入二元樹中節點的值（一個字元） */
/* #表示空樹，建構二叉鏈結串列表示二元樹T。 */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	
	scanf("%c",&ch);
	ch=str[index++];

	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; 					/* 產生根節點 */
		CreateBiTree(&(*T)->lchild); 	/* 建構左子樹 */
		CreateBiTree(&(*T)->rchild); 	/* 建構右子樹 */
	}
}

/* 二元樹的二叉線索儲存結構定義 */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0表示指向左右孩子指標, */
										/* Thread==1表示指向前驅或後繼的線索 */
typedef  struct BiThrNode				/* 二叉線索儲存節點結構 */
{
	TElemType data;						/* 節點資料 */
	struct BiThrNode *lchild, *rchild;	/* 左右孩子指標 */
	PointerTag LTag;
	PointerTag RTag;					/* 左右標志 */
} BiThrNode, *BiThrTree;


BiThrTree pre; 					/* 全局變數,始終指向剛剛存取過的節點 */
/* 中序檢查進行中序線索化 */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* 遞歸左子樹線索化 */
		if(!p->lchild) 			/* 沒有左孩子 */
		{
			p->LTag=Thread; 	/* 前驅線索 */
			p->lchild=pre; 		/* 左孩子指標指向前驅 */
		}
		if(!pre->rchild) 		/* 前驅沒有右孩子 */
		{
			pre->RTag=Thread; 	/* 後繼線索 */
			pre->rchild=p; 		/* 前驅右孩子指標指向後繼(目前節點p) */
		}
		pre=p; 					/* 保持pre指向p的前驅 */
		InThreading(p->rchild); /* 遞歸右子樹線索化 */
	}
}













































































































































































































































































































































































































































































































































































































































































































































































































































































/* T指向頭節點，頭節點左鏈lchild指向根節點，頭節點右鏈rchild指向中序檢查的*/
/* 最後一個節點。中序檢查二叉線索鏈結串列表示的二元樹T */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; 					/* p指向根節點 */
	while(p!=T)						/* 空樹或檢查結束時,p==T */
	{ 
		while(p->LTag==Link)		/*當LTag==0時循環到中序序列第一個節點 */
			p=p->lchild;
		printf（"%c",p->data）; 		/* 顯示節點資料，可以變更為其他對節點動作 */
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf（"%c",p->data）;	/* 存取後繼節點 */
		}
		p=p->rchild;				/*  p進至其右子樹根 */
	}
	return OK;
}


if （a<60）
	b=〞不及格〞;
else if （a<70）
	b=〞及格〞;
else if （a<80）
	b=〞中等〞;
else if （a<90）
	b=〞良好〞;
else 
	b=〞優秀〞;




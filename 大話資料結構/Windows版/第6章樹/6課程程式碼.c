
/* ¡¼äî¡¼¡¼ŸÌ¡¼¡¼¬á¡¼ */
#define MAX_TREE_SIZE 100

typedef int TElemType;				/* ¡¼¡¼¡¼¡¼”ã¡¼¡¼†g¡¼¡¼¡¼¡¼ */

typedef struct PTNode				/* ¡¼¡¼ö¿*/
{
	TElemType data;					/* ¡¼¡¼•D*/
	int parent;						/* ¡¼¡¼£f¡¼ */
} PTNode;

typedef struct						/* ¡¼¡¼Ãþ§O/
{
	PTNode nodes[MAX_TREE_SIZE];	/* ¡¼¡¼¡¼ */
	int r,n;						/* Ãà¡¼¡¼¡¼¡¼¡¼ */
} PTree;


/* ¡¼õÀ¡¼¡¼ŸÌ¡¼õ©¡¼ */
#define MAX_TREE_SIZE 100

typedef int TElemType;			/* ¡¼¡¼¡¼¡¼”ã¡¼¡¼†g¡¼¡¼¡¼¡¼ */

typedef struct CTNode			/* ¡¼¡¼¡¼ */
{
	int child;	
	struct CTNode *next;	
} *ChildPtr;

typedef struct 					/* ¡¼Ó\ö¿*/
{
	TElemType data;	
	ChildPtr firstchild;	
} CTBox;

typedef struct	     			/* ¡¼¡¼Ãþ§O/
{
	CTBox nodes[MAX_TREE_SIZE];	/* ¡¼¡¼¡¼ */
	int r,n;					/* Ãà¡¼¡¼¡¼¡¼¡¼ */
} CTree;



/* ¡¼õÀ¡¼¡¼¦é¡¼½]¡¼¡¼³ô/
typedef struct CSNode
{
	TElemType data;	
	struct CSNode *firstchild,*rightsib;	
} CSNode,*CSTree;



/* êE¡¼ÄâÄt¡¼¡¼¡¼õ©¡¼ */
typedef struct BiTNode  			/* ¡¼¡¼ö¿*/
{
   TElemType data;					/* ¡¼¡¼•D*/
   struct BiTNode *lchild,*rchild; 	/* ¡¼¡¼¡¼¡¼êú */
}BiTNode,*BiTree;


/* êE¡¼äë¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼¥Þ¡¼:T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);		/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
	PreOrderTraverse(T->lchild);/* ¡¼£r¡¼¡¼¡¼¡¼¡¼ */
	PreOrderTraverse(T->rchild);/* ¡¼¡¼¡¼¡¼:¡¼¡¼¡¼ */
}

/* êE¡¼ºÊ¡¼¡¼:¥Þ¨¸¸Y*/
/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼¥Þ¡¼:T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	printf("%c",T->data);		/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
	InOrderTraverse(T->rchild); /* ¡¼¡¼¡¼¡¼:¡¼¡¼¡¼ */
}

/* êE¡¼õÀ¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼ÅX»·T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 	/* £r¡¼¡¼:¡¼¡¼¡¼  */
	PostOrderTraverse(T->rchild); 	/* ¡¼¡¼¡¼:¡¼¡¼¡¼  */
	printf("%c",T->data);			/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
}

/* ¡¼¡¼¡¼¡¼êE¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Â¸Ãþ§O/
/* #¡¼‚â¡¼¡¼ëàêE¼w¡¼¡¼êE¡¼T¡¼*/
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
		(*T)->data=ch; 					/* ¡¼¡¼ÄÖÃb*/
		CreateBiTree(&(*T)->lchild); 	/* øe¡¼¡¼¡¼ */
		CreateBiTree(&(*T)->rchild); 	/* øe¡¼¡¼¡¼ */
	}
}

/* êE¡¼ÄâÄ¡¼¡¼¡¼¡¼¬á¡¼ */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0¡¼’s¡¼¡¼¡¼¡¼¡¼êú, */
										/* Thread==1¡¼’s¡¼¡¼¡¼¡¼¡¼ßT¡¼Òä/
typedef  struct BiThrNode				/* êEÙc¡¼¡¼¡¼¹Ø¡¼ */
{
	TElemType data;						/* ¡¼¡¼•D*/
	struct BiThrNode *lchild, *rchild;	/* ¡¼¡¼¡¼¡¼êú */
	PointerTag LTag;
	PointerTag RTag;					/* ¡¼¡¼¡¼–q/
} BiThrNode, *BiThrTree;


BiThrTree pre; 					/* ¡¼’l¡¼,¡¼¡¼¡¼¡¼îE¡¼I¡¼¡¼¡¼¡¼/
/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* ¥Þ¶£¡¼¡¼¡¼¡¼¡¼*/
		if(!p->lchild) 			/* u¡¼¡¼¡¼¡¼*/
		{
			p->LTag=Thread; 	/* ¡¼¡¼¡¼¡¼ */
			p->lchild=pre; 		/* ¡¼¡¼¡¼êú¡¼¡¼¡¼¡¼ */
		}
		if(!pre->rchild) 		/* ¡¼¡¼u¡¼¡¼¡¼¡¼*/
		{
			pre->RTag=Thread; 	/* ¡¼¡¼¡¼Òä/
			pre->rchild=p; 		/* ¡¼¡¼¡¼¡¼¡¼êú¡¼¡¼¡¼¡¼ÌZ¡¼Án) */
		}
		pre=p; 					/* ¡¼¡¼re¡¼¡¼päë¡¼ */
		InThreading(p->rchild); /* ¥Þäz¡¼¡¼¡¼¡¼¡¼*/
	}
}













































































































































































































































































































































































































































































































































































































































































































































































































































































/* T¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼tlchild¡¼¡¼¡¼¡¼¡¼Ó\À£¡¼¡¼hild¡¼¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ë^¡¼¡¼ÄâÄ¡¼T */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; 					/* p¡¼¡¼¡¼¡¼ */
	while(p!=T)						/* ‹Òãl¡¼¡¼¡¼¡¼,p==T */
	{ 
		while(p->LTag==Link)		/*ÎxTag==0¡¼¡¼¡¼¡¼¡¼¡¼P»ò¡¼¡¼¡¼/
			p=p->lchild;
		printf¡¼%c",p->data¡¼ 		/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf¡¼%c",p->data¡¼	/* Ò{¡¼¡¼¡¼¡¼/
		}
		p=p->rchild;				/*  p¡¼F¡¼¡¼¡¼ðù*/
	}
	return OK;
}


if ¡¼<60¡¼	b=¡¼¡¼¡¼¡¼else if ¡¼<70¡¼	b=¡¼¡¼¡¼
else if ¡¼<80¡¼	b=¡¼¡¼¡¼¡¼else if ¡¼<90¡¼	b=¡¼¡¼¡¼
else 
	b=¡¼¡¼¡¼;




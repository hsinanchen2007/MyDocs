
/* ������̡����᡼ */
#define MAX_TREE_SIZE 100

typedef int TElemType;				/* ���������㡼���g�������� */

typedef struct PTNode				/* ������*/
{
	TElemType data;					/* �����D*/
	int parent;						/* �����f�� */
} PTNode;

typedef struct						/* �������O/
{
	PTNode nodes[MAX_TREE_SIZE];	/* ������ */
	int r,n;						/* �ࡼ�������� */
} PTree;


/* ���������̡����� */
#define MAX_TREE_SIZE 100

typedef int TElemType;			/* ���������㡼���g�������� */

typedef struct CTNode			/* ������ */
{
	int child;	
	struct CTNode *next;	
} *ChildPtr;

typedef struct 					/* ���\��*/
{
	TElemType data;	
	ChildPtr firstchild;	
} CTBox;

typedef struct	     			/* �������O/
{
	CTBox nodes[MAX_TREE_SIZE];	/* ������ */
	int r,n;					/* �ࡼ�������� */
} CTree;



/* ���������顼�]������/
typedef struct CSNode
{
	TElemType data;	
	struct CSNode *firstchild,*rightsib;	
} CSNode,*CSTree;



/* �E�����t���������� */
typedef struct BiTNode  			/* ������*/
{
   TElemType data;					/* �����D*/
   struct BiTNode *lchild,*rchild; 	/* ���������� */
}BiTNode,*BiTree;


/* �E���롼�������� */
/* ������ �E��T����*/
/* ���\� �����ޡ�:T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);		/* ���������G�����顼������������/
	PreOrderTraverse(T->lchild);/* ���r���������� */
	PreOrderTraverse(T->rchild);/* ��������:������ */
}

/* �E���ʡ���:�ި��Y*/
/* ������ �E��T����*/
/* ���\� �����ޡ�:T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������ */
	printf("%c",T->data);		/* ���������G�����顼������������/
	InOrderTraverse(T->rchild); /* ��������:������ */
}

/* �E�������������� */
/* ������ �E��T����*/
/* ���\� �����X��T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 	/* �r����:������  */
	PostOrderTraverse(T->rchild); 	/* ������:������  */
	printf("%c",T->data);			/* ���������G�����顼������������/
}

/* ���������E����������������¸���O/
/* #���⡼�����E�w�����E��T��*/
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
		(*T)->data=ch; 					/* �������b*/
		CreateBiTree(&(*T)->lchild); 	/* �e������ */
		CreateBiTree(&(*T)->rchild); 	/* �e������ */
	}
}

/* �E����ġ��������᡼ */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0���s������������, */
										/* Thread==1���s�����������T����/
typedef  struct BiThrNode				/* �E�c�������ء� */
{
	TElemType data;						/* �����D*/
	struct BiThrNode *lchild, *rchild;	/* ���������� */
	PointerTag LTag;
	PointerTag RTag;					/* �������q/
} BiThrNode, *BiThrTree;


BiThrTree pre; 					/* ���l��,���������E��I��������/
/* ��������������������*/
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* �޶�����������*/
		if(!p->lchild) 			/* u��������*/
		{
			p->LTag=Thread; 	/* �������� */
			p->lchild=pre; 		/* ���������������� */
		}
		if(!pre->rchild) 		/* ����u��������*/
		{
			pre->RTag=Thread; 	/* ��������/
			pre->rchild=p; 		/* ���������������������Z���n) */
		}
		pre=p; 					/* ����re����p�롼 */
		InThreading(p->rchild); /* ���z����������*/
	}
}













































































































































































































































































































































































































































































































































































































































































































































































































































































/* T����������������tlchild�����������\������hild������������*/
/* �����������������������^������ġ�T */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; 					/* p�������� */
	while(p!=T)						/* ���l��������,p==T */
	{ 
		while(p->LTag==Link)		/*�xTag==0������������P�򡼡���/
			p=p->lchild;
		printf��%c",p->data�� 		/* ���������G�����顼������������/
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf��%c",p->data��	/* �{��������/
		}
		p=p->rchild;				/*  p��F��������*/
	}
	return OK;
}


if ��<60��	b=��������else if ��<70��	b=������
else if ��<80��	b=��������else if ��<90��	b=������
else 
	b=������;




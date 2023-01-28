
/* �����˪�ܪk�`�I���c�w�q */
#define MAX_TREE_SIZE 100

typedef int TElemType;				/* ��`�I����ƫ��A�A�ثe�ȩw����� */

typedef struct PTNode				/* �`�I���c */
{
	TElemType data;					/* �`�I��� */
	int parent;						/* ���˦�m */
} PTNode;

typedef struct						/* �𵲺c */
{
	PTNode nodes[MAX_TREE_SIZE];	/* �`�I�}�C */
	int r,n;						/* �ڪ���m�M�`�I�� */
} PTree;


/* �𪺫Ĥl��ܪk���c�w�q */
#define MAX_TREE_SIZE 100

typedef int TElemType;			/* ��`�I����ƫ��A�A�ثe�ȩw����� */

typedef struct CTNode			/* �Ĥl�`�I */
{
	int child;	
	struct CTNode *next;	
} *ChildPtr;

typedef struct 					/* ���Y���c */
{
	TElemType data;	
	ChildPtr firstchild;	
} CTBox;

typedef struct	     			/* �𵲺c */
{
	CTBox nodes[MAX_TREE_SIZE];	/* �`�I�}�C */
	int r,n;					/* �ڪ���m�M�`�I�� */
} CTree;



/* �𪺫Ĥl�S�̪�ܪk���c�w�q */
typedef struct CSNode
{
	TElemType data;	
	struct CSNode *firstchild,*rightsib;	
} CSNode,*CSTree;



/* �G���𪺤G�e�쵲��C�`�I���c�w�q */
typedef struct BiTNode  			/* �`�I���c */
{
   TElemType data;					/* �`�I��� */
   struct BiTNode *lchild,*rchild; 	/* ���k�Ĥl���� */
}BiTNode,*BiTree;


/* �G���𪺫e���ˬd���k��k */
/* �_�l����: �G����T�s�b */
/* �ʧ@���G: �e�ǻ��k�ˬdT */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);		/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
	PreOrderTraverse(T->lchild);/* �A�����ˬd���l�� */
	PreOrderTraverse(T->rchild);/* �̫�����ˬd�k�l�� */
}

/* �G���𪺤����ˬd���k��k */
/* �_�l����: �G����T�s�b */
/* �ʧ@���G: ���ǻ��k�ˬdT */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* �����ˬd���l�� */
	printf("%c",T->data);		/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
	InOrderTraverse(T->rchild); /* �̫ᤤ���ˬd�k�l�� */
}

/* �G���𪺫���ˬd���k��k */
/* �_�l����: �G����T�s�b */
/* �ʧ@���G: ��ǻ��k�ˬdT */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 	/* ������ˬd���l��  */
	PostOrderTraverse(T->rchild); 	/* �A����ˬd�k�l��  */
	printf("%c",T->data);			/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
}

/* ���e�ǿ�J�G���𤤸`�I���ȡ]�@�Ӧr���^ */
/* #��ܪž�A�غc�G�e�쵲��C��ܤG����T�C */
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
		(*T)->data=ch; 					/* ���ͮڸ`�I */
		CreateBiTree(&(*T)->lchild); 	/* �غc���l�� */
		CreateBiTree(&(*T)->rchild); 	/* �غc�k�l�� */
	}
}

/* �G���𪺤G�e�u���x�s���c�w�q */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0��ܫ��V���k�Ĥl����, */
										/* Thread==1��ܫ��V�e�X�Ϋ��~���u�� */
typedef  struct BiThrNode				/* �G�e�u���x�s�`�I���c */
{
	TElemType data;						/* �`�I��� */
	struct BiThrNode *lchild, *rchild;	/* ���k�Ĥl���� */
	PointerTag LTag;
	PointerTag RTag;					/* ���k�Ч� */
} BiThrNode, *BiThrTree;


BiThrTree pre; 					/* �����ܼ�,�l�׫��V���s���L���`�I */
/* �����ˬd�i�椤�ǽu���� */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* ���k���l��u���� */
		if(!p->lchild) 			/* �S�����Ĥl */
		{
			p->LTag=Thread; 	/* �e�X�u�� */
			p->lchild=pre; 		/* ���Ĥl���Ы��V�e�X */
		}
		if(!pre->rchild) 		/* �e�X�S���k�Ĥl */
		{
			pre->RTag=Thread; 	/* ���~�u�� */
			pre->rchild=p; 		/* �e�X�k�Ĥl���Ы��V���~(�ثe�`�Ip) */
		}
		pre=p; 					/* �O��pre���Vp���e�X */
		InThreading(p->rchild); /* ���k�k�l��u���� */
	}
}













































































































































































































































































































































































































































































































































































































































































































































































































































































/* T���V�Y�`�I�A�Y�`�I����lchild���V�ڸ`�I�A�Y�`�I�k��rchild���V�����ˬd��*/
/* �̫�@�Ӹ`�I�C�����ˬd�G�e�u���쵲��C��ܪ��G����T */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; 					/* p���V�ڸ`�I */
	while(p!=T)						/* �ž���ˬd������,p==T */
	{ 
		while(p->LTag==Link)		/*��LTag==0�ɴ`���줤�ǧǦC�Ĥ@�Ӹ`�I */
			p=p->lchild;
		printf�]"%c",p->data�^; 		/* ��ܸ`�I��ơA�i�H�ܧ󬰨�L��`�I�ʧ@ */
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf�]"%c",p->data�^;	/* �s�����~�`�I */
		}
		p=p->rchild;				/*  p�i�ܨ�k�l��� */
	}
	return OK;
}


if �]a<60�^
	b=�����ή桪;
else if �]a<70�^
	b=���ή桪;
else if �]a<80�^
	b=��������;
else if �]a<90�^
	b=���}�n��;
else 
	b=���u�q��;




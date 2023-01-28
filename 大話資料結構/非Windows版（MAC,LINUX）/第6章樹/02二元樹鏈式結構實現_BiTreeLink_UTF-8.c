#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;		/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */

/* �Ω�غc�G����********************************** */
int treeIndex=1;
typedef char String[24]; /*  0���椸�s��ꪺ���� */
String str;

Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
/* ************************************************ */

typedef char TElemType;
TElemType Nil=' '; /* �r�����H�Ů�Ŭ��� */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* �`�I���c */
{
   TElemType data;		/* �`�I��� */
   struct BiTNode *lchild,*rchild; /* ���k�Ĥl���� */
}BiTNode,*BiTree;


/* �غc�ŤG����T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* �_�l����: �G����T�s�b�C�ʧ@���G: �P���G����T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* �����Ĥl */
			DestroyBiTree(&(*T)->lchild); /* �P�����Ĥl�l�� */
		if((*T)->rchild) /* ���k�Ĥl */
			DestroyBiTree(&(*T)->rchild); /* �P���k�Ĥl�l�� */
		free(*T); /* ����ڸ`�I */
		*T=NULL; /* �ū��н�0 */
	}
}

/* ���e�ǿ�J�G���𤤸`�I���ȡ]�@�Ӧr���^ */
/* #��ܪž�A�غc�G�e�쵲��C��ܤG����T�C */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	
	/* scanf("%c",&ch); */
	ch=str[treeIndex++];

	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* ���ͮڸ`�I */
		CreateBiTree(&(*T)->lchild); /* �غc���l�� */
		CreateBiTree(&(*T)->rchild); /* �غc�k�l�� */
	}
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: �YT���ŤG����,�h�Ǧ^TRUE,�_�hFALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* �_�l����: �G����T�s�b�C�ʧ@���G: �Ǧ^T���`�� */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}

/* �_�l����: �G����T�s�b�C�ʧ@���G: �Ǧ^T���� */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* �_�l����: �G����T�s�b�Ap���VT���Y�Ӹ`�I */
/* �ʧ@���G: �Ǧ^p�ҫ��`�I���� */
TElemType Value(BiTree p)
{
	return p->data;
}

/* ��p�ҫ��`�I�����Ȭ�value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: �e�ǻ��k�ˬdT */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
	PreOrderTraverse(T->lchild); /* �A�����ˬd���l�� */
	PreOrderTraverse(T->rchild); /* �̫�����ˬd�k�l�� */
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: ���ǻ��k�ˬdT */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* �����ˬd���l�� */
	printf("%c",T->data);/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
	InOrderTraverse(T->rchild); /* �̫ᤤ���ˬd�k�l�� */
}

/* �_�l����: �G����T�s�b */
/* �ʧ@���G: ��ǻ��k�ˬdT */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* ������ˬd���l��  */
	PostOrderTraverse(T->rchild); /* �A����ˬd�k�l��  */
	printf("%c",T->data);/* ��ܸ`�I��ơA�i�H�ܧ󬰨䥦��`�I�ʧ@ */
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("�غc�ŤG�����,��ŧ_�H%d(1:�O 0:�_) �𪺲`��=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("�G���𪺮ڬ�: %c\n",e1);

	printf("\n�e���ˬd�G����:");
	PreOrderTraverse(T);
	printf("\n�����ˬd�G����:");
	InOrderTraverse(T);
	printf("\n����ˬd�G����:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n�M���G�����,��ŧ_�H%d(1:�O 0:�_) �𪺲`��=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("��šA�L��\n");
	
	return 0;
}

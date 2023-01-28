#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ��������æ�� */

typedef int Status;		/* Status������ ��,���������������á���OK�R*/

/* �����e������******************************** */
int treeIndex=1;
typedef char String[24]; /*  0���w�����š���*/
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
TElemType Nil=' '; /* ��������������*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* ������*/
{
   TElemType data;		/* �����D*/
   struct BiTNode *lchild,*rchild; /* ���������� */
}BiTNode,*BiTree;


/* �e���E��T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* ������ �E��T�����������������ġ�T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ��������*/
			DestroyBiTree(&(*T)->lchild); /* ������������ */
		if((*T)->rchild) /* ��������*/
			DestroyBiTree(&(*T)->rchild); /* ������������ */
		free(*T); /* ���t���b*/
		*T=NULL; /* ����� */
	}
}

/* ���������E����������������¸���O/
/* #���⡼�����E�w�����E��T��*/
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
		(*T)->data=ch; /* �������b*/
		CreateBiTree(&(*T)->lchild); /* �e������ */
		CreateBiTree(&(*T)->rchild); /* �e������ */
	}
}

/* ������ �E��T����*/
/* ���\� ��T�����ġ�,���_��RUE,�䡼LSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* ������ �E��T�������������_�����J */
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

/* ������ �E��T�������������_�������O/
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ������ �E��T��������T�������� */
/* ���\� �_������������ */
TElemType Value(BiTree p)
{
	return p->data;
}

/* �ơ�����������value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* ������ �E��T����*/
/* ���\� �����ޡ�:T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ���������G�����顼������������/
	PreOrderTraverse(T->lchild); /* ���r���������� */
	PreOrderTraverse(T->rchild); /* ��������:������ */
}

/* ������ �E��T����*/
/* ���\� �����ޡ�:T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������ */
	printf("%c",T->data);/* ���������G�����顼������������/
	InOrderTraverse(T->rchild); /* ��������:������ */
}

/* ������ �E��T����*/
/* ���\� �����X��T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* �r����:������  */
	PostOrderTraverse(T->rchild); /* ������:������  */
	printf("%c",T->data);/* ���������G�����顼������������/
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("�e���E�������@��%d(1:�� 0:�� �����J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("�E�����\: %c\n",e1);

	printf("\n������������);
	PreOrderTraverse(T);
	printf("\n������������);
	InOrderTraverse(T);
	printf("\n����:�E��:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n�����ġ������@��%d(1:�� 0:�� �����J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("���롼��n");
	
	return 0;
}

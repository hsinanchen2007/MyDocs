#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ーーー釦脱ー */

typedef int Status;		/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/

/* ーー�eーー菜******************************** */
int treeIndex=1;
typedef char String[24]; /*  0ー�wーー�邸次�*/
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
TElemType Nil=' '; /* ー幎ーーーーー��*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* ーー��*/
{
   TElemType data;		/* ーー�D*/
   struct BiTNode *lchild,*rchild; /* ーーーー褸 */
}BiTNode,*BiTree;


/* �eー�EーT */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* ーーー �EーTーーーーーーーー�帖�T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ーーーー*/
			DestroyBiTree(&(*T)->lchild); /* ーーーーーー */
		if((*T)->rchild) /* ーーーー*/
			DestroyBiTree(&(*T)->rchild); /* ーーーーーー */
		free(*T); /* ー�t綴�b*/
		*T=NULL; /* �溯�觀 */
	}
}

/* ーーーー�Eーーーーーーーー存寵�O/
/* #ー�癲次朱琲E�wーー�EーTー*/
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
		(*T)->data=ch; /* ーー綴�b*/
		CreateBiTree(&(*T)->lchild); /* �eーーー */
		CreateBiTree(&(*T)->rchild); /* �eーーー */
	}
}

/* ーーー �EーTーー*/
/* ー�\豢 ーTー���帖�,ー�_ーRUE,�筺�LSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* ーーー �EーTーーーーーー�_ー慈�J */
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

/* ーーー �EーTーーーーーー�_ー椿寵�O/
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ーーー �EーTーーー求Tーーーー */
/* ー�\豢 �_ーーーーーー */
TElemType Value(BiTree p)
{
	return p->data;
}

/* 詁ーーーーーーvalue */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* ーーー �EーTーー*/
/* ー�\豢 ーーマー:T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ーーーー�Gーー翠ーーー盟ーー吮/
	PreOrderTraverse(T->lchild); /* ー�rーーーーー */
	PreOrderTraverse(T->rchild); /* ーーーー:ーーー */
}

/* ーーー �EーTーー*/
/* ー�\豢 ーーマー:T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ーーーーーー */
	printf("%c",T->data);/* ーーーー�Gーー翠ーーー盟ーー吮/
	InOrderTraverse(T->rchild); /* ーーーー:ーーー */
}

/* ーーー �EーTーー*/
/* ー�\豢 ーー�X桟T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* �rーー:ーーー  */
	PostOrderTraverse(T->rchild); /* ーーー:ーーー  */
	printf("%c",T->data);/* ーーーー�Gーー翠ーーー盟ーー吮/
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("�eー�Eーーー�@ー%d(1:ー 0:�� ー慈�J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("�Eー椿�\: %c\n",e1);

	printf("\nーーーーー��);
	PreOrderTraverse(T);
	printf("\nーーーーー��);
	InOrderTraverse(T);
	printf("\nーー:�Eー:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\nーー�帖次次��@ー%d(1:ー 0:�� ー慈�J=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("ー�襦腫�n");
	
	return 0;
}

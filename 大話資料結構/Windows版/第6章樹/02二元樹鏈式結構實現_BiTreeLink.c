#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status;		/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/

/* ¡¼¡¼øe¡¼¡¼ºÚ******************************** */
int treeIndex=1;
typedef char String[24]; /*  0¡¼Ôw¡¼¡¼Å¡¼¡¼*/
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
TElemType Nil=' '; /* ¡¼Öí¡¼¡¼¡¼¡¼¡¼‹è*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* ¡¼¡¼ö¿*/
{
   TElemType data;		/* ¡¼¡¼•D*/
   struct BiTNode *lchild,*rchild; /* ¡¼¡¼¡¼¡¼êú */
}BiTNode,*BiTree;


/* øe¡¼êE¡¼T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ä¡¼T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ¡¼¡¼¡¼¡¼*/
			DestroyBiTree(&(*T)->lchild); /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
		if((*T)->rchild) /* ¡¼¡¼¡¼¡¼*/
			DestroyBiTree(&(*T)->rchild); /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
		free(*T); /* ¡¼ŞtÄÖÃb*/
		*T=NULL; /* ‹Şêúë· */
	}
}

/* ¡¼¡¼¡¼¡¼êE¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Â¸Ãş§O/
/* #¡¼‚â¡¼¡¼ëàêE¼w¡¼¡¼êE¡¼T¡¼*/
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
		(*T)->data=ch; /* ¡¼¡¼ÄÖÃb*/
		CreateBiTree(&(*T)->lchild); /* øe¡¼¡¼¡¼ */
		CreateBiTree(&(*T)->rchild); /* øe¡¼¡¼¡¼ */
	}
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼T¡¼‹şÄ¡¼,¡¼ß_¡¼RUE,õä¡¼LSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼»üŸJ */
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

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼ÄØÃş§O/
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼¡¼µáT¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ß_¡¼¡¼¡¼¡¼¡¼¡¼ */
TElemType Value(BiTree p)
{
	return p->data;
}

/* ëÆ¡¼¡¼¡¼¡¼¡¼¡¼value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼¥Ş¡¼:T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
	PreOrderTraverse(T->lchild); /* ¡¼£r¡¼¡¼¡¼¡¼¡¼ */
	PreOrderTraverse(T->rchild); /* ¡¼¡¼¡¼¡¼:¡¼¡¼¡¼ */
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼¥Ş¡¼:T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ¡¼¡¼¡¼¡¼¡¼¡¼ */
	printf("%c",T->data);/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
	InOrderTraverse(T->rchild); /* ¡¼¡¼¡¼¡¼:¡¼¡¼¡¼ */
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼ÅX»·T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* £r¡¼¡¼:¡¼¡¼¡¼  */
	PostOrderTraverse(T->rchild); /* ¡¼¡¼¡¼:¡¼¡¼¡¼  */
	printf("%c",T->data);/* ¡¼¡¼¡¼¡¼•G¡¼¡¼¿é¡¼¡¼¡¼ÌÁ¡¼¡¼Òä/
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("øe¡¼êE¡¼¡¼¡¼Œ@¡¼%d(1:¡¼ 0:øû ¡¼»üŸJ=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("êE¡¼ÄØñ\: %c\n",e1);

	printf("\n¡¼¡¼¡¼¡¼¡¼¬õ);
	PreOrderTraverse(T);
	printf("\n¡¼¡¼¡¼¡¼¡¼¬õ);
	InOrderTraverse(T);
	printf("\n¡¼¡¼:êE¡¼:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n¡¼¡¼Ä¡¼¡¼¡¼Œ@¡¼%d(1:¡¼ 0:øû ¡¼»üŸJ=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("¡¼‹ë¡¼ğ÷n");
	
	return 0;
}

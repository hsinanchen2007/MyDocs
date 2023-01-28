#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* °º°º°ºÀ’√¶°º */

typedef int Status;	/* Status°º°º°º °º,°º°º°º°º°º°º°º∂√°ºœ÷ßR*/
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0°ºís°º°º°º°º°ºÍ˙, */
										/* Thread==1°ºís°º°º°º°º°ºﬂT°º“‰/
typedef  struct BiThrNode	/* ÍEŸc°º°º°ºπÿ°º */
{
	TElemType data;	/* °º°ºïD*/
	struct BiThrNode *lchild, *rchild;	/* °º°º°º°ºÍ˙ */
	PointerTag LTag;
	PointerTag RTag;		/* °º°º°ºñq/
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* °º÷Ì°º°º°º°º°ºãË*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* °º°º°º°ºÍEŸc°º°º°º°º°º°º,¯e°º°º°º¬xT */
/* 0(°º°º)/åA°º°º°º)°ºÇ‚°º°º/
Status CreateBiThrTree(BiThrTree *T)
{ 
	TElemType h;
	scanf("%c",&h);

	if(h==Nil)
		*T=NULL;
	else
	{
		*T=(BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=h; /* °º°ºƒ÷˜“°º°º) */
		CreateBiThrTree(&(*T)->lchild); /* •ﬁƒ–°º°º°º°º */
		if((*T)->lchild) /* °º°º°º°º*/
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* •ﬁƒ–°º°º°º°º */
		if((*T)->rchild) /* °º°º°º°º*/
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* °ºíl°º,°º°º°º°ºÓE°ºI°º°º°º°º/
/* °º°º°º°º°º°º°º°º°º°º*/
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* •ﬁ∂£°º°º°º°º°º*/
		if(!p->lchild) /* u°º°º°º°º*/
		{
			p->LTag=Thread; /* °º°º°º°º */
			p->lchild=pre; /* °º°º°ºÍ˙°º°º°º°º */
		}
		if(!pre->rchild) /* °º°ºu°º°º°º°º*/
		{
			pre->RTag=Thread; /* °º°º°º“‰/
			pre->rchild=p; /* °º°º°º°º°ºÍ˙°º°º°º°ºÃZ°º¡n) */
		}
		pre=p; /* °º°ºre°º°ºp‰Î°º */
		InThreading(p->rchild); /* •ﬁ‰z°º°º°º°º°º*/
	}
}

/* °º°º°º°º°º®i°º°º°º°º°º°º°ºThrt°º°º°º°º°º/
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* °º”\√b*/
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* °º°º°º°º˜P/
	if(!T) /* °ºÍE°ºãÙ°º°º°º°º°º˜P/
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* °º°º°º°º°º°º°º°º°º°º*/
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* °º°º°º°º°º°º°º*/
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* °º°º°º°º°º°º¬xT(°º°º°º°º°º°º®∏∏Y*/
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* p°º°º°º°º */
	while(p!=T)
	{ /* ã“„l°º°º°º°º,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* “{°º°º°º°º°ºã˝°º°º */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* “{°º°º°º°º/
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("°º°º°º°º°ºÍE°º(°º:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* °º°º°º°º°º“‰/
	InOrderThreading(&H,T); /* °º°º°º°º°º°º°º°º°ºùƒ°º */
	printf("°º°º°º°º°º)ÍEŸc°º°º:\n");
	InOrderTraverse_Thr(H); /* °º°º°º°º°º)ÍEŸc°º°º */
	printf("\n");
	
	return 0;
}



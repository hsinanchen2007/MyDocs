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

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ー�屶R*/
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0ー�sーーーーー褸, */
										/* Thread==1ー�sーーーーー�Tー吮/
typedef  struct BiThrNode	/* �E�cーーー購ー */
{
	TElemType data;	/* ーー�D*/
	struct BiThrNode *lchild, *rchild;	/* ーーーー褸 */
	PointerTag LTag;
	PointerTag RTag;		/* ーーー�q/
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* ー幎ーーーーー��*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* ーーーー�E�cーーーーーー,�eーーー�xT */
/* 0(ーー)/�Aーーー)ー�癲次�/
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
		(*T)->data=h; /* ーー綴�辧次�) */
		CreateBiThrTree(&(*T)->lchild); /* マ槻ーーーー */
		if((*T)->lchild) /* ーーーー*/
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* マ槻ーーーー */
		if((*T)->rchild) /* ーーーー*/
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* ー�lー,ーーーー�EーIーーーー/
/* ーーーーーーーーーー*/
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* マ僑ーーーーー*/
		if(!p->lchild) /* uーーーー*/
		{
			p->LTag=Thread; /* ーーーー */
			p->lchild=pre; /* ーーー褸ーーーー */
		}
		if(!pre->rchild) /* ーーuーーーー*/
		{
			pre->RTag=Thread; /* ーーー吮/
			pre->rchild=p; /* ーーーーー褸ーーーー�Zー�n) */
		}
		pre=p; /* ーーreーーp粳ー */
		InThreading(p->rchild); /* マ�zーーーーー*/
	}
}

/* ーーーーー�iーーーーーーーThrtーーーーー/
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* ー�\�b*/
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* ーーーー�P/
	if(!T) /* ー�Eー�堯次次次次寿P/
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* ーーーーーーーーーー*/
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* ーーーーーーー*/
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* ーーーーーー�xT(ーーーーーー┯�Y*/
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* pーーーー */
	while(p!=T)
	{ /* �吼lーーーー,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* �{ーーーーー��ーー */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* �{ーーーー/
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("ーーーーー�Eー(ー:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* ーーーーー吮/
	InOrderThreading(&H,T); /* ーーーーーーーーー�帖� */
	printf("ーーーーー)�E�cーー:\n");
	InOrderTraverse_Thr(H); /* ーーーーー)�E�cーー */
	printf("\n");
	
	return 0;
}



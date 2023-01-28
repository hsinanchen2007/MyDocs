#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 儲存空間起始分配量 */

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼,如OK等 */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0表示指向左右孩子指標, */
										/* Thread==1表示指向前驅或後繼的線索 */
typedef  struct BiThrNode	/* 二叉線索儲存節點結構 */
{
	TElemType data;	/* 節點資料 */
	struct BiThrNode *lchild, *rchild;	/* 左右孩子指標 */
	PointerTag LTag;
	PointerTag RTag;		/* 左右標志 */
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* 字元型以空格符為空 */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* 按前序輸入二叉線索樹中節點的值,建構二叉線索樹T */
/* 0(整數)/空格(字元型)表示空節點 */
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
		(*T)->data=h; /* 產生根節點(前序) */
		CreateBiThrTree(&(*T)->lchild); /* 遞歸建構左子樹 */
		if((*T)->lchild) /* 有左孩子 */
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* 遞歸建構右子樹 */
		if((*T)->rchild) /* 有右孩子 */
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* 全局變數,始終指向剛剛存取過的節點 */
/* 中序檢查進行中序線索化 */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* 遞歸左子樹線索化 */
		if(!p->lchild) /* 沒有左孩子 */
		{
			p->LTag=Thread; /* 前驅線索 */
			p->lchild=pre; /* 左孩子指標指向前驅 */
		}
		if(!pre->rchild) /* 前驅沒有右孩子 */
		{
			pre->RTag=Thread; /* 後繼線索 */
			pre->rchild=p; /* 前驅右孩子指標指向後繼(目前節點p) */
		}
		pre=p; /* 保持pre指向p的前驅 */
		InThreading(p->rchild); /* 遞歸右子樹線索化 */
	}
}

/* 中序檢查二元樹T,並將其中序線索化,Thrt指向頭節點 */
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* 建頭節點 */
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* 右指標回指 */
	if(!T) /* 若二元樹空,則左指標回指 */
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* 中序檢查進行中序線索化 */
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* 最後一個節點線索化 */
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* 中序檢查二叉線索樹T(頭節點)的非遞歸算法 */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* p指向根節點 */
	while(p!=T)
	{ /* 空樹或檢查結束時,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* 存取其左子樹為空的節點 */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* 存取後繼節點 */
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("請按前序輸入二元樹(如:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* 按前序產生二元樹 */
	InOrderThreading(&H,T); /* 中序檢查,並中序線索化二元樹 */
	printf("中序檢查(輸出)二叉線索樹:\n");
	InOrderTraverse_Thr(H); /* 中序檢查(輸出)二叉線索樹 */
	printf("\n");
	
	return 0;
}



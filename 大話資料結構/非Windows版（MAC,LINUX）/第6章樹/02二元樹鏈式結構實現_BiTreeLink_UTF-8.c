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

typedef int Status;		/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */

/* 用於建構二元樹********************************** */
int treeIndex=1;
typedef char String[24]; /*  0號單元存放串的長度 */
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
TElemType Nil=' '; /* 字元型以空格符為空 */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* 節點結構 */
{
   TElemType data;		/* 節點資料 */
   struct BiTNode *lchild,*rchild; /* 左右孩子指標 */
}BiTNode,*BiTree;


/* 建構空二元樹T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* 起始條件: 二元樹T存在。動作結果: 銷毀二元樹T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* 有左孩子 */
			DestroyBiTree(&(*T)->lchild); /* 銷毀左孩子子樹 */
		if((*T)->rchild) /* 有右孩子 */
			DestroyBiTree(&(*T)->rchild); /* 銷毀右孩子子樹 */
		free(*T); /* 釋放根節點 */
		*T=NULL; /* 空指標賦0 */
	}
}

/* 按前序輸入二元樹中節點的值（一個字元） */
/* #表示空樹，建構二叉鏈結串列表示二元樹T。 */
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
		(*T)->data=ch; /* 產生根節點 */
		CreateBiTree(&(*T)->lchild); /* 建構左子樹 */
		CreateBiTree(&(*T)->rchild); /* 建構右子樹 */
	}
}

/* 起始條件: 二元樹T存在 */
/* 動作結果: 若T為空二元樹,則傳回TRUE,否則FALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* 起始條件: 二元樹T存在。動作結果: 傳回T的深度 */
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

/* 起始條件: 二元樹T存在。動作結果: 傳回T的根 */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* 起始條件: 二元樹T存在，p指向T中某個節點 */
/* 動作結果: 傳回p所指節點的值 */
TElemType Value(BiTree p)
{
	return p->data;
}

/* 給p所指節點給予值為value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* 起始條件: 二元樹T存在 */
/* 動作結果: 前序遞歸檢查T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* 顯示節點資料，可以變更為其它對節點動作 */
	PreOrderTraverse(T->lchild); /* 再先序檢查左子樹 */
	PreOrderTraverse(T->rchild); /* 最後先序檢查右子樹 */
}

/* 起始條件: 二元樹T存在 */
/* 動作結果: 中序遞歸檢查T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序檢查左子樹 */
	printf("%c",T->data);/* 顯示節點資料，可以變更為其它對節點動作 */
	InOrderTraverse(T->rchild); /* 最後中序檢查右子樹 */
}

/* 起始條件: 二元樹T存在 */
/* 動作結果: 後序遞歸檢查T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先後序檢查左子樹  */
	PostOrderTraverse(T->rchild); /* 再後序檢查右子樹  */
	printf("%c",T->data);/* 顯示節點資料，可以變更為其它對節點動作 */
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("建構空二元樹後,樹空否？%d(1:是 0:否) 樹的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("二元樹的根為: %c\n",e1);

	printf("\n前序檢查二元樹:");
	PreOrderTraverse(T);
	printf("\n中序檢查二元樹:");
	InOrderTraverse(T);
	printf("\n後序檢查二元樹:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n清除二元樹後,樹空否？%d(1:是 0:否) 樹的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("樹空，無根\n");
	
	return 0;
}

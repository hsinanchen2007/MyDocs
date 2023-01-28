#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 儲存空間起始分配量 */

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */ 

/* 二元樹的二叉鏈結串列節點結構定義 */
typedef  struct BiTNode	/* 節點結構 */
{
	int data;	/* 節點資料 */
	struct BiTNode *lchild, *rchild;	/* 左右孩子指標 */
} BiTNode, *BiTree;


/* 遞歸查詢二叉排序樹T中是否存在key, */
/* 指標f指向T的雙親，其起始呼叫值為NULL */
/* 若查詢成功，則指標p指向該資料元素節點，並傳回TRUE */
/* 否則指標p指向查詢路徑上存取的最後一個節點並傳回FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  查詢不成功 */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  查詢成功 */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  在左子樹中繼續查詢 */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  在右子樹中繼續查詢 */
}


/*  當二叉排序樹T中不存在關鍵字等於key的資料元素時， */
/*  插入key並傳回TRUE，否則傳回FALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* 查詢不成功 */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  插入s為新的根節點 */
		else if (key<p->data) 
			p->lchild = s;	/*  插入s為左孩子 */
		else 
			p->rchild = s;  /*  插入s為右孩子 */
		return TRUE;
	} 
	else 
		return FALSE;  /*  樹中已有關鍵字相同的節點，不再插入 */
}

/* 從二叉排序樹中移除節點p，並重接它的左或右子樹。 */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* 右子樹空則只需重接它的左子樹（待刪節點是葉子也走此分支) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* 只需重接它的右子樹 */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* 左右子樹均不空 */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* 轉左，然後向右到盡頭（找待刪節點的前驅） */
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  s指向被刪節點的直接前驅（將被刪節點前驅的值取代被刪節點的值） */
		if(q!=*p)
			q->rchild=s->lchild; /*  重接q的右子樹 */ 
		else
			q->lchild=s->lchild; /*  重接q的左子樹 */
		free(s);
	}
	return TRUE;
}

/* 若二叉排序樹T中存在關鍵字等於key的資料元素時，則移除該資料元素節點, */
/* 並傳回TRUE；否則傳回FALSE。 */
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* 不存在關鍵字等於key的資料元素 */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* 找到關鍵字等於key的資料元素 */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

int main(void)
{    
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	
	for(i=0;i<10;i++)
	{
		InsertBST(&T, a[i]);
	}
	DeleteBST(&T,93);
	DeleteBST(&T,47);
    printf("本範例建議斷點追蹤檢視二叉排序樹結構");
	return 0;
}

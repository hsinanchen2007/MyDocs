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
	int bf; /*  節點的平衡因子 */ 
	struct BiTNode *lchild, *rchild;	/* 左右孩子指標 */
} BiTNode, *BiTree;


/* 對以p為根的二叉排序樹作右旋處理， */
/* 處理之後p指向新的樹根節點，即旋轉處理之前的左子樹的根節點 */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  L指向P的左子樹根節點 */ 
	(*P)->lchild=L->rchild; /*  L的右子樹掛接為P的左子樹 */ 
	L->rchild=(*P);
	*P=L; /*  P指向新的根節點 */ 
}

/* 對以P為根的二叉排序樹作左旋處理， */
/* 處理之後P指向新的樹根節點，即旋轉處理之前的右子樹的根節點0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  R指向P的右子樹根節點 */ 
	(*P)->rchild=R->lchild; /* R的左子樹掛接為P的右子樹 */ 
	R->lchild=(*P);
	*P=R; /*  P指向新的根節點 */ 
}

#define LH +1 /*  左高 */ 
#define EH 0  /*  等高 */ 
#define RH -1 /*  右高 */ 

/*  對以指標T所指節點為根的二元樹作左平衡旋轉處理 */
/*  本算法結束時，指標T指向新的根節點 */
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  L指向T的左子樹根節點 */ 
	switch(L->bf)
	{ /*  檢查T的左子樹的平衡度，並作對應平衡處理 */ 
		 case LH: /*  新節點插入在T的左孩子的左子樹上，要作單右旋處理 */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  新節點插入在T的左孩子的右子樹上，要作雙旋處理 */ 
			Lr=L->rchild; /*  Lr指向T的左孩子的右子樹根 */ 
			switch(Lr->bf)
			{ /*  修改T及其左孩子的平衡因子 */ 
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); /*  對T的左子樹作左旋平衡處理 */ 
			R_Rotate(T); /*  對T作右旋平衡處理 */ 
	}
}

/*  對以指標T所指節點為根的二元樹作右平衡旋轉處理， */ 
/*  本算法結束時，指標T指向新的根節點 */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  R指向T的右子樹根節點 */ 
	switch(R->bf)
	{ /*  檢查T的右子樹的平衡度，並作對應平衡處理 */ 
	 case RH: /*  新節點插入在T的右孩子的右子樹上，要作單左旋處理 */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  新節點插入在T的右孩子的左子樹上，要作雙旋處理 */ 
			  Rl=R->lchild; 			/*  Rl指向T的右孩子的左子樹根 */ 
			  switch(Rl->bf)
			  { 						/*  修改T及其右孩子的平衡因子 */ 
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); /*  對T的右子樹作右旋平衡處理 */ 
			  L_Rotate(T); /*  對T作左旋平衡處理 */ 
	}
}

/*  若在平衡的二叉排序樹T中不存在和e有相同關鍵字的節點，則插入一個 */ 
/*  資料元素為e的新節點，並傳回1，否則傳回0。若因插入而使二叉排序樹 */ 
/*  失去平衡，則作平衡旋轉處理，布爾變數taller反映T長高與否。 */
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  插入新節點，樹“長高”，置taller為TRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  樹中已存在和e有相同關鍵字的節點則不再插入 */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  應繼續在T的左子樹中進行搜尋 */ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  未插入 */ 
				return FALSE;
			if(*taller) /*   已插入到T的左子樹中且左子樹“長高” */ 
				switch((*T)->bf) /*  檢查T的平衡度 */ 
				{
					case LH: /*  原本左子樹比右子樹高，需要作左平衡處理 */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  原本左、右子樹等高，現因左子樹增高而使樹增高 */ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  原本右子樹比左子樹高，現左、右子樹等高 */  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  應繼續在T的右子樹中進行搜尋 */ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  未插入 */ 
				return FALSE;
			if(*taller) /*  已插入到T的右子樹且右子樹“長高” */ 
				switch((*T)->bf) /*  檢查T的平衡度 */ 
				{
					case LH: /*  原本左子樹比右子樹高，現左、右子樹等高 */ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  原本左、右子樹等高，現因右子樹增高而使樹增高  */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  原本右子樹比左子樹高，需要作右平衡處理 */ 
							RightBalance(T); *taller=FALSE; break;
				}
		}
	}
	return TRUE;
}

int main(void)
{    
	int i;
	int a[10]={3,2,1,4,5,6,7,10,9,8};
	BiTree T=NULL;
	Status taller;
	for(i=0;i<10;i++)
	{
		InsertAVL(&T,a[i],&taller);
	}
	printf("本範例建議斷點追蹤檢視平衡二元樹結構");
	return 0;
}
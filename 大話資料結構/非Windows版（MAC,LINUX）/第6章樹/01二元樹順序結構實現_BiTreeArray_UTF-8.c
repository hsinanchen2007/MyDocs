#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 儲存空間起始分配量 */
#define MAX_TREE_SIZE 100 /* 二元樹的最大節點數 */

typedef int Status;		/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */
typedef int TElemType;  /* 樹節點的資料型態，目前暫定為整數 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0號單元儲存根節點  */

typedef struct
{
	int level,order; /* 節點的層,本層序號(按滿二元樹計算) */
}Position;

TElemType Nil=0; /*  設整數以0為空 */

Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}

/* 建構空二元樹T。因為T是固定陣列，不會改變，故不需要& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* 初值為空 */
	return OK;
}

/* 按層序次序輸入二元樹中節點的值(字元型或整數), 建構連序儲存的二元樹T */
Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("請按層序輸入節點的值(整數)，0表示空節點，輸999結束。節點數□%d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* 此節點(不空)無雙親且不是根 */
		{
			printf("出現無雙親的非根節點%d\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* 將空給予值給T的後面的節點 */
		i++;
	}

	return OK;
}

#define ClearBiTree InitBiTree /* 在連序儲存結構中，兩函數完全一樣 */

/* 起始條件: 二元樹T存在 */
/* 動作結果: 若T為空二元樹,則傳回TRUE,否則FALSE */
Status BiTreeEmpty(SqBiTree T)
{ 
	if(T[0]==Nil) /* 根節點為空,則樹空 */
		return TRUE;
	else
		return FALSE;
}

/* 起始條件: 二元樹T存在。動作結果: 傳回T的深度 */
int BiTreeDepth(SqBiTree T)
{ 
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* 找到最後一個節點 */
     if(T[i]!=Nil)
       break;
   i++; 
   do
     j++;
   while(i>=powl(2,j));/* 計算2的j次冪。 */
   return j;
}

/* 起始條件: 二元樹T存在 */
/* 動作結果:  當T不空,用e傳回T的根,傳回OK;否則傳回ERROR,e無定義 */
Status Root(SqBiTree T,TElemType *e)
{ 
	if(BiTreeEmpty(T)) /* T空 */
		return ERROR;
	else
	{	
		*e=T[0];
		return OK;
	}
}

/* 起始條件: 二元樹T存在,e是T中某個節點(的位置) */
/* 動作結果: 傳回處於位置e(層,本層序號)的節點的值 */
TElemType Value(SqBiTree T,Position e)
{ 
	 return T[(int)powl(2,e.level-1)+e.order-2];
}

/* 起始條件: 二元樹T存在,e是T中某個節點(的位置) */
/* 動作結果: 給處於位置e(層,本層序號)的節點賦新值value */
Status Assign(SqBiTree T,Position e,TElemType value)
{ 
	int i=(int)powl(2,e.level-1)+e.order-2; /* 將層、本層序號轉為矩陣的序號 */
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* 給葉子賦非空值但雙親為空 */
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  給雙親賦空值但有葉子（不空） */
		return ERROR;
	T[i]=value;
	return OK;
}

/* 起始條件: 二元樹T存在,e是T中某個節點 */
/* 動作結果: 若e是T的非根節點,則傳回它的雙親,否則傳回〞空〞 */
TElemType Parent(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* 空樹 */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[(i+1)/2-1];
	return Nil; /* 沒找到e */
}


/* 起始條件: 二元樹T存在,e是T中某個節點 */
/* 動作結果: 傳回e的左孩子。若e無左孩子,則傳回〞空〞 */
TElemType LeftChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* 空樹 */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+1];
	return Nil; /* 沒找到e */
}

/* 起始條件: 二元樹T存在,e是T中某個節點 */
/* 動作結果: 傳回e的右孩子。若e無右孩子,則傳回〞空〞 */
TElemType RightChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* 空樹 */
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+2];
	return Nil; /* 沒找到e */
}

/* 起始條件: 二元樹T存在,e是T中某個節點 */
/* 動作結果: 傳回e的左兄弟。若e是T的左孩子或無左兄弟,則傳回〞空〞 */
TElemType LeftSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* 空樹 */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* 找到e且其序號為偶數(是右孩子) */
			return T[i-1];
	return Nil; /* 沒找到e */
}

/* 起始條件: 二元樹T存在,e是T中某個節點 */
/* 動作結果: 傳回e的右兄弟。若e是T的右孩子或無右兄弟,則傳回〞空〞 */
TElemType RightSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* 空樹 */
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* 找到e且其序號為奇數(是左孩子) */
			return T[i+1];
	return Nil; /* 沒找到e */
}

/* PreOrderTraverse()呼叫 */
void PreTraverse(SqBiTree T,int e)
{ 
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* 左子樹不空 */
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* 右子樹不空 */
		PreTraverse(T,2*e+2);
}

/* 起始條件: 二元樹存在 */
/* 動作結果: 先序檢查T。 */
Status PreOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* 樹不空 */
	 PreTraverse(T,0);
	printf("\n");
	return OK;
}

/* InOrderTraverse()呼叫 */
void InTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* 左子樹不空 */
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* 右子樹不空 */
		InTraverse(T,2*e+2);
}

/* 起始條件: 二元樹存在 */
/* 動作結果: 中序檢查T。 */
Status InOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* 樹不空 */
		InTraverse(T,0);
	printf("\n");
	return OK;
}

/* PostOrderTraverse()呼叫 */
void PostTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* 左子樹不空 */
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* 右子樹不空 */
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

/* 起始條件: 二元樹T存在 */
/* 動作結果: 後序檢查T。 */
Status PostOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* 樹不空 */
		PostTraverse(T,0);
	printf("\n");
	return OK;
}

/* 層序檢查二元樹 */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* 找到最後一個非空節點的序號 */
	for(j=0;j<=i;j++)  /* 從根節點起,按層序檢查二元樹 */
		if(T[j]!=Nil)
			visit(T[j]); /* 只檢查非空的節點 */
	printf("\n");
}

/* 逐層、按本層序號輸出二元樹 */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("第%d層: ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}


int main()
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("建立二元樹後,樹空否？%d(1:是 0:否) 樹的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二元樹的根為：%d\n",e);
	else
		printf("樹空，無根\n");
	printf("層序檢查二元樹:\n");
	LevelOrderTraverse(T);
	printf("前序檢查二元樹:\n");
	PreOrderTraverse(T);
	printf("中序檢查二元樹:\n");
	InOrderTraverse(T);
	printf("後序檢查二元樹:\n");
	PostOrderTraverse(T);
	printf("修改節點的層號3本層序號2。");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("待修改節點的原值為%d請輸入新值:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("前序檢查二元樹:\n");
	PreOrderTraverse(T);
	printf("節點%d的雙親為%d,左右孩子分別為",e,Parent(T,e));
	printf("%d,%d,左右兄弟分別為",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("清除二元樹後,樹空否？%d(1:是 0:否) 樹的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二元樹的根為：%d\n",e);
	else
		printf("樹空，無根\n");
	
	return 0;
}


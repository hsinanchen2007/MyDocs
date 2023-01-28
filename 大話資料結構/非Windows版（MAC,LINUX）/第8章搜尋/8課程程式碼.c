Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* 插入新節點，樹“長高”，置taller為TRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* 樹中已存在和e有相同關鍵字的節點則不再插入 */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* 應繼續在T的左子樹中進行搜尋 */
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  未插入 */ 
				return FALSE;
			if(*taller) 		/* 已插入到T的左子樹中且左子樹“長高” */ 
			{
				switch((*T)->bf)/* 檢查T的平衡度 */ 
				{
					case LH: 	/* 原本左子樹比右子樹高，需要作左平衡處理 */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* 原本左、右子樹等高，現因左子樹增高而使樹增高 */ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* 原本右子樹比左子樹高，現左、右子樹等高 */  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  應繼續在T的右子樹中進行搜尋 */ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* 未插入 */ 
				return FALSE;
			if(*taller) 		/* 已插入到T的右子樹且右子樹“長高” */ 
			{
				switch((*T)->bf)/* 檢查T的平衡度 */ 
				{
					case LH: 	/* 原本左子樹比右子樹高，現左、右子樹等高 */ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* 原本左、右子樹等高，現因右子樹增高而使樹增高 */
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* 原本右子樹比左子樹高，需要作右平衡處理 */ 
						RightBalance(T); 
						*taller=FALSE; 
						break;
				}
			}
		}
	}
	return TRUE;
}

void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; 					/* L指向T的左子樹根節點 */ 
	switch(L->bf)		/* 檢查T的左子樹的平衡度，並作對應平衡處理 */ 
	{ 
		 case LH:     	/* 新節點插入在T的左孩子的左子樹上，要作單右旋處理 */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* 新節點插入在T的左孩子的右子樹上，要作雙旋處理 */ 
			Lr=L->rchild; 				/* Lr指向T的左孩子的右子樹根 */ 
			switch(Lr->bf)				/* 修改T及其左孩子的平衡因子 */ 
			{ 							
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
			L_Rotate(&(*T)->lchild); 	/* 對T的左子樹作左旋平衡處理 */ 
			R_Rotate(T); 				/* 對T作右旋平衡處理 */ 
	}
}

Status Delete(BiTree *p)
{/* 從二叉排序樹中移除節點p，並重接它的左或右子樹。 */
	BiTree q,s;
	if((*p)->rchild==NULL) /* 右子樹空則只需重接它的左子樹（待刪節點是葉子也走此分支) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* 只需重接它的右子樹 */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* 左右子樹均不空 */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* 轉左，然後向右到盡頭（找待刪節點的前驅）*/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* s指向被刪節點直接前驅(將被刪節點前驅的值取代被刪節點的值) */
		if(q!=*p)
			q->rchild=s->lchild;/*  重接q的右子樹 */ 
		else
			q->lchild=s->lchild;/*  重接q的左子樹 */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* 若二叉排序樹T中存在關鍵字等於key的資料元素時，則移除該資料節點 */
	if(!*T) 					/* 不存在關鍵字等於key的資料元素 */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* 找到關鍵字等於key的資料元素 */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* 遞歸查詢二叉排序樹T中是否存在key, */ 
	if (!T)		/* 若查詢不成功，指標p指向查詢路徑上存取的最後一個節點並傳回FALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* 若查詢成功，則指標p指向該資料元素節點，並傳回TRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* 在左子樹中繼續查詢 */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* 在右子樹中繼續查詢 */
}

int Fibonacci_Search(int *a,int n,int key) /* 費氏查詢 */
{
	int low,high,mid,i,k;
	low=1;						/* 定義最低索引為記錄首位 */
	high=n;						/* 定義最高索引為記錄末位 */
	k=0;
	while(n>F[k]-1)				/* 計算n位於費氏數列的位置 */
		k++;
	for (i=n;i<F[k]-1;i++)		/* 將不滿的數值補全 */
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* 計算目前分隔的索引 */
		if (key<a[mid])			/* 若查詢記錄小於目前分隔記錄 */
		{
			high=mid-1;			/* 最高索引調整到分隔索引mid-1處 */
			k=k-1;				/* 費氏數列索引減一位 */
		}
		else if (key>a[mid])	/* 若查詢記錄大於目前分隔記錄 */
		{
			low=mid+1;			/* 最低索引調整到分隔索引mid+1處 */
			k=k-2;				/* 費氏數列索引減兩位 */
		}
		else
		{
			if (mid<=n)
				return mid;		/* 若相等則說明mid即為查詢到的位置 */
			else 
				return n;		/* 若mid>n說明是補全數值，傳回n */
		}
	}
	return 0;
}

/* 順序查詢，a為陣列，n為要查詢的陣列個數，key為要查詢的關鍵字 */
int Sequential_Search(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return 0;
}

/* 有哨兵順序查詢 */
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* 設定a[0]為關鍵字值，我們稱之為“哨兵”*/
	i=n;				/* 循環從陣列尾部開始 */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* 傳回0則說明查詢失敗 */
}

/* 折半查詢 */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* 定義最低索引為記錄首位 */
	high=n;					/* 定義最高索引為記錄末位 */
	while(low<=high)
	{
		mid=(low+high)/2;	/* 折半 */
		if (key<a[mid])		/* 若查詢值比中值小 */
			high=mid-1;		/* 最高索引調整到中位索引小一位 */
		else if (key>a[mid])/* 若查詢值比中值大 */
			low=mid+1;		/* 最低索引調整到中位索引大一位 */
		else
			return mid;		/* 若相等則說明mid即為查詢到的位置 */
	}
	return 0;
}

/* 插值查詢 */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* 定義最低索引為記錄首位 */
	high=n;	/* 定義最高索引為記錄末位 */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* 插值 */
		if (key<a[mid])		/* 若查詢值比插值小 */
			high=mid-1;		/* 最高索引調整到插值索引小一位 */
		else if (key>a[mid])/* 若查詢值比插值大 */
			low=mid+1;		/* 最低索引調整到插值索引大一位 */
		else
			return mid;		/* 若相等則說明mid即為查詢到的位置 */
	}
	return 0;
}

/* 二元樹的二叉鏈結串列節點結構定義 */
typedef  struct BiTNode					/* 節點結構 */
{
	int data;							/* 節點資料 */
	struct BiTNode *lchild, *rchild;	/* 左右孩子指標 */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* 查詢不成功 */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  插入s為新的根節點 */
		else if (key<p->data) 
			p->lchild = s;				/*  插入s為左孩子 */
		else 
			p->rchild = s;  			/*  插入s為右孩子 */
		return TRUE;
	} 
	else 
		return FALSE;  					/*  樹中已有關鍵字相同的節點，不再插入 */
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* 二元樹的二叉鏈結串列節點結構定義 */
typedef  struct BiTNode					/* 節點結構 */
{
	int data;							/* 節點資料 */
	int bf; 							/*  節點的平衡因子 */ 
	struct BiTNode *lchild, *rchild;	/* 左右孩子指標 */
} BiTNode, *BiTree;


/* 對以p為根的二叉排序樹作右旋處理， */
/* 處理之後p指向新的樹根節點，即旋轉處理之前的左子樹的根節點 */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  L指向P的左子樹根節點 */ 
	(*P)->lchild=L->rchild; /*  L的右子樹掛接為P的左子樹 */ 
	L->rchild=(*P);
	*P=L; 					/*  P指向新的根節點 */ 
}

/* 對以P為根的二叉排序樹作左旋處理， */
/* 處理之後P指向新的樹根節點，即旋轉處理之前的右子樹的根節點0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  R指向P的右子樹根節點 */ 
	(*P)->rchild=R->lchild; /* R的左子樹掛接為P的右子樹 */ 
	R->lchild=(*P);
	*P=R; 					/*  P指向新的根節點 */ 
}

#define LH +1 /*  左高 */ 
#define EH 0  /*  等高 */ 
#define RH -1 /*  右高 */ 

/*  對以指標T所指節點為根的二元樹作左平衡旋轉處理 */
/*  本算法結束時，指標T指向新的根節點 */



/*  對以指標T所指節點為根的二元樹作右平衡旋轉處理， */ 
/*  本算法結束時，指標T指向新的根節點 */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* R指向T的右子樹根節點 */ 
	switch(R->bf)
	{ /* 檢查T的右子樹的平衡度，並作對應平衡處理 */ 
	 case RH: /* 新節點插入在T的右孩子的右子樹上，要作單左旋處理 */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* 新節點插入在T的右孩子的左子樹上，要作雙旋處理 */ 
			  Rl=R->lchild; 			/* Rl指向T的右孩子的左子樹根 */ 
			  switch(Rl->bf)			/* 修改T及其右孩子的平衡因子 */ 
			  { 						
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
			  R_Rotate(&(*T)->rchild); 	/* 對T的右子樹作右旋平衡處理 */ 
			  L_Rotate(T); 				/* 對T作左旋平衡處理 */ 
	}
}



int i;
int a[10]={3,2,1,4,5,6,7,10,9,8};
BiTree T=NULL;
Status taller;
for(i=0;i<10;i++)
{
	InsertAVL(&T,a[i],&taller);
}


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 	/* 定義雜湊表長為陣列的長度 */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* 資料元素儲存基址，動態分配陣列 */
   int count; 			/*  目前資料元素個數 */
}HashTable;

int m=0; 				/* 雜湊表表長，全局變數 */

/* 起始化雜湊表 */
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}

/* 雜湊函數 */
int Hash(int key)
{
	return key % m; /* 除留余數法 */
}

/* 插入關鍵字進雜湊表 */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* 求雜湊位址 */
	while (H->elem[addr] != NULLKEY) 	/* 若果不為空，則沖突 */
	{
		addr = (addr+1) % m; 			/* 開放定址法的線性探測 */
	}
	H->elem[addr] = key; 				/* 直到有空位後插入關鍵字 */
}


/* 雜湊表查詢關鍵字 */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* 求雜湊位址 */
	while(H.elem[*addr] != key) 							/* 若果不為空，則沖突 */
	{
		*addr = (*addr+1) % m; 								/* 開放定址法的線性探測 */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* 若果循環回到原點 */
			return UNSUCCESS;								/* 則說明關鍵字不存在 */
	}
	return SUCCESS;
}







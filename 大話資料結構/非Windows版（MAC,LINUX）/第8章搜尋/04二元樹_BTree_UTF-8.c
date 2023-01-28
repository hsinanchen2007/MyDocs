#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 儲存空間起始分配量 */

#define m 3 /*  二元樹的階，暫設為3 */ 
#define N 17 /*  資料元素個數 */ 
#define MAX 5 /*  字串最大長度+1  */

typedef int Status;	/* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */ 

typedef struct BTNode
{
	int keynum; /*  節點中關鍵字個數，即節點的大小 */ 
	struct BTNode *parent; /*  指向雙親節點 */ 
	struct Node /*  節點向量型態 */ 
	{
		 int key; /*  關鍵字向量 */ 
		 struct BTNode *ptr; /*  子樹指標向量 */ 
		 int recptr; /*  記錄指標向量 */ 
	}node[m+1]; /*  key,recptr的0號單元未用 */ 
}BTNode,*BTree; /*  二元樹節點和二元樹的型態 */ 

typedef struct
{
	BTNode *pt; /*  指向找到的節點 */ 
	int i; /*  1..m，在節點中的關鍵字序號 */ 
	int tag; /*  1:查詢成功，O:查詢失敗 */ 
}Result; /*  二元樹的查詢結果型態 */ 

/*  在p->node[1..keynum].key中查詢i,使得p->node[i].key□K＜p->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}

/*  在m階二元樹T上查詢關鍵字K，傳回結果(pt,i,tag)。若查詢成功，則特征值 */ 
/*  tag=1，指標pt所指節點中第i個關鍵字等於K；否則特征值tag=0，等於K的  */
/*  關鍵字應插入在指標Pt所指節點中第i和第i+1個關鍵字之間。 */
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  起始化，p指向待查節點，q指向p的雙親  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].key□K<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  找到待查關鍵字 */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  查詢成功  */
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   查詢不成功，傳回K的插入位置訊息 */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}

/* 將r->key、r和ap分別插入到q->key[i+1]、q->recptr[i+1]和q->ptr[i+1]中 */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  空出(*q)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}

/* 將節點q分裂成兩個節點，前一半保留，後一半移入新生節點ap */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  產生新節點ap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  後一半移入ap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  q的前一半保留，修改keynum */ 
}

/* 產生含訊息(T,r,ap)的新的根節點&T，原T和ap為子樹指標 */ 
void NewRoot(BTree *T,int key,BTree ap)
{ 
	BTree p;
	p=(BTree)malloc(sizeof(BTNode));
	p->node[0].ptr=*T;
	*T=p;
	if((*T)->node[0].ptr)
		(*T)->node[0].ptr->parent=*T;
	(*T)->parent=NULL;
	(*T)->keynum=1;
	(*T)->node[1].key=key;
	(*T)->node[1].recptr=key;
	(*T)->node[1].ptr=ap;
	if((*T)->node[1].ptr)
		(*T)->node[1].ptr->parent=*T;
}

/*  在m階二元樹T上節點*q的key[i]與key[i+1]之間插入關鍵字K的指標r。若引起 */ 
/*  節點過大,則沿雙親鏈進行必要的節點分裂調整,使T仍是m階二元樹。 */
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  將r->key、r和ap分別插入到q->key[i+1]、q->recptr[i+1]和q->ptr[i+1]中  */
		if(q->keynum<m)
			finished=TRUE; /*  插入完成 */ 
		else
		{ /*  分裂節點*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  將q->key[s+1..m],q->ptr[s..m]和q->recptr[s+1..m]移入新節點*ap  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  在雙親節點*q中查詢rx->key的插入位置  */
		}
	}
	if(!finished) /*  T是空樹(參數q初值為NULL)或根節點已分裂為節點*q和*ap */ 
		NewRoot(T,rx,ap); /*  產生含訊息(T,rx,ap)的新的根節點*T，原T和ap為子樹指標 */ 
}


void print(BTNode c,int i) /*  TraverseDSTable()呼叫的函數  */
{
	printf("(%d)",c.node[i].key);
}

int main()
{
	int r[N]={22,16,41,58,8,11,12,16,17,22,23,31,41,52,58,59,61};
	BTree T=NULL;
	Result s;
	int i;
	for(i=0;i<N;i++)
	{
		s=SearchBTree(T,r[i]);
		if(!s.tag)
			InsertBTree(&T,r[i],s.pt,s.i);
	}
	printf("\n請輸入待查詢記錄的關鍵字: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("沒找到");
	printf("\n");

	return 0;
}

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ーーー釦脱ー */

#define m 3 /*  Bー�弌次次次�3 */ 
#define N 17 /*  ー��ー�Vー/ 
#define MAX 5 /*  ー笹�法次�+1  */

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/ 

typedef struct BTNode
{
	int keynum; /*  ーー遥ー�Vーーー驪ー */ 
	struct BTNode *parent; /*  ーーーーーー/ 
	struct Node /*  ーー ー */ 
	{
		 int key; /*  遥ーー */ 
		 struct BTNode *ptr; /*  ーーーーー */ 
		 int recptr; /*  ーーーー */ 
	}node[m+1]; /*  key,recptr粫ー�w�_ー */ 
}BTNode,*BTree; /*  BーーーBー事ー */ 

typedef struct
{
	BTNode *pt; /*  ーーー��ーー */ 
	int i; /*  1..mーーーー�繊次次次�*/ 
	int tag; /*  1:ーーー扼O:ーー�a */ 
}Result; /*  Bー�x啄ーーー */ 

/*  ーp->node[1..keynum].keyーーー,ー瓊->node[i].keyーー->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}

/*  ーmーーTーーーーーKー甬ーーt,i,tag)ーーーー扼ーーーー */ 
/*  tag=1ー褸ptーーーー殖忤ーー表ーーーーーーtag=0ーーー貊 */
/*  遥ーーーーーーPtーーーー殖ーー+1忤ーーーーー/
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  ーーーーー�蠶幵Bー求p粮ー  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].keyー<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  ー敷ー遥ー */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  ーーー剩*/
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   ーーー�Vーー�x�O�fーーー */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}

/* ー->keyーーp�pーー�v->key[i+1]ー->recptr[i+1]ー->ptr[i+1]ー */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  ��嬢q)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}

/* ーーqーーーーーーーーーーーーーーーーーー */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  ーーーーap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  ーーーーap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  q粳ーーーーーーeynum */ 
}

/* ーーーー(T,r,ap)妾�gー綴樞Tーーーpーーーーー */ 
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

/*  ーmーーTーーー雑ey[i]ーkey[i+1]ーー�O遥ーK妻褸rーーー */ 
/*  ーーーーーーーtーーーーーーQ�檗樹廖次次次次�*/
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  ー->keyーーp�pーー�v->key[i+1]ー->recptr[i+1]ー->ptr[i+1]ー  */
		if(q->keynum<m)
			finished=TRUE; /*  ーーー*/ 
		else
		{ /*  ーーー*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  ー->key[s+1..m],q->ptr[s..m]ー->recptr[s+1..m]ーーーーーp  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  ーーーーーーーーx->key�x�O�fー  */
		}
	}
	if(!finished) /*  Tー�匳_ーー�pーNULL)ー綴賤ーーーー�sqーap */ 
		NewRoot(T,rx,ap); /*  ーーーー(T,rx,ap)妾�gー綴�sTーーーpーーーーー */ 
}


void print(BTNode c,int i) /*  TraverseDSTable()�qoー��  */
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
	printf("\nーーー�蠡錙次射據�: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("uー��);
	printf("\n");

	return 0;
}

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

#define m 3 /*  B¡¼÷Ð¡¼¡¼¡¼¡¼3 */ 
#define N 17 /*  ¡¼”÷¡¼¶V¡¼/ 
#define MAX 5 /*  ¡¼ºû’Ë¡¼¡¼+1  */

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/ 

typedef struct BTNode
{
	int keynum; /*  ¡¼¡¼ÍÚ¡¼¶V¡¼¡¼¡¼ñë¡¼ */ 
	struct BTNode *parent; /*  ¡¼¡¼¡¼¡¼¡¼¡¼/ 
	struct Node /*  ¡¼¡¼ ¡¼ */ 
	{
		 int key; /*  ÍÚ¡¼¡¼ */ 
		 struct BTNode *ptr; /*  ¡¼¡¼¡¼¡¼¡¼ */ 
		 int recptr; /*  ¡¼¡¼¡¼¡¼ */ 
	}node[m+1]; /*  key,recpträè¡¼Ôw£_¡¼ */ 
}BTNode,*BTree; /*  B¡¼¡¼¡¼B¡¼»ö¡¼ */ 

typedef struct
{
	BTNode *pt; /*  ¡¼¡¼¡¼­£¡¼¡¼ */ 
	int i; /*  1..m¡¼¡¼¡¼¡¼õÁ¡¼¡¼¡¼¡¼*/ 
	int tag; /*  1:¡¼¡¼¡¼Ù¯O:¡¼¡¼ða */ 
}Result; /*  B¡¼ÀxÂï¡¼¡¼¡¼ */ 

/*  ¡¼p->node[1..keynum].key¡¼¡¼¡¼,¡¼àû->node[i].key¡¼¡¼->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}

/*  ¡¼m¡¼¡¼T¡¼¡¼¡¼¡¼¡¼K¡¼áµ¡¼¡¼t,i,tag)¡¼¡¼¡¼¡¼Ù¯¡¼¡¼¡¼¡¼ */ 
/*  tag=1¡¼êúpt¡¼¡¼¡¼¡¼¿£×Ø¡¼¡¼É½¡¼¡¼¡¼¡¼¡¼¡¼tag=0¡¼¡¼¡¼ì½ */
/*  ÍÚ¡¼¡¼¡¼¡¼¡¼¡¼Pt¡¼¡¼¡¼¡¼¿£¡¼¡¼+1×Ø¡¼¡¼¡¼¡¼¡¼/
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  ¡¼¡¼¡¼¡¼¡¼–êÄÖôB¡¼µápäî¡¼  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].key¡¼<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  ¡¼Éß¡¼ÍÚ¡¼ */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  ¡¼¡¼¡¼Ñô*/
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   ¡¼¡¼¡¼ïV¡¼¡¼Àx§O£f¡¼¡¼¡¼ */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}

/* ¡¼->key¡¼¡¼p¯p¡¼¡¼¼v->key[i+1]¡¼->recptr[i+1]¡¼->ptr[i+1]¡¼ */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  ‹û¾îq)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}

/* ¡¼¡¼q¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  ¡¼¡¼¡¼¡¼ap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  ¡¼¡¼¡¼¡¼ap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  qäë¡¼¡¼¡¼¡¼¡¼¡¼eynum */ 
}

/* ¡¼¡¼¡¼¡¼(T,r,ap)¾ª£g¡¼ÄÖÜäT¡¼¡¼¡¼p¡¼¡¼¡¼¡¼¡¼ */ 
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

/*  ¡¼m¡¼¡¼T¡¼¡¼¡¼»¨ey[i]¡¼key[i+1]¡¼¡¼§OÍÚ¡¼KºÊêúr¡¼¡¼¡¼ */ 
/*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼t¡¼¡¼¡¼¡¼¡¼¡¼QöÝ¡¼ù×¡¼¡¼¡¼¡¼¡¼*/
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  ¡¼->key¡¼¡¼p¯p¡¼¡¼¼v->key[i+1]¡¼->recptr[i+1]¡¼->ptr[i+1]¡¼  */
		if(q->keynum<m)
			finished=TRUE; /*  ¡¼¡¼¡¼*/ 
		else
		{ /*  ¡¼¡¼¡¼*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  ¡¼->key[s+1..m],q->ptr[s..m]¡¼->recptr[s+1..m]¡¼¡¼¡¼¡¼¡¼p  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼x->keyÀx§O£f¡¼  */
		}
	}
	if(!finished) /*  T¡¼‹Ò½_¡¼¡¼Øp¡¼NULL)¡¼ÄÖìÍ¡¼¡¼¡¼¡¼Åsq¡¼ap */ 
		NewRoot(T,rx,ap); /*  ¡¼¡¼¡¼¡¼(T,rx,ap)¾ª£g¡¼ÄÖÅsT¡¼¡¼¡¼p¡¼¡¼¡¼¡¼¡¼ */ 
}


void print(BTNode c,int i) /*  TraverseDSTable()Åqo¡¼‡¹  */
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
	printf("\n¡¼¡¼¡¼–êÂï¡¼¡¼ÍÚ¡¼: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("u¡¼§Î);
	printf("\n");

	return 0;
}

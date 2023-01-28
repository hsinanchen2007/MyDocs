#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ��������æ�� */

#define m 3 /*  B���С�������3 */ 
#define N 17 /*  �������V��/ 
#define MAX 5 /*  �����ˡ���+1  */

typedef int Status;	/* Status������ ��,���������������á���OK�R*/ 

typedef struct BTNode
{
	int keynum; /*  �����ڡ��V�������롼 */ 
	struct BTNode *parent; /*  ������������/ 
	struct Node /*  ���� �� */ 
	{
		 int key; /*  �ڡ��� */ 
		 struct BTNode *ptr; /*  ���������� */ 
		 int recptr; /*  �������� */ 
	}node[m+1]; /*  key,recptr�衼�w�_�� */ 
}BTNode,*BTree; /*  B������B������ */ 

typedef struct
{
	BTNode *pt; /*  ������������ */ 
	int i; /*  1..m������������������*/ 
	int tag; /*  1:������ٯO:�����a */ 
}Result; /*  B���x����� */ 

/*  ��p->node[1..keynum].key������,����->node[i].key����->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}

/*  ��m����T����������K��ᵡ���t,i,tag)��������ٯ�������� */ 
/*  tag=1����pt�����������ء���ɽ������������tag=0������� */
/*  �ڡ�����������Pt��������������+1�ء���������/
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  ���������������B����p�  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].key��<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  ���ߡ��ڡ� */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  ��������*/
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   �������V�����x�O�f������ */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}

/* ��->key����p�p�����v->key[i+1]��->recptr[i+1]��->ptr[i+1]�� */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  ����q)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}

/* ����q������������������������������������ */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  ��������ap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  ��������ap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  q�롼����������eynum */ 
}

/* ��������(T,r,ap)���g������T������p���������� */ 
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

/*  ��m����T��������ey[i]��key[i+1]�����O�ڡ�K����r������ */ 
/*  ��������������t������������Q�ݡ��ס���������*/
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  ��->key����p�p�����v->key[i+1]��->recptr[i+1]��->ptr[i+1]��  */
		if(q->keynum<m)
			finished=TRUE; /*  ������*/ 
		else
		{ /*  ������*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  ��->key[s+1..m],q->ptr[s..m]��->recptr[s+1..m]����������p  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  ����������������x->key�x�O�f��  */
		}
	}
	if(!finished) /*  T���ҽ_�����p��NULL)�����͡��������sq��ap */ 
		NewRoot(T,rx,ap); /*  ��������(T,rx,ap)���g�����sT������p���������� */ 
}


void print(BTNode c,int i) /*  TraverseDSTable()�qo����  */
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
	printf("\n������������ڡ�: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("u����);
	printf("\n");

	return 0;
}

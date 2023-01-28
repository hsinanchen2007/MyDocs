#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

#define m 3 /*  �G���𪺶��A�ȳ]��3 */ 
#define N 17 /*  ��Ƥ����Ӽ� */ 
#define MAX 5 /*  �r��̤j����+1  */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */ 

typedef struct BTNode
{
	int keynum; /*  �`�I������r�ӼơA�Y�`�I���j�p */ 
	struct BTNode *parent; /*  ���V���˸`�I */ 
	struct Node /*  �`�I�V�q���A */ 
	{
		 int key; /*  ����r�V�q */ 
		 struct BTNode *ptr; /*  �l����ЦV�q */ 
		 int recptr; /*  �O�����ЦV�q */ 
	}node[m+1]; /*  key,recptr��0���椸���� */ 
}BTNode,*BTree; /*  �G����`�I�M�G���𪺫��A */ 

typedef struct
{
	BTNode *pt; /*  ���V��쪺�`�I */ 
	int i; /*  1..m�A�b�`�I��������r�Ǹ� */ 
	int tag; /*  1:�d�ߦ��\�AO:�d�ߥ��� */ 
}Result; /*  �G���𪺬d�ߵ��G���A */ 

/*  �bp->node[1..keynum].key���d��i,�ϱop->node[i].key��K��p->node[i+1].key */ 
int Search(BTree p, int K)
{ 
	int i=0,j;
	for(j=1;j<=p->keynum;j++)
	 if(p->node[j].key<=K)
	   i=j;
	return i;
}

/*  �bm���G����T�W�d������rK�A�Ǧ^���G(pt,i,tag)�C�Y�d�ߦ��\�A�h�S���� */ 
/*  tag=1�A����pt�ҫ��`�I����i������r����K�F�_�h�S����tag=0�A����K��  */
/*  ����r�����J�b����Pt�ҫ��`�I����i�M��i+1������r�����C */
Result SearchBTree(BTree T, int K)
{ 
	BTree p=T,q=NULL; /*  �_�l�ơAp���V�ݬd�`�I�Aq���Vp������  */
	Status found=FALSE;
	int i=0;
	Result r;
	while(p&&!found)
	{
	 i=Search(p,K); /*  p->node[i].key��K<p->node[i+1].key  */
	 if(i>0&&p->node[i].key==K) /*  ���ݬd����r */ 
	   found=TRUE;
	 else
	 {
	   q=p;
	   p=p->node[i].ptr;
	 }
	}
	r.i=i;
	if(found) /*  �d�ߦ��\  */
	{
	 r.pt=p;
	 r.tag=1;
	}
	else /*   �d�ߤ����\�A�Ǧ^K�����J��m�T�� */ 
	{
	 r.pt=q;
	 r.tag=0;
	}
	return r;
}

/* �Nr->key�Br�Map���O���J��q->key[i+1]�Bq->recptr[i+1]�Mq->ptr[i+1]�� */ 
void Insert(BTree *q,int i,int key,BTree ap)
{ 
	int j;
	for(j=(*q)->keynum;j>i;j--) /*  �ťX(*q)->node[i+1]  */
		(*q)->node[j+1]=(*q)->node[j];
	(*q)->node[i+1].key=key;
	(*q)->node[i+1].ptr=ap;
	(*q)->node[i+1].recptr=key;
	(*q)->keynum++;
}

/* �N�`�Iq��������Ӹ`�I�A�e�@�b�O�d�A��@�b���J�s�͸`�Iap */ 
void split(BTree *q,BTree *ap)
{ 
	int i,s=(m+1)/2;
	*ap=(BTree)malloc(sizeof(BTNode)); /*  ���ͷs�`�Iap */ 
	(*ap)->node[0].ptr=(*q)->node[s].ptr; /*  ��@�b���Jap */ 
	for(i=s+1;i<=m;i++)
	{
		 (*ap)->node[i-s]=(*q)->node[i];
		 if((*ap)->node[i-s].ptr)
			(*ap)->node[i-s].ptr->parent=*ap;
	}
	(*ap)->keynum=m-s;
	(*ap)->parent=(*q)->parent;
	(*q)->keynum=s-1; /*  q���e�@�b�O�d�A�ק�keynum */ 
}

/* ���ͧt�T��(T,r,ap)���s���ڸ`�I&T�A��T�Map���l����� */ 
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

/*  �bm���G����T�W�`�I*q��key[i]�Pkey[i+1]�������J����rK������r�C�Y�ް_ */ 
/*  �`�I�L�j,�h�u������i�楲�n���`�I�����վ�,��T���Om���G����C */
void InsertBTree(BTree *T,int key,BTree q,int i)
{ 
	BTree ap=NULL;
	Status finished=FALSE;
	int s;
	int rx;
	rx=key;
	while(q&&!finished)
	{
		Insert(&q,i,rx,ap); /*  �Nr->key�Br�Map���O���J��q->key[i+1]�Bq->recptr[i+1]�Mq->ptr[i+1]��  */
		if(q->keynum<m)
			finished=TRUE; /*  ���J���� */ 
		else
		{ /*  �����`�I*q */ 
			s=(m+1)/2;
			rx=q->node[s].recptr;
			split(&q,&ap); /*  �Nq->key[s+1..m],q->ptr[s..m]�Mq->recptr[s+1..m]���J�s�`�I*ap  */
			q=q->parent;
			if(q)
				i=Search(q,key); /*  �b���˸`�I*q���d��rx->key�����J��m  */
		}
	}
	if(!finished) /*  T�O�ž�(�Ѽ�q��Ȭ�NULL)�ήڸ`�I�w�������`�I*q�M*ap */ 
		NewRoot(T,rx,ap); /*  ���ͧt�T��(T,rx,ap)���s���ڸ`�I*T�A��T�Map���l����� */ 
}


void print(BTNode c,int i) /*  TraverseDSTable()�I�s�����  */
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
	printf("\n�п�J�ݬd�߰O��������r: ");
	scanf("%d",&i);
	s=SearchBTree(T,i);
	if(s.tag)
		print(*(s.pt),s.i);
	else
		printf("�S���");
	printf("\n");

	return 0;
}

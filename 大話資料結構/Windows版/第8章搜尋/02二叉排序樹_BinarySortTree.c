#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ーーー釦脱ー */

typedef int Status;	/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/ 

/* �Eー亭��tーーー��ー */
typedef  struct BiTNode	/* ーー��*/
{
	int data;	/* ーー�D*/
	struct BiTNode *lchild, *rchild;	/* ーーーー褸 */
} BiTNode, *BiTree;


/* マ饕ー�E�iーーTーー�@ーkey, */
/* ーーfーーT粮ーーーー�qO甼NULL */
/* ーーーー扼ーーーpーー�aーーーーーー甬TRUE */
/* �筺次�pーーーー短ー�{ーー��ーーーー甬FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  ーーーー*/
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  ーーー��/
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  ーーーーーー�cー */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  ーーーーーー�cー */
}


/*  �|�帖次次�Tーーー遥ー表ーey糀ーーーーー*/
/*  ーーyー甬TRUEーー�_ーALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* ーーーー*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  ーーー椿綴�b*/
		else if (key<p->data) 
			p->lchild = s;	/*  ーーーーー*/
		else 
			p->rchild = s;  /*  ーーーーー*/
		return TRUE;
	} 
	else 
		return FALSE;  /*  ーーーー遥ーーー�弌次次次次�/
}

/* ー�帖次次次次次次�pーーーーーーーーー */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* ーーー�棔次次次次次次次次次次爾Kーーーーーー捉*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ーーーーーーーー */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* ーーーー�后� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* ーーーーーー�vーーーーーーーーー*/
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  sーーー�LЁーーーーーーーーーー妻�n�]ーーーーー*/
		if(q!=*p)
			q->rchild=s->lchild; /*  ーー蔘ーー吮/ 
		else
			q->lchild=s->lchild; /*  ーー蔬ーー */
		free(s);
	}
	return TRUE;
}

/* ー�E�iーーTーーーーー表ーey糀ーーーーーーーEーーーーー*/
/* ー甬TRUEーー�_ーALSEー*/
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* ーー遥ー表ーey糀ーーー */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* ー�弌次蕊宗�ey糀ーーー */ 
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
    printf("ー爍ー茸茅ーーーーーーー椨;
	return 0;
}

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status;	/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/ 

/* êE¡¼ÄâÄt¡¼¡¼¡¼õ©¡¼ */
typedef  struct BiTNode	/* ¡¼¡¼ö¿*/
{
	int data;	/* ¡¼¡¼•D*/
	struct BiTNode *lchild, *rchild;	/* ¡¼¡¼¡¼¡¼êú */
} BiTNode, *BiTree;


/* ¥ÞñÃ¡¼êEÝi¡¼¡¼T¡¼¡¼÷@¡¼key, */
/* ¡¼¡¼f¡¼¡¼Täî¡¼¡¼¡¼¡¼ÅqOá¶NULL */
/* ¡¼¡¼¡¼¡¼Ù¯¡¼¡¼¡¼p¡¼¡¼Ða¡¼¡¼¡¼¡¼¡¼¡¼áµTRUE */
/* õä¡¼¡¼p¡¼¡¼¡¼¡¼Ã»¡¼Ò{¡¼¡¼ ú¡¼¡¼¡¼¡¼áµFALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  ¡¼¡¼¡¼¡¼*/
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  ¡¼¡¼¡¼®è/
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  ¡¼¡¼¡¼¡¼¡¼¡¼³c¡¼ */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  ¡¼¡¼¡¼¡¼¡¼¡¼³c¡¼ */
}


/*  ·|Ä¡¼¡¼¡¼T¡¼¡¼¡¼ÍÚ¡¼É½¡¼eyäñ¡¼¡¼¡¼¡¼¡¼*/
/*  ¡¼¡¼y¡¼áµTRUE¡¼¡¼ß_¡¼ALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* ¡¼¡¼¡¼¡¼*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  ¡¼¡¼¡¼ÄØÄÖÃb*/
		else if (key<p->data) 
			p->lchild = s;	/*  ¡¼¡¼¡¼¡¼¡¼*/
		else 
			p->rchild = s;  /*  ¡¼¡¼¡¼¡¼¡¼*/
		return TRUE;
	} 
	else 
		return FALSE;  /*  ¡¼¡¼¡¼¡¼ÍÚ¡¼¡¼¡¼÷Ð¡¼¡¼¡¼¡¼¡¼/
}

/* ¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼p¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* ¡¼¡¼¡¼‹Ü¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¤K¡¼¡¼¡¼¡¼¡¼¡¼Âª*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* ¡¼¡¼¡¼¡¼ ¹¡¼ */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* ¡¼¡¼¡¼¡¼¡¼¡¼Ìv¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼*/
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  s¡¼¡¼¡¼‚L§§¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ºÊÊn©]¡¼¡¼¡¼¡¼¡¼*/
		if(q!=*p)
			q->rchild=s->lchild; /*  ¡¼¡¼èõ¡¼¡¼Òä/ 
		else
			q->lchild=s->lchild; /*  ¡¼¡¼èö¡¼¡¼ */
		free(s);
	}
	return TRUE;
}

/* ¡¼êEÝi¡¼¡¼T¡¼¡¼¡¼¡¼¡¼É½¡¼eyäñ¡¼¡¼¡¼¡¼¡¼¡¼¡¼E¡¼¡¼¡¼¡¼¡¼*/
/* ¡¼áµTRUE¡¼¡¼ß_¡¼ALSE¡¼*/
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* ¡¼¡¼ÍÚ¡¼É½¡¼eyäñ¡¼¡¼¡¼ */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* ¡¼§Ð¡¼¡¼É½¡¼eyäñ¡¼¡¼¡¼ */ 
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
    printf("¡¼à£¡¼Âû³ý¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ü­;
	return 0;
}

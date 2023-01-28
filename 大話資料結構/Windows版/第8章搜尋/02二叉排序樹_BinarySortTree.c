#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ��������æ�� */

typedef int Status;	/* Status������ ��,���������������á���OK�R*/ 

/* �E�����t���������� */
typedef  struct BiTNode	/* ������*/
{
	int data;	/* �����D*/
	struct BiTNode *lchild, *rchild;	/* ���������� */
} BiTNode, *BiTree;


/* ���á��E�i����T�����@��key, */
/* ����f����T��������qO�NULL */
/* ��������ٯ������p�����a�������������TRUE */
/* �䡼��p��������û���{���������������FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  ��������*/
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  ��������/
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  �������������c�� */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  �������������c�� */
}


/*  �|�ġ�����T�������ڡ�ɽ��ey�񡼡�������*/
/*  ����y���TRUE�����_��ALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* ��������*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  �����������b*/
		else if (key<p->data) 
			p->lchild = s;	/*  ����������*/
		else 
			p->rchild = s;  /*  ����������*/
		return TRUE;
	} 
	else 
		return FALSE;  /*  ���������ڡ������С���������/
}

/* ���ġ�������������p������������������ */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* �������ܡ����������������������K������������ª*/
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ���������������� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* ������������ */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* �������������v������������������*/
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  s�������L�������������������������n�]����������*/
		if(q!=*p)
			q->rchild=s->lchild; /*  ������������/ 
		else
			q->lchild=s->lchild; /*  ���������� */
		free(s);
	}
	return TRUE;
}

/* ���E�i����T����������ɽ��ey�񡼡�����������E����������*/
/* ���TRUE�����_��ALSE��*/
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* �����ڡ�ɽ��ey�񡼡��� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* ���С���ɽ��ey�񡼡��� */ 
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
    printf("��࣡�������������������ܭ;
	return 0;
}

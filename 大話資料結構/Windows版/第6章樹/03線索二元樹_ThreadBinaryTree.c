#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ��������æ�� */

typedef int Status;	/* Status������ ��,���������������á��֧R*/
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0���s������������, */
										/* Thread==1���s�����������T����/
typedef  struct BiThrNode	/* �E�c�������ء� */
{
	TElemType data;	/* �����D*/
	struct BiThrNode *lchild, *rchild;	/* ���������� */
	PointerTag LTag;
	PointerTag RTag;		/* �������q/
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* ��������������*/

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* ���������E�c������������,�e�������xT */
/* 0(����)/�A������)���⡼��/
Status CreateBiThrTree(BiThrTree *T)
{ 
	TElemType h;
	scanf("%c",&h);

	if(h==Nil)
		*T=NULL;
	else
	{
		*T=(BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=h; /* �������ҡ���) */
		CreateBiThrTree(&(*T)->lchild); /* ���С������� */
		if((*T)->lchild) /* ��������*/
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* ���С������� */
		if((*T)->rchild) /* ��������*/
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* ���l��,���������E��I��������/
/* ��������������������*/
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* �޶�����������*/
		if(!p->lchild) /* u��������*/
		{
			p->LTag=Thread; /* �������� */
			p->lchild=pre; /* ���������������� */
		}
		if(!pre->rchild) /* ����u��������*/
		{
			pre->RTag=Thread; /* ��������/
			pre->rchild=p; /* ���������������������Z���n) */
		}
		pre=p; /* ����re����p�롼 */
		InThreading(p->rchild); /* ���z����������*/
	}
}

/* �����������i��������������Thrt����������/
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* ���\�b*/
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* ���������P/
	if(!T) /* ���E���������������P/
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* ��������������������*/
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* ��������������*/
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* �������������xT(���������������Y*/
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* p�������� */
	while(p!=T)
	{ /* ���l��������,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* �{���������������� */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* �{��������/
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("�����������E��(��:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* ������������/
	InOrderThreading(&H,T); /* �������������������ġ� */
	printf("����������)�E�c����:\n");
	InOrderTraverse_Thr(H); /* ����������)�E�c���� */
	printf("\n");
	
	return 0;
}



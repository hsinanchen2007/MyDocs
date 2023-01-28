#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X,�pOK�� */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link==0��ܫ��V���k�Ĥl����, */
										/* Thread==1��ܫ��V�e�X�Ϋ��~���u�� */
typedef  struct BiThrNode	/* �G�e�u���x�s�`�I���c */
{
	TElemType data;	/* �`�I��� */
	struct BiThrNode *lchild, *rchild;	/* ���k�Ĥl���� */
	PointerTag LTag;
	PointerTag RTag;		/* ���k�Ч� */
} BiThrNode, *BiThrTree;

TElemType Nil='#'; /* �r�����H�Ů�Ŭ��� */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

/* ���e�ǿ�J�G�e�u���𤤸`�I����,�غc�G�e�u����T */
/* 0(���)/�Ů�(�r����)��ܪŸ`�I */
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
		(*T)->data=h; /* ���ͮڸ`�I(�e��) */
		CreateBiThrTree(&(*T)->lchild); /* ���k�غc���l�� */
		if((*T)->lchild) /* �����Ĥl */
			(*T)->LTag=Link;
		CreateBiThrTree(&(*T)->rchild); /* ���k�غc�k�l�� */
		if((*T)->rchild) /* ���k�Ĥl */
			(*T)->RTag=Link;
	}
	return OK;
}

BiThrTree pre; /* �����ܼ�,�l�׫��V���s���L���`�I */
/* �����ˬd�i�椤�ǽu���� */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* ���k���l��u���� */
		if(!p->lchild) /* �S�����Ĥl */
		{
			p->LTag=Thread; /* �e�X�u�� */
			p->lchild=pre; /* ���Ĥl���Ы��V�e�X */
		}
		if(!pre->rchild) /* �e�X�S���k�Ĥl */
		{
			pre->RTag=Thread; /* ���~�u�� */
			pre->rchild=p; /* �e�X�k�Ĥl���Ы��V���~(�ثe�`�Ip) */
		}
		pre=p; /* �O��pre���Vp���e�X */
		InThreading(p->rchild); /* ���k�k�l��u���� */
	}
}

/* �����ˬd�G����T,�ñN�䤤�ǽu����,Thrt���V�Y�`�I */
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ 
	*Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag=Link; /* ���Y�`�I */
	(*Thrt)->RTag=Thread;
	(*Thrt)->rchild=(*Thrt); /* �k���Ц^�� */
	if(!T) /* �Y�G�����,�h�����Ц^�� */
		(*Thrt)->lchild=*Thrt;
	else
	{
		(*Thrt)->lchild=T;
		pre=(*Thrt);
		InThreading(T); /* �����ˬd�i�椤�ǽu���� */
		pre->rchild=*Thrt;
		pre->RTag=Thread; /* �̫�@�Ӹ`�I�u���� */
		(*Thrt)->rchild=pre;
	}
	return OK;
}

/* �����ˬd�G�e�u����T(�Y�`�I)���D���k��k */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; /* p���V�ڸ`�I */
	while(p!=T)
	{ /* �ž���ˬd������,p==T */
		while(p->LTag==Link)
			p=p->lchild;
		if(!visit(p->data)) /* �s���䥪�l�𬰪Ū��`�I */
			return ERROR;
		while(p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;
			visit(p->data); /* �s�����~�`�I */
		}
		p=p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H,T;
	printf("�Ы��e�ǿ�J�G����(�p:'ABDH##I##EJ###CF##G##')\n");
 	CreateBiThrTree(&T); /* ���e�ǲ��ͤG���� */
	InOrderThreading(&H,T); /* �����ˬd,�ä��ǽu���ƤG���� */
	printf("�����ˬd(��X)�G�e�u����:\n");
	InOrderTraverse_Thr(H); /* �����ˬd(��X)�G�e�u���� */
	printf("\n");
	
	return 0;
}



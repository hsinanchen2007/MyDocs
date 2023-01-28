#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �x�s�Ŷ��_�l���t�q */

typedef int Status;	/* Status�O��ƪ����A,��ȬO��Ƶ��G���A�{���X�A�pOK�� */ 

/* �G���𪺤G�e�쵲��C�`�I���c�w�q */
typedef  struct BiTNode	/* �`�I���c */
{
	int data;	/* �`�I��� */
	struct BiTNode *lchild, *rchild;	/* ���k�Ĥl���� */
} BiTNode, *BiTree;


/* ���k�d�ߤG�e�ƧǾ�T���O�_�s�bkey, */
/* ����f���VT�����ˡA��_�l�I�s�Ȭ�NULL */
/* �Y�d�ߦ��\�A�h����p���V�Ӹ�Ƥ����`�I�A�öǦ^TRUE */
/* �_�h����p���V�d�߸��|�W�s�����̫�@�Ӹ`�I�öǦ^FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	/*  �d�ߤ����\ */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /*  �d�ߦ��\ */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  /*  �b���l���~��d�� */
	else  
		return SearchBST(T->rchild, key, T, p);  /*  �b�k�l���~��d�� */
}


/*  ��G�e�ƧǾ�T�����s�b����r����key����Ƥ����ɡA */
/*  ���Jkey�öǦ^TRUE�A�_�h�Ǧ^FALSE */
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) /* �d�ߤ����\ */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			/*  ���Js���s���ڸ`�I */
		else if (key<p->data) 
			p->lchild = s;	/*  ���Js�����Ĥl */
		else 
			p->rchild = s;  /*  ���Js���k�Ĥl */
		return TRUE;
	} 
	else 
		return FALSE;  /*  �𤤤w������r�ۦP���`�I�A���A���J */
}

/* �q�G�e�ƧǾ𤤲����`�Ip�A�í����������Υk�l��C */
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) /* �k�l��ūh�u�ݭ����������l��]�ݧR�`�I�O���l�]��������) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* �u�ݭ��������k�l�� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else /* ���k�l�𧡤��� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) /* �४�A�M��V�k����Y�]��ݧR�`�I���e�X�^ */
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; /*  s���V�Q�R�`�I�������e�X�]�N�Q�R�`�I�e�X���Ȩ��N�Q�R�`�I���ȡ^ */
		if(q!=*p)
			q->rchild=s->lchild; /*  ����q���k�l�� */ 
		else
			q->lchild=s->lchild; /*  ����q�����l�� */
		free(s);
	}
	return TRUE;
}

/* �Y�G�e�ƧǾ�T���s�b����r����key����Ƥ����ɡA�h�����Ӹ�Ƥ����`�I, */
/* �öǦ^TRUE�F�_�h�Ǧ^FALSE�C */
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) /* ���s�b����r����key����Ƥ��� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) /* �������r����key����Ƥ��� */ 
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
    printf("���d�ҫ�ĳ�_�I�l���˵��G�e�ƧǾ𵲺c");
	return 0;
}

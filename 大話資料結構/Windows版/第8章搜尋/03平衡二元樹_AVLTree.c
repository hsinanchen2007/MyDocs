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
	int bf; /*  ���������� */ 
	struct BiTNode *lchild, *rchild;	/* ���������� */
} BiTNode, *BiTree;


/* �㡼���ࡼ�ġ��������������� */
/* ���������������e�������������������������b*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  L����P���������� */ 
	(*P)->lchild=L->rchild; /*  L������¹���������� */ 
	L->rchild=(*P);
	*P=L; /*  P�����������b*/ 
}

/* �㡼���ࡼ�ġ��������������� */
/* ���������������e���������������������s�ա���0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  R����P�������e����/ 
	(*P)->rchild=R->lchild; /* R������ມ�����������/ 
	R->lchild=(*P);
	*P=R; /*  P�����������b*/ 
}

#define LH +1 /*  ����*/ 
#define EH 0  /*  �顼*/ 
#define RH -1 /*  ����*/ 

/*  �㡼��T���������ࡼ�ġ���������������/
/*  �������᡼��T�����������b*/
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  L����T���������� */ 
	switch(L->bf)
	{ /*  ���򡼡����꡼�t�������������z */ 
		 case LH: /*  ����������T�������������������a����- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  ����������T������������ޤ������������/ 
			Lr=L->rchild; /*  Lr����T�������������e */ 
			switch(Lr->bf)
			{ /*  ���C���������������� */ 
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); /*  �d�����������������z */ 
			R_Rotate(T); /*  �d�����������z */ 
	}
}

/*  �㡼��T���������ࡼ�ġ��������������� */ 
/*  �������᡼��T�����������b*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  R����T�������e����/ 
	switch(R->bf)
	{ /*  ���򡼡����s�ա������������������z */ 
	 case RH: /*  ����������T������������ޤ�����M������/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  ����������T��������������������������/ 
			  Rl=R->lchild; 			/*  Rl����T��������������*/ 
			  switch(Rl->bf)
			  { 						/*  ���C���������������� */ 
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); /*  �d�������ʡ��������z */ 
			  L_Rotate(T); /*  �d�����������z */ 
	}
}

/*  �����������ġ�����T���������������ڡ��С�����������*/ 
/*  ��������e�����������������_�������������E�i���� */ 
/*  ��������������������������taller�V���᡼����/
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  �������������᡼��taller��TRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  �������������������ڡ��С��������O */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  ������T����������������/ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �_����/ 
				return FALSE;
			if(*taller) /*   ������T�������������������᡼*/ 
				switch((*T)->bf) /*  ���򡼡��r*/ 
				{
					case LH: /*  ���������������С�㺡��������z */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  �������������顼�������������ުࡼ����*/ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  �����������������ʡ�������������*/  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  ������T�������١�������/ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  �_����/ 
				return FALSE;
			if(*taller) /*  ������T�������N���������᡼*/ 
				switch((*T)->bf) /*  ���򡼡��r*/ 
				{
					case LH: /*  ���������������С������������顼*/ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  �������������顼�������������ުࡼ���� */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  �����������������ʡ������������z */ 
							RightBalance(T); *taller=FALSE; break;
				}
		}
	}
	return TRUE;
}

int main(void)
{    
	int i;
	int a[10]={3,2,1,4,5,6,7,10,9,8};
	BiTree T=NULL;
	Status taller;
	for(i=0;i<10;i++)
	{
		InsertAVL(&T,a[i],&taller);
	}
	printf("��࣡��������������ġ���ܭ;
	return 0;
}
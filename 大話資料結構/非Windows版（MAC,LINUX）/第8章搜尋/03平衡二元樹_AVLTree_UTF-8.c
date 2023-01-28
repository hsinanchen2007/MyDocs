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
	int bf; /*  �`�I�����Ŧ]�l */ 
	struct BiTNode *lchild, *rchild;	/* ���k�Ĥl���� */
} BiTNode, *BiTree;


/* ��Hp���ڪ��G�e�ƧǾ�@�k�۳B�z�A */
/* �B�z����p���V�s����ڸ`�I�A�Y����B�z���e�����l�𪺮ڸ`�I */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  L���VP�����l��ڸ`�I */ 
	(*P)->lchild=L->rchild; /*  L���k�l�𱾱���P�����l�� */ 
	L->rchild=(*P);
	*P=L; /*  P���V�s���ڸ`�I */ 
}

/* ��HP���ڪ��G�e�ƧǾ�@���۳B�z�A */
/* �B�z����P���V�s����ڸ`�I�A�Y����B�z���e���k�l�𪺮ڸ`�I0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  R���VP���k�l��ڸ`�I */ 
	(*P)->rchild=R->lchild; /* R�����l�𱾱���P���k�l�� */ 
	R->lchild=(*P);
	*P=R; /*  P���V�s���ڸ`�I */ 
}

#define LH +1 /*  ���� */ 
#define EH 0  /*  ���� */ 
#define RH -1 /*  �k�� */ 

/*  ��H����T�ҫ��`�I���ڪ��G����@�����ű���B�z */
/*  ����k�����ɡA����T���V�s���ڸ`�I */
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  L���VT�����l��ڸ`�I */ 
	switch(L->bf)
	{ /*  �ˬdT�����l�𪺥��ūסA�ç@�������ųB�z */ 
		 case LH: /*  �s�`�I���J�bT�����Ĥl�����l��W�A�n�@��k�۳B�z */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  �s�`�I���J�bT�����Ĥl���k�l��W�A�n�@���۳B�z */ 
			Lr=L->rchild; /*  Lr���VT�����Ĥl���k�l��� */ 
			switch(Lr->bf)
			{ /*  �ק�T�Ψ䥪�Ĥl�����Ŧ]�l */ 
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
			L_Rotate(&(*T)->lchild); /*  ��T�����l��@���ۥ��ųB�z */ 
			R_Rotate(T); /*  ��T�@�k�ۥ��ųB�z */ 
	}
}

/*  ��H����T�ҫ��`�I���ڪ��G����@�k���ű���B�z�A */ 
/*  ����k�����ɡA����T���V�s���ڸ`�I */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  R���VT���k�l��ڸ`�I */ 
	switch(R->bf)
	{ /*  �ˬdT���k�l�𪺥��ūסA�ç@�������ųB�z */ 
	 case RH: /*  �s�`�I���J�bT���k�Ĥl���k�l��W�A�n�@�楪�۳B�z */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  �s�`�I���J�bT���k�Ĥl�����l��W�A�n�@���۳B�z */ 
			  Rl=R->lchild; 			/*  Rl���VT���k�Ĥl�����l��� */ 
			  switch(Rl->bf)
			  { 						/*  �ק�T�Ψ�k�Ĥl�����Ŧ]�l */ 
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
			  R_Rotate(&(*T)->rchild); /*  ��T���k�l��@�k�ۥ��ųB�z */ 
			  L_Rotate(T); /*  ��T�@���ۥ��ųB�z */ 
	}
}

/*  �Y�b���Ū��G�e�ƧǾ�T�����s�b�Me���ۦP����r���`�I�A�h���J�@�� */ 
/*  ��Ƥ�����e���s�`�I�A�öǦ^1�A�_�h�Ǧ^0�C�Y�]���J�ӨϤG�e�ƧǾ� */ 
/*  ���h���šA�h�@���ű���B�z�A�����ܼ�taller�ϬMT�����P�_�C */
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  ���J�s�`�I�A�𡧪������A�mtaller��TRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  �𤤤w�s�b�Me���ۦP����r���`�I�h���A���J */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  ���~��bT�����l�𤤶i��j�M */ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �����J */ 
				return FALSE;
			if(*taller) /*   �w���J��T�����l�𤤥B���l�𡧪����� */ 
				switch((*T)->bf) /*  �ˬdT�����ū� */ 
				{
					case LH: /*  �쥻���l���k�l�𰪡A�ݭn�@�����ųB�z */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  �쥻���B�k�l�𵥰��A�{�]���l��W���ӨϾ�W�� */ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  �쥻�k�l��񥪤l�𰪡A�{���B�k�l�𵥰� */  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  ���~��bT���k�l�𤤶i��j�M */ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  �����J */ 
				return FALSE;
			if(*taller) /*  �w���J��T���k�l��B�k�l�𡧪����� */ 
				switch((*T)->bf) /*  �ˬdT�����ū� */ 
				{
					case LH: /*  �쥻���l���k�l�𰪡A�{���B�k�l�𵥰� */ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  �쥻���B�k�l�𵥰��A�{�]�k�l��W���ӨϾ�W��  */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  �쥻�k�l��񥪤l�𰪡A�ݭn�@�k���ųB�z */ 
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
	printf("���d�ҫ�ĳ�_�I�l���˵����ŤG���𵲺c");
	return 0;
}
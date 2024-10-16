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
	int bf; /*  ーーーーー */ 
	struct BiTNode *lchild, *rchild;	/* ーーーー褸 */
} BiTNode, *BiTree;


/* �磧次蔀燹��帖次次次次次次次� */
/* ーーーーーー糀�eーーーーーーー蔬ーー椿綴�b*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  LーーP蔬ーーーー */ 
	(*P)->lchild=L->rchild; /*  L蔘ーー孫ーーーーー */ 
	L->rchild=(*P);
	*P=L; /*  Pーーー椿綴�b*/ 
}

/* �磧次蔀燹��帖次次次次次次次� */
/* ーーーーーー糀�eーーーーーーー蔘ーー�s箇ーー0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  RーーP蔘ーー�eーー/ 
	(*P)->rchild=R->lchild; /* R蔬ーー犧ーーーーー吮/ 
	R->lchild=(*P);
	*P=R; /*  Pーーー椿綴�b*/ 
}

#define LH +1 /*  ー堆*/ 
#define EH 0  /*  �蕁�*/ 
#define RH -1 /*  ー堆*/ 

/*  �磧手�Tーーーー逐ー�帖次次次次次次次�/
/*  ーーー�瓠手�Tーーー椿綴�b*/
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  LーーT蔬ーーーー */ 
	switch(L->bf)
	{ /*  ー鋳ーーー粨ー�tーーーーーー�z */ 
		 case LH: /*  ーーーーーT蔬ーー蔬ーーーーー�aーー- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  ーーーーーT蔬ーー蔘ーー泙ーーーーーー/ 
			Lr=L->rchild; /*  LrーーT蔬ーー蔘ーー�e */ 
			switch(Lr->bf)
			{ /*  ー�Cーーーーーーーー */ 
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
			L_Rotate(&(*T)->lchild); /*  �d蔬ーーーーーーー�z */ 
			R_Rotate(T); /*  �dーーーーー�z */ 
	}
}

/*  �磧手�Tーーーー逐ー�帖次次次次次次次� */ 
/*  ーーー�瓠手�Tーーー椿綴�b*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  RーーT蔘ーー�eーー/ 
	switch(R->bf)
	{ /*  ー鋳ーーー�s箇ーーーーーーーーー�z */ 
	 case RH: /*  ーーーーーT蔘ーー蔘ーー泙ーー�Mーーー/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  ーーーーーT蔘ーー蔬ーーーーーーーーー/ 
			  Rl=R->lchild; 			/*  RlーーT蔘ーー蔬ーー顆*/ 
			  switch(Rl->bf)
			  { 						/*  ー�Cーーーーーーーー */ 
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
			  R_Rotate(&(*T)->rchild); /*  �d蔘ーー淙ーーーー�z */ 
			  L_Rotate(T); /*  �dーーーーー�z */ 
	}
}

/*  ーーーーー�帖次次�Tーーーーーーー遥ー�弌次次次次主�*/ 
/*  ー��ーーe妾ーーーーーーー�_ーーーーーー�E�iーー */ 
/*  ーーーーーーーーーーーーーtaller�Vーメーーー/
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  ーーーーーーメーーtallerーTRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  ーーーーーーーーー遥ー�弌次次次磁O */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  ーー繍T蔬ーーーーーー吮/ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  �_ーー/ 
				return FALSE;
			if(*taller) /*   ーーーT蔬ーーーーーーーーメー*/ 
				switch((*T)->bf) /*  ー鋳ーー�r*/ 
				{
					case LH: /*  ーーーーーーー衾ー禳ーーーー�z */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  ーーーーーー�蕁次次次次次次酒洽燹次実�*/ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  ーーーー�А次次腫福次次次次而�堆*/  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  ーー繍T蔘ーー瞹ーーー吮/ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  �_ーー/ 
				return FALSE;
			if(*taller) /*  ーーーT蔘ーー�Nーーーーメー*/ 
				switch((*T)->bf) /*  ー鋳ーー�r*/ 
				{
					case LH: /*  ーーーーーーー衾ーーーーーー�蕁�*/ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  ーーーーーー�蕁次次次次次次酒洽燹次実� */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  ーーーー�А次次腫福次次次次次写z */ 
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
	printf("ー爍ー茸茅ーーーー�帖次尺�;
	return 0;
}
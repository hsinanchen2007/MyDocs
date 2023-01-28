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
	int bf; /*  ¡¼¡¼¡¼¡¼¡¼ */ 
	struct BiTNode *lchild, *rchild;	/* ¡¼¡¼¡¼¡¼êú */
} BiTNode, *BiTree;


/* öã¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼¡¼¡¼¡¼äñÁe¡¼¡¼¡¼¡¼¡¼¡¼¡¼èö¡¼¡¼ÄØÄÖÃb*/
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; /*  L¡¼¡¼Pèö¡¼¡¼¡¼¡¼ */ 
	(*P)->lchild=L->rchild; /*  Lèõ¡¼¡¼Â¹¡¼¡¼¡¼¡¼¡¼ */ 
	L->rchild=(*P);
	*P=L; /*  P¡¼¡¼¡¼ÄØÄÖÃb*/ 
}

/* öã¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
/* ¡¼¡¼¡¼¡¼¡¼¡¼äñÁe¡¼¡¼¡¼¡¼¡¼¡¼¡¼èõ¡¼¡¼¸s²Õ¡¼¡¼0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; /*  R¡¼¡¼Pèõ¡¼¡¼Áe¡¼¡¼/ 
	(*P)->rchild=R->lchild; /* Rèö¡¼¡¼àº¡¼¡¼¡¼¡¼¡¼Òä/ 
	R->lchild=(*P);
	*P=R; /*  P¡¼¡¼¡¼ÄØÄÖÃb*/ 
}

#define LH +1 /*  ¡¼ÂÏ*/ 
#define EH 0  /*  ¨é¡¼*/ 
#define RH -1 /*  ¡¼ÂÏ*/ 

/*  öã¡¼êúT¡¼¡¼¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
/*  ¡¼¡¼¡¼ªá¡¼êúT¡¼¡¼¡¼ÄØÄÖÃb*/
void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; /*  L¡¼¡¼Tèö¡¼¡¼¡¼¡¼ */ 
	switch(L->bf)
	{ /*  ¡¼Ãò¡¼¡¼¡¼äê¡¼Ýt¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
		 case LH: /*  ¡¼¡¼¡¼¡¼¡¼Tèö¡¼¡¼èö¡¼¡¼¡¼¡¼¡¼Îa¡¼¡¼- */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH: /*  ¡¼¡¼¡¼¡¼¡¼Tèö¡¼¡¼èõ¡¼¡¼Þ¤¡¼¡¼¡¼¡¼¡¼¡¼/ 
			Lr=L->rchild; /*  Lr¡¼¡¼Tèö¡¼¡¼èõ¡¼¡¼Áe */ 
			switch(Lr->bf)
			{ /*  ¡¼ùC¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
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
			L_Rotate(&(*T)->lchild); /*  Ädèö¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
			R_Rotate(T); /*  Äd¡¼¡¼¡¼¡¼¡¼Ìz */ 
	}
}

/*  öã¡¼êúT¡¼¡¼¡¼¡¼Ãà¡¼Ä¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
/*  ¡¼¡¼¡¼ªá¡¼êúT¡¼¡¼¡¼ÄØÄÖÃb*/ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; /*  R¡¼¡¼Tèõ¡¼¡¼Áe¡¼¡¼/ 
	switch(R->bf)
	{ /*  ¡¼Ãò¡¼¡¼¡¼¸s²Õ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
	 case RH: /*  ¡¼¡¼¡¼¡¼¡¼Tèõ¡¼¡¼èõ¡¼¡¼Þ¤¡¼¡¼®M¡¼¡¼¡¼/ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /*  ¡¼¡¼¡¼¡¼¡¼Tèõ¡¼¡¼èö¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/ 
			  Rl=R->lchild; 			/*  Rl¡¼¡¼Tèõ¡¼¡¼èö¡¼¡¼ðù*/ 
			  switch(Rl->bf)
			  { 						/*  ¡¼ùC¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */ 
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
			  R_Rotate(&(*T)->rchild); /*  Ädèõ¡¼¡¼ÞÊ¡¼¡¼¡¼¡¼Ìz */ 
			  L_Rotate(T); /*  Äd¡¼¡¼¡¼¡¼¡¼Ìz */ 
	}
}

/*  ¡¼¡¼¡¼¡¼¡¼Ä¡¼¡¼¡¼T¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÍÚ¡¼÷Ð¡¼¡¼¡¼¡¼¡¼çï*/ 
/*  ¡¼”÷¡¼¡¼e¾ª¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼¡¼¡¼¡¼êEÝi¡¼¡¼ */ 
/*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼tallerÓV¡¼¥á¡¼¡¼¡¼/
Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)
	{ /*  ¡¼¡¼¡¼¡¼¡¼¡¼¥á¡¼¡¼taller¡¼TRUE */ 
		 *T=(BiTree)malloc(sizeof(BiTNode));
		 (*T)->data=e; (*T)->lchild=(*T)->rchild=NULL; (*T)->bf=EH;
		 *taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)
		{ /*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ÍÚ¡¼÷Ð¡¼¡¼¡¼¡¼§O */ 
			*taller=FALSE; return FALSE;
		}
		if (e<(*T)->data)
		{ /*  ¡¼¡¼½«Tèö¡¼¡¼¡¼¡¼¡¼¡¼Òä/ 
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  £_¡¼¡¼/ 
				return FALSE;
			if(*taller) /*   ¡¼¡¼¡¼Tèö¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¥á¡¼*/ 
				switch((*T)->bf) /*  ¡¼Ãò¡¼¡¼Ýr*/ 
				{
					case LH: /*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼êÐ¡¼ãº¡¼¡¼¡¼¡¼Ìz */ 
							LeftBalance(T);	*taller=FALSE; break;
					case EH: /*  ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼¡¼¡¼¡¼¡¼¡¼¡¼òÞªà¡¼¡¼ÂÏ*/ 
							(*T)->bf=LH; *taller=TRUE; break;
					case RH: /*  ¡¼¡¼¡¼¡¼ô§¡¼¡¼¡¼ðÊ¡¼¡¼¡¼¡¼¡¼©¬ÂÏ*/  
							(*T)->bf=EH; *taller=FALSE; break;
				}
		}
		else
		{ /*  ¡¼¡¼½«Tèõ¡¼¡¼âÙ¡¼¡¼¡¼Òä/ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /*  £_¡¼¡¼/ 
				return FALSE;
			if(*taller) /*  ¡¼¡¼¡¼Tèõ¡¼¡¼¿N¡¼¡¼¡¼¡¼¥á¡¼*/ 
				switch((*T)->bf) /*  ¡¼Ãò¡¼¡¼Ýr*/ 
				{
					case LH: /*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼êÐ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼*/ 
							(*T)->bf=EH; *taller=FALSE;	break;
					case EH: /*  ¡¼¡¼¡¼¡¼¡¼¡¼¨é¡¼¡¼¡¼¡¼¡¼¡¼¡¼òÞªà¡¼¡¼ÂÏ */
							(*T)->bf=RH; *taller=TRUE; break;
					case RH: /*  ¡¼¡¼¡¼¡¼ô§¡¼¡¼¡¼ðÊ¡¼¡¼¡¼¡¼¡¼¡¼Ìz */ 
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
	printf("¡¼à£¡¼Âû³ý¡¼¡¼¡¼¡¼Ä¡¼¡¼Ü­;
	return 0;
}
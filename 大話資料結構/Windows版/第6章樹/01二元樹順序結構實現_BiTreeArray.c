#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */
#define MAX_TREE_SIZE 100 /* êE¡¼èöž´¡¼¡¼ */

typedef int Status;		/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef int TElemType;  /* ¡¼¡¼¡¼¡¼”ã¡¼¡¼†g¡¼¡¼¡¼¡¼ */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0¡¼Ôw¡¼¡¼¡¼¡¼*/

typedef struct
{
	int level,order; /* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼Æl¡¼) */
}Position;

TElemType Nil=0; /*  ¡¼¡¼¡¼¡¼0¡¼‹è*/

Status visit(TElemType c)
{
	printf("%d ",c);
	return OK;
}

/* øe¡¼êE¡¼T¡¼¡¼T¡¼¿öªÞ¡¼¡¼¡¼²æ¡¼¾Z¡¼¡¼& */
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++)
		T[i]=Nil; /* ¡¼á¶‹è*/
	return OK;
}

/* ¡¼¡¼¡¼¡¼¡¼êE¡¼¡¼¡¼¡¼¡¼(¡¼Öí¡¼¡¼¡¼), øe¡¼¡¼¡¼¡¼êE¡¼T */
Status CreateBiTree(SqBiTree T)
{ 
	int i=0;
 	printf("¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼(¡¼¡¼)¡¼¡¼‚â¡¼¡¼¡¼999¡¼¦ç¡¼¡¼¡¼d:\n",MAX_TREE_SIZE);
	while(i<10)
	{
		T[i]=i+1;
		
		if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* ¡¼¡¼(¡¼¡¼£Q¡¼¡¼¡¼¡¼¡¼Ãþ§O/
		{
			printf("¡¼¡¼¡¼¡¼Ä×¡¼ÄÖåsd\n",T[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i]=Nil; /* ¡¼¡¼¡¼è@õÀ¡¼÷Ð¡¼ */
		i++;
	}

	return OK;
}

#define ClearBiTree InitBiTree /* ¡¼¡¼¡¼¡¼¡¼õ¦¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼T¡¼‹þÄ¡¼,¡¼ß_¡¼RUE,õä¡¼LSE */
Status BiTreeEmpty(SqBiTree T)
{ 
	if(T[0]==Nil) /* ¡¼¡¼¡¼‹ô¡¼¡¼‹è*/
		return TRUE;
	else
		return FALSE;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼»üŸJ */
int BiTreeDepth(SqBiTree T)
{ 
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* ¡¼±k ú¡¼¡¼¡¼ */
     if(T[i]!=Nil)
       break;
   i++; 
   do
     j++;
   while(i>=powl(2,j));/* ¡¼¡¼¡¼¡¼¡¼¡¼/
   return j;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶  Ñk¡¼¡¼¡¼eß_¡¼ÄØóÆáµOK;õä¡¼¡¼RROR,e£Q¡¼³ô/
Status Root(SqBiTree T,TElemType *e)
{ 
	if(BiTreeEmpty(T)) /* T‹è*/
		return ERROR;
	else
	{	
		*e=T[0];
		return OK;
	}
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼(¸ü¡¼) */
/* ¡¼Ó\ì¶ ß_¡¼¾Ú£f¡¼e(¡¼¡¼¡¼¡¼÷Ð¡¼ºÊ³ô/
TElemType Value(SqBiTree T,Position e)
{ 
	 return T[(int)powl(2,e.level-1)+e.order-2];
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼(¸ü¡¼) */
/* ¡¼Ó\ì¶ ¿ã¾Ú£f¡¼e(¡¼¡¼¡¼¡¼÷Ð¡¼¡¼¡¼åklue */
Status Assign(SqBiTree T,Position e,TElemType value)
{ 
	int i=(int)powl(2,e.level-1)+e.order-2; /* ¡¼¡¼¡¼¡¼¡¼¡¼’ò¡¼¡¼¡¼*/
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* èAÝ¾¡¼¡¼¡¼ØÛ¡¼¡¼¡¼‹è*/
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  ¸}¡¼¿ú¡¼ØÛ¡¼¡¼¡¼¡¼¡¼¡¼*/
		return ERROR;
	T[i]=value;
	return OK;
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ¡¼e¡¼TÄ×¡¼ÄÖ¤Ð¡¼ß_¡¼¡¼¡¼¡¼,õä¡¼¡¼¡¼¡¼*/
TElemType Parent(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ‹ÒÒä/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ¡¼«Û */
			return T[(i+1)/2-1];
	return Nil; /* u¡¼«Û */
}


/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ß_¡¼èö¡¼¡¼¡¼¡¼¡¼¡¼¡¼,¡¼ß_¡¼¡¼¡¼*/
TElemType LeftChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ‹ÒÒä/
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ¡¼«Û */
			return T[i*2+1];
	return Nil; /* u¡¼«Û */
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ß_¡¼èõ¡¼¡¼¡¼¡¼¡¼¡¼¡¼,¡¼ß_¡¼¡¼¡¼*/
TElemType RightChild(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ‹ÒÒä/
		return Nil;
	for(i=0;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e) /* ¡¼«Û */
			return T[i*2+2];
	return Nil; /* u¡¼«Û */
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ß_¡¼èö¡¼¤g¦We¡¼Tèö¡¼¡¼¡¼¡¼¡¼¦d¡¼ß_¡¼¡¼¡¼*/
TElemType LeftSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ‹ÒÒä/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2==0) /* ¡¼«Û¡¼¡¼¡¼¡¼¡¼¡¼(¡¼¡¼¡¼¡¼ */
			return T[i-1];
	return Nil; /* u¡¼«Û */
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼e¡¼T¡¼¡¼¡¼¡¼ */
/* ¡¼Ó\ì¶ ß_¡¼èõ¡¼¡¼¡¼¦We¡¼Tèõ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ß_¡¼¡¼¡¼*/
TElemType RightSibling(SqBiTree T,TElemType e)
{ 
	int i;
	if(T[0]==Nil) /* ‹ÒÒä/
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if(T[i]==e&&i%2) /* ¡¼«Û¡¼¡¼¡¼¡¼¡¼¡¼(¡¼¡¼¡¼¡¼ */
			return T[i+1];
	return Nil; /* u¡¼«Û */
}

/* PreOrderTraverse()Åqa*/
void PreTraverse(SqBiTree T,int e)
{ 
	visit(T[e]);
	if(T[2*e+1]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		PreTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		PreTraverse(T,2*e+2);
}

/* ¡¼¡¼¡¼ êE¡¼¡¼¡¼*/
/* ¡¼Ó\ì¶ £r¡¼¡¼¡¼¡¼/
Status PreOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ¡¼¡¼¡¼*/
	 PreTraverse(T,0);
	printf("\n");
	return OK;
}

/* InOrderTraverse()Åqa*/
void InTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		InTraverse(T,2*e+1);
	visit(T[e]);
	if(T[2*e+2]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		InTraverse(T,2*e+2);
}

/* ¡¼¡¼¡¼ êE¡¼¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼¡¼¡¼¡¼/
Status InOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ¡¼¡¼¡¼*/
		InTraverse(T,0);
	printf("\n");
	return OK;
}

/* PostOrderTraverse()Åqa*/
void PostTraverse(SqBiTree T,int e)
{ 
	if(T[2*e+1]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		PostTraverse(T,2*e+1);
	if(T[2*e+2]!=Nil) /* ¡¼¡¼¡¼¡¼¡¼*/
		PostTraverse(T,2*e+2);
	visit(T[e]);
}

/* ¡¼¡¼¡¼ êE¡¼T¡¼¡¼*/
/* ¡¼Ó\ì¶ ¡¼¡¼:T¡¼*/
Status PostOrderTraverse(SqBiTree T)
{ 
	if(!BiTreeEmpty(T)) /* ¡¼¡¼¡¼*/
		PostTraverse(T,0);
	printf("\n");
	return OK;
}

/* ¡¼¡¼:êE¡¼ */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAX_TREE_SIZE-1,j;
	while(T[i]==Nil)
		i--; /* ¡¼±k ú¡¼Óæ¡¼¡¼¡¼¾ª¡¼ */
	for(j=0;j<=i;j++)  /* ¡¼ÄÖéP¡¼¡¼¡¼¡¼¡¼¡¼Òä/
		if(T[j]!=Nil)
			visit(T[j]); /* ¡¼¡¼¡¼‹ý¡¼¡¼ */
	printf("\n");
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼êE¡¼ */
void Print(SqBiTree T)
{ 
	int j,k;
	Position p;
	TElemType e;
	for(j=1;j<=BiTreeDepth(T);j++)
	{
		printf("Ã`d¡¼ ",j);
		for(k=1;k<=powl(2,j-1);k++)
		{
			p.level=j;
			p.order=k;
			e=Value(T,p);
			if(e!=Nil)
				printf("%d:%d ",k,e);
		}
		printf("\n");
	}
}


int main()
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("¡¼¡¼¡¼¯Ç,¡¼Œ@¡¼%d(1:¡¼ 0:øû ¡¼»üŸJ=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("êE¡¼ÄØñ\¡¼d\n",e);
	else
		printf("¡¼‹ë¡¼ð÷n");
	printf("¡¼¡¼:êE¡¼:\n");
	LevelOrderTraverse(T);
	printf("¡¼¡¼¡¼¡¼¡¼Æln");
	PreOrderTraverse(T);
	printf("¡¼¡¼¡¼¡¼¡¼Æln");
	InOrderTraverse(T);
	printf("¡¼¡¼:êE¡¼:\n");
	PostOrderTraverse(T);
	printf("¡¼ÛO¡¼Àx¡¼3¡¼¡¼¡¼¡¼);
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("¦õ¡¼¡¼¡¼¾©¡¼¡¼%d¡¼¡¼¡¼¡¼¡¼:50 ",e);
	e=50;
	Assign(T,p,e);
	printf("¡¼¡¼¡¼¡¼¡¼Æln");
	PreOrderTraverse(T);
	printf("¡¼¡¼äî¡¼¡¼%d,¡¼¡¼¡¼¡¼¡¼¡¼",e,Parent(T,e));
	printf("%d,%d,¡¼¡¼¡¼¡¼¡¼¡¼",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("¡¼¡¼Ä¡¼¡¼¡¼Œ@¡¼%d(1:¡¼ 0:øû ¡¼»üŸJ=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("êE¡¼ÄØñ\¡¼d\n",e);
	else
		printf("¡¼‹ë¡¼ð÷n");
	
	return 0;
}


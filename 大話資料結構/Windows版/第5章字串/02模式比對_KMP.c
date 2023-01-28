#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

typedef int Status;		/* Status¡¼¡¼¡¼ ¡¼,¡¼¡¼¡¼¡¼¡¼¡¼¡¼¶Ã¡¼¡¼OK§R*/
typedef int ElemType;	/* ElemType ¡¼ÃÛ¡¼¹ú¡¼¡¼ÁÍ¡¼¡¼¡¼×mint */

typedef char String[MAXSIZE+1]; /*  0¡¼Ôw¡¼¡¼žÅ¡¼¡¼*/

/* ¡¼¡¼¡¼¡¼¡¼É½¡¼harsñë‘x*/
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

Status ClearString(String S)
{ 
	S[0]=0;/*  n¡¼¡¼c */
	return OK;
}

/*  ¡¼¡¼¡¼¡¼T¡¼*/
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  ¡¼¡¼ext¡¼¡¼¡¼¡¼*/
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* ß_¡¼žÅ¡¼¡¼¶V¡¼/
int StrLength(String S)
{ 
	return S[0];
}

/* ¡¼¡¼»õ¡¼¡¼¡¼¸Y*/
int Index(String S, String T, int pos) 
{
	int i = pos;	/* i¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼¤Ð¡¼pos¡¼¡¼¡¼¡¼os£f¡¼¡¼¡¼¡¼ */
	int j = 1;				/* j¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼³ô/
	while (i <= S[0] && j <= T[0]) /* ¡¼i¡¼¡¼SÃ_¡¼¡¼¡¼¡¼¡¼TÃ_¡¼¡¼¡¼¡¼¡¼÷P/
	{
		if (S[i] == T[j]) 	/* }¡¼¡¼¡¼­ç¡¼¡¼ */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
      	{  
         	i = i-j+2;		/* i¡¼¡¼¡¼¡¼®Ì¡¼£fßT¡¼¡¼ */
         	j = 1; 			/* j¡¼¡¼¡¼¡¼äñ¡¼¡¼/
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼‘¯¡¼ext¡¼¡¼¡¼*/
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ¡¼õÍ0]¡¼ž¯TÃ_¡¼ */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* ¡¼¡¼ãl¡¼¡¼¡¼¡¼áµ¡¼ */
  	}
}

/* ß_¡¼¡¼‘l¡¼²ÏS¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0¡¼*/
/*  Tïú¡¼¡¼¡¼os¡¼trLength(S)¡¼*/
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;		/* i¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼¤Ð¡¼pos¡¼¡¼¡¼¡¼os£f¡¼¡¼¡¼¡¼ */
	int j = 1;			/* j¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼³ô/
	int next[255];		/* ¡¼«¦next¡¼¡¼ */
	get_next(T, next);	/* ¡¼‘oºü£a¡¼o¡¼xt¡¼¡¼ */
	while (i <= S[0] && j <= T[0]) /* ¡¼i¡¼¡¼SÃ_¡¼¡¼¡¼¡¼¡¼TÃ_¡¼¡¼¡¼¡¼¡¼÷P/
	{
		if (j==0 || S[i] == T[j]) 	/* }¡¼¡¼¡¼­ç¡¼¡¼¡¼¡¼¡¼¡¼¸ZºvKj=0¡¼Ù]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
      	 	j = next[j];/* j¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ¡¼¡¼¡¼¡¼ï¹ext¡¼¡¼¡¼¡¼¡¼áØ¡¼¡¼nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  /* ¡¼õÍ0]¡¼ž¯TÃ_¡¼ */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]¡¼ ú¡¼ñì±a¡¼Â¸¡¼k]¡¼ýY¡¼ñì±a¡¼ßX*/
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* ¡¼ÌZ¡¼µ²¡¼¡¼¡¼ãl¡¼ */
				nextval[i] = k;	/* ¡¼ÌZ¡¼j¡¼nextval¡¼i£f¡¼ºÊ³ô/
      		else 
				nextval[i] = nextval[k];	/* ¡¼èñ¡¼¡¼¡¼¸g¡¼¡¼¡¼¡¼¡¼¡¼ºø¡¼*/
											/* nextval¡¼»­±`nextval¡¼i£f¡¼ºÊ³ô/
    	} 
		else 
			k= nextval[k];			/* ¡¼¡¼ãl¡¼¡¼¡¼¡¼áµ¡¼ */
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int i = pos;		/* i¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼¤Ð¡¼pos¡¼¡¼¡¼¡¼os£f¡¼¡¼¡¼¡¼ */
	int j = 1;			/* j¡¼¡¼¡¼¡¼¡¼ÌZ£f¡¼¡¼¡¼³ô/
	int next[255];		/* ¡¼«¦next¡¼¡¼ */
	get_nextval(T, next);	/* ¡¼‘oºü£a¡¼o¡¼xt¡¼¡¼ */
	while (i <= S[0] && j <= T[0]) /* ¡¼i¡¼¡¼SÃ_¡¼¡¼¡¼¡¼¡¼TÃ_¡¼¡¼¡¼¡¼¡¼÷P/
	{
		if (j==0 || S[i] == T[j]) 	/* }¡¼¡¼¡¼­ç¡¼¡¼¡¼¡¼¡¼¡¼¸ZºvKj=0¡¼Ù]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼ */
      	 	j = next[j];/* j¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼/
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

int main()
{
	int i,*p;
	String s1,s2;
	
	StrAssign(s1,"abcdex");
	printf("¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next¡¼: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"abcabx");
	printf("¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next¡¼: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"ababaaaba");
	printf("¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next¡¼: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"aaaaaaaab");
	printf("¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next¡¼: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"ababaaaba");
	printf("   ¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   Next¡¼: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextVal¡¼: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"aaaaaaaab");
	printf("   ¡¼¡¼¡¼");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   Next¡¼: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextVal¡¼: ");
	NextPrint(p,StrLength(s1));

	printf("\n");

	StrAssign(s1,"00000000000000000000000000000000000000000000000001");
	printf("¡¼¡¼¡¼");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("¡¼¡¼¡¼");
	StrPrint(s2);
	printf("\n");
	printf("¡¼¡¼¡¼¡¼‘rÃ`d¡¼¡¼¡¼¡¼¡¼®Ì¡¼¡¼¡¼¡¼¡¼¡¼¡¼¿qõH",Index(s1,s2,1));
	printf("¡¼¡¼¡¼¡¼‘rÃ`d¡¼¡¼¡¼¡¼¡¼®Ì¡¼MP¡¼¿q¾gn",Index_KMP(s1,s2,1));
	printf("¡¼¡¼¡¼¡¼‘rÃ`d¡¼¡¼¡¼¡¼¡¼®Ì¡¼MPÓm¡¼¿q¾gn",Index_KMP1(s1,s2,1));

	return 0;
}


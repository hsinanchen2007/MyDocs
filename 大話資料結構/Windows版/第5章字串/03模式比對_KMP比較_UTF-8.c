#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ーーー釦脱ー */

typedef int Status;		/* Statusーーー ー,ーーーーーーー驚ーーOK�R*/
typedef int ElemType;	/* ElemType ー築ー忽ーー鼠ーーー�mint */

typedef char String[MAXSIZE+1]; /*  0ー�wーー�邸次�*/

/* ーーーーー表ーhars驪�x*/
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
	S[0]=0;/*  nーーc */
	return OK;
}

/*  ーーーーTー*/
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  ーーextーーーー*/
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* �_ー�邸次雫Vー/
int StrLength(String S)
{ 
	return S[0];
}

/* ーー歯ーーー�Y*/
int Index(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;	/* iーーーーー�Z�fーーーばーposーーーーos�fーーーー */
	int j = 1;				/* jーーーーー�Z�fーーー株/
	while (i <= S[0] && j <= T[0]) /* ーiーーS�_ーーーーーT�_ーーーーー�P/
	{
		if (S[i] == T[j]) 	/* }ーーー�隋次� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ーーーーーーーーー */
      	{  
         	i = i-j+2;		/* iーーーー�漫治f�Tーー */
         	j = 1; 			/* jーーーー糀ーー/
      	} 
      	
		printf("n=%d i=%d j=%d\n",++n,i,j); 
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ーーーーーー��ーextーーー*/
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ー��0]ー��T�_ー */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* ーー�lーーーー甬ー */
  	}
}

/* �_ーー�lー河Sー�iosーーーーーーーーーーーーーー甼0ー*/
/*  T陏ーーーosーtrLength(S)ー*/
int Index_KMP(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;		/* iーーーーー�Z�fーーーばーposーーーーos�fーーーー */
	int j = 1;			/* jーーーーー�Z�fーーー株/
	int next[255];		/* ー��nextーー */
	get_next(T, next);	/* ー�o匙�aーoーxtーー */
	while (i <= S[0] && j <= T[0]) /* ーiーーS�_ーーーーーT�_ーーーーー�P/
	{
		if (j==0 || S[i] == T[j]) 	/* }ーーー�隋次次次次次叱Z�vKj=0ー�]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ーーーーーーーーー */
      	 	j = next[j];/* jーーーーーーーーーー/
      
	  	printf("n=%d i=%d j=%d\n",++n,i,j);  
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ーーーー鏐extーーーーー痍ーーnextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  /* ー��0]ー��T�_ー */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]ー��ー骭�aー存ーk]ー�Yー骭�aー�X*/
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* ー�Zー飢ーーー�lー */
				nextval[i] = k;	/* ー�Zーjーnextvalーi�fー妻株/
      		else 
				nextval[i] = nextval[k];	/* ー蔡ーーー�gーーーーーー錯ー*/
											/* nextvalー鮫�`nextvalーi�fー妻株/
    	} 
		else 
			k= nextval[k];			/* ーー�lーーーー甬ー */
		
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int n=0;
	int i = pos;		/* iーーーーー�Z�fーーーばーposーーーーos�fーーーー */
	int j = 1;			/* jーーーーー�Z�fーーー株/
	int next[255];		/* ー��nextーー */
	get_nextval(T, next);	/* ー�o匙�aーoーxtーー */
	while (i <= S[0] && j <= T[0]) /* ーiーーS�_ーーーーーT�_ーーーーー�P/
	{
		if (j==0 || S[i] == T[j]) 	/* }ーーー�隋次次次次次叱Z�vKj=0ー�]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ーーーーーーーーー */
      	 	j = next[j];/* jーーーーーーーーーー/
      	
      	printf("n=%d i=%d j=%d\n",++n,i,j);
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
	
	StrAssign(s1,"000000000200000000020000000002000000000200000000020000000001");
	printf("ーーー");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("ーーー");
	StrPrint(s2);
	printf("\n");
	
	printf("\n");
	printf("ーーーー�r�`dーーーーー�漫次次次次次次漆q�H",Index(s1,s2,1));
	printf("ーーーー�r�`dーーーーー�漫�MPー�q�gn",Index_KMP(s1,s2,1));
	printf("ーーーー�r�`dーーーーー�漫�MP�mー�q�gn",Index_KMP1(s1,s2,1));

	return 0;
}

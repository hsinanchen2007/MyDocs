#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* ーーー釦脱ー */

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

/* ーー笛ーo�x*/
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* ーSー���JーーRUE,�筺次�ALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  ーーー ーーーー*/
/*  ー�\豢 ーS>T,ー�_ー��;ーS=T,ー�_ー骨;ーS<T,ー�_ー�z */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* �_ー�邸次雫Vー/
int StrLength(String S)
{ 
	return S[0];
}

/* ーーーーーーーーーーー甼���q/
Status ClearString(String S)
{ 
	S[0]=0;/*  nーーc */
	return OK;
}

/* ーT�_ー1ー2jー�鮠�゜�漫治_ーーー�_ーRUEーーFALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  �_ーー*/
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  ーー2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}

/* ーSub�_ー�Mーーosーーーーーーn蔬ー�� */
Status SubString(String Sub,String S,int pos,int len)
{
	int i;
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	for(i=1;i<=len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}

/* �_ーー�lー河Sー�iosーーーーーーーーーーーーーー甼0ー*/
/* ーー,T陏ー1ーosーtrLength(S)ー*/
int Index(String S, String T, int pos) 
{
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
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}


/*  Tー陏ー�漫次次次漆iosーーーーーーTー撲ーー�� */
/*  ー�_ーーーーー蔬ー�rSー厚ーーー�_ー */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* 侍ーー�_ー */
		m = StrLength(T);	/* 侍ーー�_ー */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* ーーーーー�`ーーーーー蔬ー�]sub */
			if (StrCompare(sub,T) != 0)    /* ーーーーー */
				++i;
			else 				/* ーーーー�R*/
				return i;		/* ー�_ーー */
		}
	}
	return 0;	/* ー�Qーーーーー甬0 */
}


/*  ーーー ーーーー1ーosーtrLength(S)+1 */
/*  ー�\豢 ーー骭ーosーーーーーーTーーーーーRUE,ーー�O�_ーALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  ーーーー/
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  ーー�O */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

/*  ーーー ーーー1ーosーtrLength(S)-len+1 */
/*  ー�\豢 ー�蹇��\�iosーーーーーーn蔬ー�q/
Status StrDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1||pos>S[0]-len+1||len<0)
		return ERROR;
	for(i=pos+len;i<=S[0];i++)
		S[i-len]=S[i];
	S[0]-=len;
	return OK;
}

/*  ーーー ー,TーーーTー陏ー�粥��后次次赦�ー�]�Y寵�O/
/*  ー�\豢 ーVーー河Sーーーー�RーTー撲ーー�xーー�q/
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  ー�Mーーーー禾ーーー */
	if(StrEmpty(T)) /*  Tー���q/
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  ーーーーーーーーーーーー厚ー */
		if(i) /*  ーーーー�x*/
		{
			StrDelete(S,i,StrLength(T)); /*  ーーo�x*/
			StrInsert(S,i,V); /*  ーーー厚ーーーV */
			i+=StrLength(V); /*  ーーーーー垰ーーー�x*/
		}
	}while(i);
	return OK;
}

/*  ーーーーT */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}


int main()
{
	
	int i,j;
	Status k;
	char s;
	String t,s1,s2;
	printf("ーーーー1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("ーー齷AXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("ーー%d ーーー%d(1:ー 0:��\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("ーーーーー��: ");
	StrPrint(s2);
	printf("ーーーー2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("ーー齷AXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("ー1%cー2\n",s);
	k=Concat(t,s1,s2);
	printf("ー1jー�Q侍ーーー: ");
	StrPrint(t);
	if(k==FALSE)
		printf("ーーーーn");
	ClearString(s1);
	printf("ーー����,ー1ー: ");
	StrPrint(s1);
	printf("ーー%d ーーー%d(1:ー 0:��\n",StrLength(s1),StrEmpty(s1));
	printf("ーー蔬ー��ーーーーーー�fー,ーーー: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("ーー2ー: ");
		StrPrint(s2);
	}
	printf("ー�供次�osーーー,ーーenーーーーーーpos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("ーーーーー: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("ーー2骭ーdーーーーーーtーー2ー:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2骭ーdーー褌ー賜ーーー\n",i);
	SubString(t,s2,1,1);
	printf("ーーー);
	StrPrint(t);
	Concat(s1,t,t);
	printf("ー1ーー);
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("ーー1ー���Qーー�nー�xー�xー��,ー2ー: ");
	StrPrint(s2);


	return 0;
}


#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* ¡¼¡¼¡¼ËÕÃ¦¡¼ */

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

/* ¡¼¡¼Å«¡¼o‘x*/
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* ¡¼S¡¼‹ü›J¡¼¡¼RUE,õä¡¼¡¼ALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  ¡¼¡¼¡¼ ¡¼¡¼¡¼¡¼*/
/*  ¡¼Ó\ì¶ ¡¼S>T,¡¼ß_¡¼©º;¡¼S=T,¡¼ß_¡¼¹ü;¡¼S<T,¡¼ß_¡¼Ñz */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* ß_¡¼žÅ¡¼¡¼¶V¡¼/
int StrLength(String S)
{ 
	return S[0];
}

/* ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶‹ü–q/
Status ClearString(String S)
{ 
	S[0]=0;/*  n¡¼¡¼c */
	return OK;
}

/* ¡¼Tß_¡¼1¡¼2j¡¼«ò¾ª¡¬–Ì¡¼£_¡¼¡¼¡¼ß_¡¼RUE¡¼¡¼FALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  £_¡¼¡¼*/
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  ¡¼¡¼2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}

/* ¡¼Subß_¡¼‘M¡¼¡¼os¡¼¡¼¡¼¡¼¡¼¡¼nèö¡¼–Ì */
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

/* ß_¡¼¡¼‘l¡¼²ÏS¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼á¶0¡¼*/
/* ¡¼¡¼,Tïú¡¼1¡¼os¡¼trLength(S)¡¼*/
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


/*  T¡¼ïú¡¼–Ì¡¼¡¼¡¼¡¼¿ios¡¼¡¼¡¼¡¼¡¼¡¼T¡¼ËÐ¡¼¡¼—¸ */
/*  ¡¼ß_¡¼¡¼¡¼¡¼¡¼èö¡¼‘rS¡¼¸ü¡¼¡¼¡¼ß_¡¼ */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* »ø¡¼¡¼Ã_¡¼ */
		m = StrLength(T);	/* »ø¡¼¡¼Ã_¡¼ */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* ¡¼¡¼¡¼¡¼¡¼à`¡¼¡¼¡¼¡¼¡¼èö¡¼ ]sub */
			if (StrCompare(sub,T) != 0)    /* ¡¼¡¼¡¼¡¼¡¼ */
				++i;
			else 				/* ¡¼¡¼¡¼¡¼§R*/
				return i;		/* ¡¼ß_¡¼¡¼ */
		}
	}
	return 0;	/* ¡¼£Q¡¼¡¼¡¼¡¼¡¼áµ0 */
}


/*  ¡¼¡¼¡¼ ¡¼¡¼¡¼¡¼1¡¼os¡¼trLength(S)+1 */
/*  ¡¼Ó\ì¶ ¡¼¡¼ñì¡¼os¡¼¡¼¡¼¡¼¡¼¡¼T¡¼¡¼¡¼¡¼¡¼RUE,¡¼¡¼§Oß_¡¼ALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  ¡¼¡¼¡¼¡¼/
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  ¡¼¡¼§O */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

/*  ¡¼¡¼¡¼ ¡¼¡¼¡¼1¡¼os¡¼trLength(S)-len+1 */
/*  ¡¼Ó\ì¶ ¡¼í¡¼ž\¿ios¡¼¡¼¡¼¡¼¡¼¡¼nèö¡¼–q/
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

/*  ¡¼¡¼¡¼ ¡¼,T¡¼¡¼¡¼T¡¼ïú¡¼—´¡¼‡¹¡¼¡¼¡¼Ï«¡¼ñ]ÊYÃþ§O/
/*  ¡¼Ó\ì¶ ¡¼V¡¼¡¼²ÏS¡¼¡¼¡¼¡¼¾R¡¼T¡¼ËÐ¡¼¡¼¼x¡¼¡¼–q/
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  ¡¼‘M¡¼¡¼¡¼¡¼²Ó¡¼¡¼¡¼ */
	if(StrEmpty(T)) /*  T¡¼‹ü–q/
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  ¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¡¼¸ü¡¼ */
		if(i) /*  ¡¼¡¼¡¼¡¼‘x*/
		{
			StrDelete(S,i,StrLength(T)); /*  ¡¼¡¼o‘x*/
			StrInsert(S,i,V); /*  ¡¼¡¼¡¼¸ü¡¼¡¼¡¼V */
			i+=StrLength(V); /*  ¡¼¡¼¡¼¡¼¡¼Ô»¡¼¡¼¡¼‘x*/
		}
	}while(i);
	return OK;
}

/*  ¡¼¡¼¡¼¡¼T */
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
	printf("¡¼¡¼¡¼¡¼1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("¡¼¡¼óùAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("¡¼¡¼%d ¡¼¡¼¡¼%d(1:¡¼ 0:øû\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("¡¼¡¼¡¼¡¼¡¼Žû: ");
	StrPrint(s2);
	printf("¡¼¡¼¡¼¡¼2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("¡¼¡¼óùAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("¡¼1%c¡¼2\n",s);
	k=Concat(t,s1,s2);
	printf("¡¼1j¡¼žQ»ø¡¼¡¼¡¼: ");
	StrPrint(t);
	if(k==FALSE)
		printf("¡¼¡¼¡¼¡¼n");
	ClearString(s1);
	printf("¡¼¡¼‹ü ú,¡¼1¡¼: ");
	StrPrint(s1);
	printf("¡¼¡¼%d ¡¼¡¼¡¼%d(1:¡¼ 0:øû\n",StrLength(s1),StrEmpty(s1));
	printf("¡¼¡¼èö¡¼šü¡¼¡¼¡¼¡¼¡¼¡¼£f¡¼,¡¼¡¼¡¼: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("¡¼¡¼2¡¼: ");
		StrPrint(s2);
	}
	printf("¡¼ž¶¡¼¡¼os¡¼¡¼¡¼,¡¼¡¼en¡¼¡¼¡¼¡¼¡¼¡¼pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("¡¼¡¼¡¼¡¼¡¼: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("¡¼¡¼2ñì¡¼d¡¼¡¼¡¼¡¼¡¼¡¼t¡¼¡¼2¡¼:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2ñì¡¼d¡¼¡¼êî¡¼»ò¡¼¡¼¡¼\n",i);
	SubString(t,s2,1,1);
	printf("¡¼¡¼¡¼);
	StrPrint(t);
	Concat(s1,t,t);
	printf("¡¼1¡¼¡¼);
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("¡¼¡¼1¡¼­¸žQ¡¼¡¼žn¡¼Àx¡¼¼x¡¼ ú,¡¼2¡¼: ");
	StrPrint(s2);


	return 0;
}


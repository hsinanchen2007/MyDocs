#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* ��������æ�� */

typedef int Status;		/* Status������ ��,���������������á���OK�R*/
typedef int ElemType;	/* ElemType ���ۡ��������͡������mint */

typedef char String[MAXSIZE+1]; /*  0���w�����š���*/

/* ����������ɽ��hars��x*/
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
	S[0]=0;/*  n����c */
	return OK;
}

/*  ��������T��*/
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  ����ext��������*/
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* �_���š����V��/
int StrLength(String S)
{ 
	return S[0];
}

/* �������������Y*/
int Index(String S, String T, int pos) 
{
	int i = pos;	/* i�����������Z�f�������С�pos��������os�f�������� */
	int j = 1;				/* j�����������Z�f��������/
	while (i <= S[0] && j <= T[0]) /* ��i����S�_����������T�_�����������P/
	{
		if (S[i] == T[j]) 	/* }�������硼�� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ������������������ */
      	{  
         	i = i-j+2;		/* i���������̡��f�T���� */
         	j = 1; 			/* j���������񡼡�/
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ����������������ext������*/
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* ����0]����T�_�� */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* �����l��������ᵡ� */
  	}
}

/* �_�����l����S���ios�����������������������������0��*/
/*  T��������os��trLength(S)��*/
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;		/* i�����������Z�f�������С�pos��������os�f�������� */
	int j = 1;			/* j�����������Z�f��������/
	int next[255];		/* ����next���� */
	get_next(T, next);	/* ���o���a��o��xt���� */
	while (i <= S[0] && j <= T[0]) /* ��i����S�_����������T�_�����������P/
	{
		if (j==0 || S[i] == T[j]) 	/* }�������硼�����������Z�vKj=0���]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ������������������ */
      	 	j = next[j];/* j��������������������/
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ���������ext�����������ء���nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  /* ����0]����T�_�� */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��������a��¸��k]���Y����a���X*/
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* ���Z�����������l�� */
				nextval[i] = k;	/* ���Z��j��nextval��i�f���ʳ�/
      		else 
				nextval[i] = nextval[k];	/* ���񡼡����g����������������*/
											/* nextval�����`nextval��i�f���ʳ�/
    	} 
		else 
			k= nextval[k];			/* �����l��������ᵡ� */
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int i = pos;		/* i�����������Z�f�������С�pos��������os�f�������� */
	int j = 1;			/* j�����������Z�f��������/
	int next[255];		/* ����next���� */
	get_nextval(T, next);	/* ���o���a��o��xt���� */
	while (i <= S[0] && j <= T[0]) /* ��i����S�_����������T�_�����������P/
	{
		if (j==0 || S[i] == T[j]) 	/* }�������硼�����������Z�vKj=0���]*/
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ������������������ */
      	 	j = next[j];/* j��������������������/
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
	printf("������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next��: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"abcabx");
	printf("������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next��: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"ababaaaba");
	printf("������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next��: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"aaaaaaaab");
	printf("������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("Next��: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"ababaaaba");
	printf("   ������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   Next��: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextVal��: ");
	NextPrint(p,StrLength(s1));
	printf("\n");

	StrAssign(s1,"aaaaaaaab");
	printf("   ������");
	StrPrint(s1);
	i=StrLength(s1);
	p=(int*)malloc((i+1)*sizeof(int));
	get_next(s1,p); 
	printf("   Next��: ");
	NextPrint(p,StrLength(s1));
	get_nextval(s1,p); 
	printf("NextVal��: ");
	NextPrint(p,StrLength(s1));

	printf("\n");

	StrAssign(s1,"00000000000000000000000000000000000000000000000001");
	printf("������");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("������");
	StrPrint(s2);
	printf("\n");
	printf("���������r�`d�����������̡��������������q�H",Index(s1,s2,1));
	printf("���������r�`d�����������̡�MP���q�gn",Index_KMP(s1,s2,1));
	printf("���������r�`d�����������̡�MP�m���q�gn",Index_KMP1(s1,s2,1));

	return 0;
}


#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* ��������æ�� */

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

/* ����ū��o�x*/
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* ��S�����J����RUE,�䡼��ALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  ������ ��������*/
/*  ���\� ��S>T,���_����;��S=T,���_����;��S<T,���_���z */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* �_���š����V��/
int StrLength(String S)
{ 
	return S[0];
}

/* ����������������������ᶋ��q/
Status ClearString(String S)
{ 
	S[0]=0;/*  n����c */
	return OK;
}

/* ��T�_��1��2j���򾪡��̡��_�������_��RUE����FALSE */
Status Concat(String T,String S1,String S2)
{
	int i;
	if(S1[0]+S2[0]<=MAXSIZE)
	{ /*  �_����*/
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=S2[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  ����2 */
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
		return FALSE;
	}
}

/* ��Sub�_���M����os������������n������ */
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

/* �_�����l����S���ios�����������������������������0��*/
/* ����,T����1��os��trLength(S)��*/
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


/*  T�������̡��������ios������������T���С����� */
/*  ���_���������������rS�����������_�� */
int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* �������_�� */
		m = StrLength(T);	/* �������_�� */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* �����������`���������������]sub */
			if (StrCompare(sub,T) != 0)    /* ���������� */
				++i;
			else 				/* ���������R*/
				return i;		/* ���_���� */
		}
	}
	return 0;	/* ���Q�����������0 */
}


/*  ������ ��������1��os��trLength(S)+1 */
/*  ���\� �����졼os������������T����������RUE,�����O�_��ALSE */
Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  ��������/
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  �����O */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

/*  ������ ������1��os��trLength(S)-len+1 */
/*  ���\� �����\�ios������������n�����q/
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

/*  ������ ��,T������T������������������ϫ���]�Y���O/
/*  ���\� ��V������S���������R��T���С����x�����q/
Status Replace(String S,String T,String V)
{ 
	int i=1; /*  ���M���������ӡ����� */
	if(StrEmpty(T)) /*  T�����q/
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  ���������������������������� */
		if(i) /*  ���������x*/
		{
			StrDelete(S,i,StrLength(T)); /*  ����o�x*/
			StrInsert(S,i,V); /*  ��������������V */
			i+=StrLength(V); /*  ����������Ի�������x*/
		}
	}while(i);
	return OK;
}

/*  ��������T */
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
	printf("��������1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("������AXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("����%d ������%d(1:�� 0:��\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("������������: ");
	StrPrint(s2);
	printf("��������2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("������AXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("��1%c��2\n",s);
	k=Concat(t,s1,s2);
	printf("��1j���Q��������: ");
	StrPrint(t);
	if(k==FALSE)
		printf("��������n");
	ClearString(s1);
	printf("��������,��1��: ");
	StrPrint(s1);
	printf("����%d ������%d(1:�� 0:��\n",StrLength(s1),StrEmpty(s1));
	printf("�����������������������f��,������: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("����2��: ");
		StrPrint(s2);
	}
	printf("��������os������,����en������������pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("����������: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("����2�졼d������������t����2��:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2�졼d������򡼡���\n",i);
	SubString(t,s2,1,1);
	printf("������);
	StrPrint(t);
	Concat(s1,t,t);
	printf("��1����);
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("����1�����Q�����n���x���x����,��2��: ");
	StrPrint(s2);


	return 0;
}

